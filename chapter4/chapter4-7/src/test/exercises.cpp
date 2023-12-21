#include <catch.hpp>

// 文字列を表すStringクラスを作成し、
// コピーアサインメント演算子を使用して
// 既存のオブジェクトに別のオブジェクトを代入するクラスを実装する.

/**
 * @brief 演習問題のテストコード
 * 
 */
// #include "XXXXX.hpp"
TEST_CASE("exercises", "")
{
    // 変更しないこと ======>

    String str1("Hello");
    String str2("World");
    str1 = str2;
    REQUIRE(strcmp(str1.c_str(), "World") == 0);
    REQUIRE(strcmp(str2.c_str(), "World") == 0);
    
    // <====== ここまで
}
