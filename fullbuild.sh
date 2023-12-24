#!/bin/sh

# rm -rf build

# 1. 指定したディレクトリ以下にある、main.cppのあるディレクトリを取得
search_dir=$1
directories=$(find "$search_dir" -type f -name "main.cpp" -exec dirname {} \; | grep -E -v "chapter_template")

# 2. 各ディレクトリに対してcmakeでビルドを実行
for dir in $directories; do
    echo $dir
    _BUILD_DIR="build/$(basename $dir)"
    echo $_BUILD_DIR
    # 2-1. cmakeコマンド実行
    cmake -S "$dir" -B $_BUILD_DIR
    
    # 2-2. cmake --buildコマンド実行
    cmake --build $_BUILD_DIR
    
    # 2-3. テスト実行
    if [ -x "$_BUILD_DIR/output/testExecutor" ]; then
        # エラーなら終了
        if ! "$_BUILD_DIR/output/testExecutor"; then
            exit 1
        fi
    else
        echo "Error: testExecutor not found in build directory for $dir"
    fi
done