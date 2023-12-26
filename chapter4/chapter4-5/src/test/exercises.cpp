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

    Calculator calc;
    Complex a(1.0, 2.0);
    Complex b(3.0, 4.0);
    Complex c = calc.multiply(a, b);
    auto s = stringWrittentToStream([&c]() { c.output(); });
    REQUIRE(s == "Complex: -5, 10i\n");

    // <====== ここまで
}
