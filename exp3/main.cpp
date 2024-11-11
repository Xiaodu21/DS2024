#include "HuffCode.h"
#include <iostream>
#include <string>

int main() {
    // 需要编码的文本（你可以根据需要选择其他文本）
    std::string text = "I have a dream that one day this nation will rise up and live out the true meaning of its creed.";

    // 创建 HuffmanCoding 对象并对文本进行编码
    HuffmanCoding huffman(text);
    huffman.encode();

    // 输出所有26个字母的哈夫曼编码
    std::cout << "Huffman Codes for 26 letters:" << std::endl;
    huffman.printLetterCodes();

    std::cout << "\nEncoding 'dream':" << std::endl;
    std::string word = "dream";
    std::string encodedWord = huffman.getCode(word);
    std::cout << "dream: " << encodedWord << " " << std::endl;

    return 0;
}
