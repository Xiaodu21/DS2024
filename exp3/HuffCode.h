#ifndef HUFFMANCODING_H
#define HUFFMANCODING_H

#include "HuffTree.h"
#include <string>
#include <unordered_map>
#include <iostream>

class HuffmanCoding {
public:
    std::unordered_map<char, int> frequencies;
    std::unordered_map<char, std::string> huffCode;

    // 构造函数，根据文本频率统计
    HuffmanCoding(const std::string& text) {
        for (char ch : text) {
            if (isalpha(ch)) frequencies[tolower(ch)]++;
        }
    }

    // 对文本进行哈夫曼编码
    void encode() {
        HuffTree huffTree(frequencies);
        huffTree.generateCodes(huffTree.root, "", huffCode);
    }

    // 获取单词的哈夫曼编码
    std::string getCode(const std::string& word) {
        std::string encoded = "";
        for (char ch : word) {
            encoded += huffCode[tolower(ch)] + " ";  // 每个编码之间加空格
        }
        return encoded;
    }

    // 输出26个字母的编码
    void printLetterCodes() {
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (huffCode.find(ch) != huffCode.end()) {
                std::cout << ch << ": ";
                for (char bit : huffCode[ch]) {
                    std::cout << bit << " ";  // 输出编码时在每个 bit 之间添加空格
                }
                std::cout << std::endl;
            }
        }
    }

    // 输出哈夫曼编码
    void printCodes() {
        for (auto& pair : huffCode) {
            std::cout << pair.first << ": ";
            for (char bit : pair.second) {
                std::cout << bit << " ";  // 输出编码时在每个 bit 之间添加空格
            }
            std::cout << std::endl;
        }
    }
};

#endif
