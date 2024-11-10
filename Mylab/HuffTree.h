//
// Created by lenovo on 2024/11/10.
//

#ifndef DS2024A_HUFFTREE_H
#define DS2024A_HUFFTREE_H

#endif //DS2024A_HUFFTREE_H

#ifndef HUFFTREE_H
#define HUFFTREE_H

#include "BinTree.h"
#include <unordered_map>
#include <queue>
#include <string>

class HuffTree : public BinTree {
private:
    std::unordered_map<char, std::string> codes;

    void generateCode(BinNode* node, const std::string& code) {
        if (!node) return;
        if (!node->left && !node->right)  // 叶节点
            codes[node->data] = code;
        generateCode(node->left, code + "0");
        generateCode(node->right, code + "1");
    }

public:
    void buildTree(const std::unordered_map<char, int>& freq) {
        auto cmp = [](BinNode* a, BinNode* b) { return a->weight > b->weight; };
        std::priority_queue<BinNode*, std::vector<BinNode*>, decltype(cmp)> pq(cmp);

        for (const auto& [ch, w] : freq)
            pq.push(new BinNode(ch, w));

        while (pq.size() > 1) {
            BinNode* left = pq.top(); pq.pop();
            BinNode* right = pq.top(); pq.pop();
            BinNode* parent = new BinNode('\0', left->weight + right->weight);
            parent->left = left;
            parent->right = right;
            pq.push(parent);
        }
        root = pq.top();
        generateCode(root, "");
    }

    const std::unordered_map<char, std::string>& getCodes() const { return codes; }
};

#endif // HUFFTREE_H

