#ifndef HUFFTREE_H
#define HUFFTREE_H

#include "Bintree.h"
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>

class HuffTree {
public:
    BinTreeNode* root;

    // 构造函数，生成哈夫曼树
    HuffTree(std::unordered_map<char, int>& frequencies) {
        auto cmp = [](BinTreeNode* a, BinTreeNode* b) { return a->freq > b->freq; };
        std::priority_queue<BinTreeNode*, std::vector<BinTreeNode*>, decltype(cmp)> pq(cmp);

        for (auto& pair : frequencies) {
            pq.push(new BinTreeNode(pair.first, pair.second));
        }

        while (pq.size() > 1) {
            BinTreeNode* left = pq.top(); pq.pop();
            BinTreeNode* right = pq.top(); pq.pop();
            BinTreeNode* node = new BinTreeNode('\0', left->freq + right->freq);
            node->left = left;
            node->right = right;
            pq.push(node);
        }
        root = pq.top();
    }

    // 递归生成编码
    void generateCodes(BinTreeNode* node, std::string code, std::unordered_map<char, std::string>& huffCode) {
        if (!node) return;
        if (!node->left && !node->right) huffCode[node->ch] = code;
        generateCodes(node->left, code + "0", huffCode);
        generateCodes(node->right, code + "1", huffCode);
    }
};

#endif
