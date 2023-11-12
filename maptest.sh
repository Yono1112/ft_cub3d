#!/bin/bash

# 実行するコマンドのパス
command="./cub3D"

# ANSIカラーコード
YELLOW='\033[33m'
NC='\033[0m' # No Color

# errorboxディレクトリ内のerror*.cubファイルを検出して実行
for file in errorbox/map{1..39}.cub; do
    if [ -f "$file" ]; then
        echo -e "${YELLOW}実行中: $command $file${NC}"
        $command $file
        echo "$file の実行が完了しました"
    else
        echo "ファイルが存在しません: $file"
    fi
done

echo "すべてのファイルに対する実行が完了しました"

