cmake_minimum_required(VERSION 3.13.0)

# projectは実行ファイルを作成するときにだけ設定する
project(testExecutor
    VERSION 0.1.0
    DESCRIPTION
    "..."
    LANGUAGES C CXX)

# VSCodeのIntelliSenseにInclude Pathを設定するための設定
# cmakeのビルドを実行すると、ビルド先にcompile_commands.jsonが生成される
# .vscode/c_cpp_properties.jsonにcompile_commands.jsonのパスを設定するとインテリセンスが効く
#       "compileCommands": "${workspaceFolder}/build/compile_commands.json"
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# c++17定義
enable_language(CXX)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# サブディレクトリ全体をコンパイルしたオブジェクトライブラリを定義
add_library(srcCompileObjects OBJECT "main.cpp")
# include pathの設定
target_include_directories(
    srcCompileObjects
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/../../include/Catch2"
)

# CHECK::ここにサブディレクトリを追加
add_subdirectory(src)

# 実行バイリの出力先(build/{project src path}/output)
set(EXECUTABLE_OUTPUT_PATH output)

# 実行ファイルの作成
add_executable(${PROJECT_NAME})

target_compile_options(
    ${PROJECT_NAME}
    PRIVATE
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic>
    $<$<CXX_COMPILER_ID:GCC>:-pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused>
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
)

# 実行ファイルにコンパイル済みオブジェクトライブラリを追加
target_link_libraries(${PROJECT_NAME} PRIVATE srcCompileObjects)

# 実行ファイルと同じ場所にテスト用のファイルをコピー
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/src/readfile.txt $<TARGET_FILE_DIR:${PROJECT_NAME}>)