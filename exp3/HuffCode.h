#ifndef HUFFMANCODING_H
#define HUFFMANCODING_H

#include "HuffTree.h"
#include <string>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>

class HuffmanCoding {
public:
    std::unordered_map<char, int> frequencies;
    std::unordered_map<char, std::string> huffCode;

    // 构造函数，根据文本频率统计
    HuffmanCoding(const std::string& filename) {
        std::ifstream file(filename);
        std::stringstream buffer;
        buffer << file.rdbuf();  // 读取文件内容

        std::string text = buffer.str();
        for (char ch : text) {
            if (isalpha(ch)) frequencies[tolower(ch)]++; // 统计字符频率
        }
    }

    // 执行哈夫曼编码
    void encode() {
        HuffTree huffTree(frequencies);  // 根据字符频率构造哈夫曼树
        huffTree.generateCodes(huffTree.root, "", huffCode);  // 生成编码
    }

    // 获取单词的哈夫曼编码
    std::string getCode(const std::string& word) {
        std::string encoded = "";
        for (char ch : word) {
            encoded += huffCode[tolower(ch)] + " ";  // 每个编码之间加空格
        }
        return encoded;
    }

    // 输出26个字母的哈夫曼编码
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

    // 输出所有的哈夫曼编码
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
