FROM ubuntu:22.04

# 设置时区（避免安装时的交互提示）
ENV TZ=Asia/Shanghai
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# 安装系统依赖
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    libopencv-dev \
    pkg-config \
    && rm -rf /var/lib/apt/lists/*

# 设置工作目录
WORKDIR /app

# 复制源代码到容器内
COPY src/ /app/src/

# 创建输出目录（用于保存生成的图片）
RUN mkdir /output

# 编译控制台版本
RUN g++ -o /app/love_console src/love_heart.cpp

# 编译OpenCV图形版本
RUN g++ -o /app/love_graphic src/love_opencv.cpp `pkg-config --cflags --libs opencv4`

# 设置默认启动命令
CMD ["/app/love_console"]
