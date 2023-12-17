#include <catch.hpp>

/**
 * @brief 演習問題のテストコード
 *
 */
// #include "XXXXX.hpp"
#include <float.h>
#include <math.h>
TEST_CASE("exercises", "")
{
    // 回答コードはここに記載する

    // これ以降は変更しないこと ======>

    // テストデータ
    Product product1("apple", 100.50, 10);
    Product product2("orange", 50.80, 10);
    Product product3("banana", 80.30, 10);

    ShoppingCart cart;
    cart.addItemToCart(product1);
    cart.addItemToCart(product2);
    cart.addItemToCart(product3);

    // 計算誤差以内であること
    double a = cart.displayTotal();
    double b = 231.60;
    REQUIRE(fabs(a - b) <= (DBL_EPSILON * fmax(1.0, fmax(fabs(a), fabs(b)))));
    // <====== ここまで
}
