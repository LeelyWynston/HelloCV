#include <opencv2/opencv.hpp>
#include <cmath>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
    cout << "🐳 在Docker容器中生成图形化爱心..." << endl;
    
    const int width = 800;
    const int height = 600;
    Mat image = Mat::zeros(height, width, CV_8UC3);
    
    // 设置背景色（浅粉色）
    image.setTo(Scalar(255, 240, 245));
    
    Point center(width/2, height/2 - 50);
    int scale = 15;
    
    // 绘制爱心轮廓
    vector<Point> heart_points;
    for (double t = 0; t <= 2 * M_PI; t += 0.01) {
        // 心形参数方程
        double x = 16 * pow(sin(t), 3);
        double y = 13 * cos(t) - 5 * cos(2*t) - 2 * cos(3*t) - cos(4*t);
        
        int pixelX = center.x + scale * x;
        int pixelY = center.y - scale * y;
        
        heart_points.push_back(Point(pixelX, pixelY));
    }
    
    // 填充爱心（红色）
    vector<vector<Point>> contours = {heart_points};
    fillPoly(image, contours, Scalar(0, 0, 255));
    
    // 添加文字
    putText(image, "我可怜的39块啊我很想你", Point(150, 50), 
            FONT_HERSHEY_SIMPLEX, 1.2, Scalar(0, 0, 0), 3);
    
    putText(image, "我一直在等你在未来回到我的钱包", Point(200, 100), 
            FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);
    
    putText(image, "Docker Version", Point(280, 150), 
            FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 0, 0), 2);
    
    putText(image, "❤️", Point(width/2-20, height-50), 
            FONT_HERSHEY_SIMPLEX, 1.5, Scalar(0, 0, 255), 3);
    
    // 在Docker中：只保存图片，不显示窗口
    string output_path = "/output/love_heart_docker.jpg";
    bool save_result = imwrite(output_path, image);
    
    if (save_result) {
        cout << "✅ 爱心图片已保存至: " << output_path << endl;
        cout << "📁 映射到本地: output/love_heart_docker.jpg" << endl;
        cout << "💾 图片大小: " << width << "x" << height << endl;
    } else {
        cerr << "❌ 图片保存失败！" << endl;
        cerr << "⚠️  请检查输出目录权限" << endl;
        return 1;
    }
    
    // 在Docker环境中不尝试显示窗口
    cout << "ℹ️  Docker环境已跳过窗口显示" << endl;
    cout << "🔍 请在本地文件管理器查看生成的图片" << endl;
    
    return 0;
}

