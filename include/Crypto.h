#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>

class Crypto {
public:
    static std::string caesarEncrypt(const std::string& text, int key);
    static std::string caesarDecrypt(const std::string& text, int key);
};

#endif
