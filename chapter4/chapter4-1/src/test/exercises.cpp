#include <catch.hpp>


/**
 * @brief 演習問題のテストコード
 * 
 */
#include "add.hpp"
TEST_CASE("exercises", "")
{
    // 変更しないこと ======>

    // int型のテスト
    REQUIRE(add(1, 2) == 3);

    // double型のテスト
    REQUIRE(add(1.1, 2.2) == Approx(3.3));

    // float型のテスト
    REQUIRE(add(1.1f, 2.2f) == Approx(3.3f));

    // std::string型のテスト
    REQUIRE(add(std::string("Hello"), std::string("World")) == "HelloWorld");
    
    // <====== ここまで
}
