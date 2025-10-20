#include "Menu.h"
#include "Crypto.h"
#include "FileHandler.h"
#include <iostream>
#include <limits>

void Menu::run() {
    while (true) {
        showMainMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choice) {
            case 1:
                handleTextEncryption();
                break;
            case 2:
                handleTextDecryption();
                break;
            case 3:
                handleFileEncryption();
                break;
            case 4:
                handleFileDecryption();
                break;
            case 0:
                std::cout << "感谢使用加密工具，再见！" << std::endl;
                return;
            default:
                std::cout << "无效选择，请重新输入！" << std::endl;
        }
        
        std::cout << "\n按回车键继续...";
        std::cin.get();
    }
}

void Menu::showMainMenu() {
    std::cout << "\n=== 文本加密解密工具 ===" << std::endl;
    std::cout << "1. 文本加密" << std::endl;
    std::cout << "2. 文本解密" << std::endl;
    std::cout << "3. 文件加密" << std::endl;
    std::cout << "4. 文件解密" << std::endl;
    std::cout << "0. 退出" << std::endl;
    std::cout << "请选择功能: ";
}

void Menu::handleTextEncryption() {
    std::cout << "\n--- 文本加密 ---" << std::endl;
    
    std::string text;
    std::cout << "请输入要加密的文本: ";
    std::getline(std::cin, text);
    
    int key;
    std::cout << "请输入密钥（整数）: ";
    std::cin >> key;
    
    std::string encryptedText = Crypto::caesarEncrypt(text, key);
    std::cout << "加密结果: " << encryptedText << std::endl;
}

void Menu::handleTextDecryption() {
    std::cout << "\n--- 文本解密 ---" << std::endl;
    
    std::string text;
    std::cout << "请输入要解密的文本: ";
    std::getline(std::cin, text);
    
    int key;
    std::cout << "请输入密钥（整数）: ";
    std::cin >> key;
    
    std::string decryptedText = Crypto::caesarDecrypt(text, key);
    std::cout << "解密结果: " << decryptedText << std::endl;
}

void Menu::handleFileEncryption() {
    std::cout << "\n--- 文件加密 ---" << std::endl;
    
    std::string inputFile, outputFile;
    std::cout << "请输入输入文件名: ";
    std::cin >> inputFile;
    std::cout << "请输入输出文件名: ";
    std::cin >> outputFile;
    
    if (!FileHandler::fileExists(inputFile)) {
        std::cout << "输入文件不存在！" << std::endl;
        return;
    }
    
    int key;
    std::cout << "请输入密钥（整数）: ";
    std::cin >> key;
    
    try {
        std::string content = FileHandler::readFile(inputFile);
        std::string encryptedContent = Crypto::caesarEncrypt(content, key);
        
        if (FileHandler::writeFile(outputFile, encryptedContent)) {
            std::cout << "文件加密成功！结果保存在: " << outputFile << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cout << "错误: " << e.what() << std::endl;
    }
}

void Menu::handleFileDecryption() {
    std::cout << "\n--- 文件解密 ---" << std::endl;
    
    std::string inputFile, outputFile;
    std::cout << "请输入输入文件名: ";
    std::cin >> inputFile;
    std::cout << "请输入输出文件名: ";
    std::cin >> outputFile;
    
    if (!FileHandler::fileExists(inputFile)) {
        std::cout << "输入文件不存在！" << std::endl;
        return;
    }
    
    int key;
    std::cout << "请输入密钥（整数）: ";
    std::cin >> key;
    
    try {
        std::string content = FileHandler::readFile(inputFile);
        std::string decryptedContent = Crypto::caesarDecrypt(content, key);
        
        if (FileHandler::writeFile(outputFile, decryptedContent)) {
            std::cout << "文件解密成功！结果保存在: " << outputFile << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cout << "错误: " << e.what() << std::endl;
    }
}
