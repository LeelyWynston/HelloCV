#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "===天杀的轻蜂加速器我要退钱 ===" << endl;
    cout << "===退钱！退钱！退钱！！！！ ===" << endl;
    cout << endl;
    
    // 爱心方程: (x² + y² - 1)³ - x²y³ < 0
    for (double y = 1.5; y >= -1.5; y -= 0.1) {
        for (double x = -1.5; x <= 1.5; x += 0.05) {
            double a = x * x + y * y - 1;
            double b = a * a * a - x * x * y * y * y;
            
            if (b < 0.0) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    
    cout << endl;
    cout <<" 有病吧，一个连全局代理都做不到的玩意还要我39！！" << endl;
    
    return 0;
}
