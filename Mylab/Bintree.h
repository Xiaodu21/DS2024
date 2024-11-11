#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>

struct BinTreeNode {
    char ch;
    int freq;
    BinTreeNode* left;
    BinTreeNode* right;
    BinTreeNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

#endif // BINTREE_H
