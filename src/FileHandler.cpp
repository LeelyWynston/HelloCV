#include "FileHandler.h"
#include <fstream>
#include <iostream>

std::string FileHandler::readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("无法打开文件: " + filename);
    }
    
    std::string content((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());
    file.close();
    return content;
}

bool FileHandler::writeFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "错误：无法创建文件 " << filename << std::endl;
        return false;
    }
    
    file << content;
    file.close();
    return true;
}

bool FileHandler::fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}
