#include "Crypto.h"
#include <string>

std::string Crypto::caesarEncrypt(const std::string& text, int key) {
    std::string result = text;
    for (char& c : result) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + key) % 26 + base;
        }
    }
    return result;
}

std::string Crypto::caesarDecrypt(const std::string& text, int key) {
    return caesarEncrypt(text, 26 - (key % 26));
}
