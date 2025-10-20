#!/bin/bash

echo "🐳 Docker爱心代码管理器"

case "$1" in
    "build")
        echo "正在构建Docker镜像..."
        docker build -t love-heart .
        if [ $? -eq 0 ]; then
            echo "✅ 镜像构建成功！"
        else
            echo "❌ 镜像构建失败！"
            exit 1
        fi
        ;;
    "run")
        echo "正在运行控制台版本..."
        docker run --rm love-heart
        ;;
    "run-graphic")
        echo "正在运行图形版本..."
        docker run --rm -v $(pwd)/output:/output love-heart /app/love_graphic
        echo "✅ 图片已保存到: output/love_heart_docker.jpg"
        ;;
    "shell")
        echo "进入容器Shell..."
        docker run -it --rm -v $(pwd)/output:/output love-heart /bin/bash
        ;;
    "clean")
        echo "清理Docker资源..."
        docker system prune -f
        echo "✅ 清理完成！"
        ;;
    "info")
        echo "镜像信息："
        docker images | grep love-heart
        echo ""
        echo "运行中的容器："
        docker ps | grep love-heart
        ;;
    *)
        echo "使用方法:"
        echo "  ./scripts/docker-manager.sh build       # 构建Docker镜像"
        echo "  ./scripts/docker-manager.sh run         # 运行控制台版本"
        echo "  ./scripts/docker-manager.sh run-graphic # 运行图形版本并保存图片"
        echo "  ./scripts/docker-manager.sh shell       # 进入容器内部"
        echo "  ./scripts/docker-manager.sh clean       # 清理Docker资源"
        echo "  ./scripts/docker-manager.sh info        # 查看Docker信息"
        ;;
esac
