#!/bin/bash

echo "💝 爱心代码项目 - 选择运行方式"
echo "================================="

PS3='请选择运行方式: '
options=("Docker控制台版本" "Docker图形版本" "进入容器Shell" "查看Docker信息" "退出")
select opt in "${options[@]}"
do
    case $opt in
        "Docker控制台版本")
            echo "运行Docker控制台版本..."
            ./scripts/docker-manager.sh run
            ;;
        "Docker图形版本")
            echo "运行Docker图形版本..."
            ./scripts/docker-manager.sh run-graphic
            ;;
        "进入容器Shell")
            echo "进入容器Shell..."
            ./scripts/docker-manager.sh shell
            ;;
        "查看Docker信息")
            echo "Docker信息:"
            ./scripts/docker-manager.sh info
            ;;
        "退出")
            break
            ;;
        *) echo "无效选项 $REPLY";;
    esac
done
