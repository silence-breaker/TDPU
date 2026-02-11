#!/bin/bash

# 查找并删除当前目录及子目录下所有以 :Zone.Identifier 或 .Zone.Identifier 结尾的文件
# -print 会在删除前打印文件名，方便你知道删除了哪些文件

echo "开始清理 Zone.Identifier 文件..."

find . -type f \( -name "*:Zone.Identifier" -o -name "*.Zone.Identifier" \) -print -delete

echo "清理完成。"
