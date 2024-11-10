//
// Created by lenovo on 2024/11/10.
//

#ifndef DS2024A_HUFFCODE_H
#define DS2024A_HUFFCODE_H

#endif //DS2024A_HUFFCODE_H
#ifndef HUFFCODE_H
#define HUFFCODE_H

#include "Bitmap.h"
#include <string>
#include <unordered_map>

class HuffCode {
private:
    Bitmap bitmap;
    std::string binaryString;

public:
    HuffCode(const std::unordered_map<char, std::string>& codes, const std::string& text) {
        for (char ch : text) {
            binaryString += codes.at(ch);
        }
        for (size_t i = 0; i < binaryString.size(); ++i) {
            if (binaryString[i] == '1') bitmap.set(i);
        }
    }

    std::string getBinaryString() const { return binaryString; }
};

#endif // HUFFCODE_H
