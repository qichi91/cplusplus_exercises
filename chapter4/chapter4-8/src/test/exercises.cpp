#include <catch.hpp>

// 動的に確保されたメモリを持つStringクラスを作成し、
// ムーブコンストラクタとムーブ演算子を使用して、
// オブジェクトの所有権を移動するクラスを作成する


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

    REQUIRE(strcmp(str1.c_str(), "Hello") == 0);
    REQUIRE(strcmp(str2.c_str(), "World") == 0);

    str1 = str2;

    REQUIRE(strcmp(str1.c_str(), "World") == 0);
    REQUIRE(strcmp(str2.c_str(), "World") == 0);

    String str3 = std::move(str1);

    REQUIRE(strcmp(str3.c_str(), "World") == 0);
    REQUIRE(strcmp(str2.c_str(), "World") == 0);

    str1 = std::move(str2);

    REQUIRE(strcmp(str1.c_str(), "World") == 0);
    REQUIRE(strcmp(str3.c_str(), "World") == 0);

    // <====== ここまで
}
