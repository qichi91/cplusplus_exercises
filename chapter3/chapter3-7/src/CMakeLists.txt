cmake_minimum_required(VERSION 3.13.0)

# CHECK::ここにサブディレクトリを追加
add_subdirectory(test)
#################
# ディレクトリを追加する場合は、ここから =====>

# add_subdirectory(XXXXX)

# <==== この間に追加する.
# 行頭のシャープはコメントアウトなので消す事
# XXXXXはディレクトリ名
#####



# add sources to the library target
target_sources(srcCompileObjects PRIVATE
    
    #####
    # ソースファイルを追加した場合は、ここから =====>

    # "${CMAKE_CURRENT_SOURCE_DIR}/XXXXX.cpp"

    # <===== ここまでの間に追加する
    # 行頭のシャープはコメントアウトなので消す事
    # XXXXXはソースファイル名
    #####
)

# set the include directories
target_include_directories(
    srcCompileObjects
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"

    # PRIVATE include
)
