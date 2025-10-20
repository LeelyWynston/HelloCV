#ifndef MENU_H
#define MENU_H

#include <string>

class Menu {
private:
    void showMainMenu();
    void handleTextEncryption();
    void handleTextDecryption(); 
    void handleFileEncryption();
    void handleFileDecryption();
    
public:
    void run();  // 启动菜单系统
};

#endif
