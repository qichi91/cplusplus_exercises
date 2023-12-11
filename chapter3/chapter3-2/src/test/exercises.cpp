#include <catch.hpp>

/**
 * @brief 演習問題のテストコード
 * 
 */
// #include "XXXXX.hpp"
TEST_CASE("exercises", "")
{
    // 回答コードはここに記載する

    // これ以降は変更しないこと ======>
    // 円と正方形の面積を計算する
    // 半径10の円
    auto circle = Circle(10);
    // 幅3x高さ4の正方形
    auto rectangle = Rectangle(3,4);
    // 底辺9x高さ4の三角形
    auto triangle = Triangle(9,4);

    REQUIRE(circle.calculateArea() == Approx(314.0));
    REQUIRE(rectangle.calculateArea() == Approx(12.0));
    REQUIRE(triangle.calculateArea() == Approx(18.0));

    // これ以降は変更しないこと <======
}
