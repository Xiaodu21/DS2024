#include "HuffCode.h"

int main() {
    std::string filename = "E:\\DS2024A\\exp3\\I_have_a_dream.txt";  // 假设你保存了文章的原文为此文件
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error: Cannot open the file " << filename << std::endl;
        return 1;  // 退出程序
    }

    HuffmanCoding huffman(filename);  // 根据文件创建HuffmanCoding对象
    huffman.encode();  // 执行哈夫曼编码

    // 输出所有字母的编码
    std::cout << "Huffman Codes for 26 Letters: " << std::endl;
    huffman.printLetterCodes();

    // 输出单词 "dream" 的哈夫曼编码
    std::string word = "dream";
    std::cout << "Huffman encoding for word '" << word << "': " << huffman.getCode(word) << std::endl;

    return 0;
}
