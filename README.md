# 文本加密解密工具一个使用 C++ 和 CMake 构建的简易加密解密工具。

## 功能特性

- ✅ 文本加密/解密
- ✅ 文件加密/解密  
- ✅ 凯撒密码算法
- ✅ 命令行交互界面

## 项目结构
CryptoTool/
├── CMakeLists.txt
├── include/
│ ├── Crypto.h
│ ├── FileHandler.h
│ └── Menu.h
├── src/
│ ├── Crypto.cpp
│ ├── FileHandler.cpp
│ ├── Menu.cpp
│ └── main.cpp
└── README.md

text

## 构建说明

```bash
mkdir build && cd build
cmake ..
make
./CryptoTool
使用方法
运行程序后选择功能：

1: 文本加密

2: 文本解密

3: 文件加密

4: 文件解密

0: 退出
