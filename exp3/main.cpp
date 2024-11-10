#include "HuffTree.h"
#include "HuffCode.h"
#include <iostream>
#include <unordered_map>

int main() {
    std::string text = "i have a dream";  // 示例文本

    // 统计字母频率（不区分大小写）
    std::unordered_map<char, int> freq;
    for (char ch : text) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            freq[ch]++;
        }
    }

    // 构建 Huffman 树并生成编码
    HuffTree huffTree;
    huffTree.buildTree(freq);
    const auto& codes = huffTree.getCodes();

    // 打印每个字符的编码
    std::cout << "Huffman Codes:\n";
    for (const auto& [ch, code] : codes) {
        std::cout << ch << ": " << code << "\n";
    }

    // 对示例文本编码
    HuffCode huffCode(codes, "dream");
    std::cout << "\nEncoded 'dream' as binary string: " << huffCode.getBinaryString() << "\n";

    return 0;
}
//
// Created by lenovo on 2024/11/10.
//
