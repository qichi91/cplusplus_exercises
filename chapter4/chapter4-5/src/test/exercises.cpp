#include <catch.hpp>
#include "catchhelper.hpp"

// 2つのクラスComplexとCalculatorを作成する
#include "complex.hpp"
#include "calculator.hpp"

// ------
// コンパイルが通るようにソースコードを変更すること
// friend修飾子を使うこと
// このファイルのコードは変更しないこと
// ------

/**
 * @brief 演習問題のテストコード
 *
 */
TEST_CASE("exercises", "")
{
    // 変更しないこと ======>

    Calculator calculator;
    Complex c1(1.0, 2.0);
    Complex c2(3.0, 4.0);
    Complex c3 = calculator.multiply(c1, c2);
    REQUIRE(c3.getReal() == -5.0);
    REQUIRE(c3.getImaginary() == 10.0);
    auto s = stringWrittentToStream([&c3]() { c3.display(); });
    REQUIRE("Complex: -5, 10i\n" == s);

    // <====== ここまで
}
