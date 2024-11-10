#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>

class BinNode {
public:
    char data;
    int weight;           // 权重，用于构建 Huffman 树
    BinNode* left;
    BinNode* right;

    BinNode(char d, int w) : data(d), weight(w), left(nullptr), right(nullptr) {}
};

class BinTree {
public:
    BinNode* root;

    BinTree() : root(nullptr) {}
    virtual ~BinTree() { destroy(root); }

    void destroy(BinNode* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }
};

#endif // BINTREE_H
