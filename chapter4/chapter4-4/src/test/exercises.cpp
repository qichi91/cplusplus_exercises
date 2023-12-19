#include <catch.hpp>
#include "catchhelper.hpp"

// 2次元ベクトルを表すVector2Dクラスを作成する
// 以下の要件を満たすこと
// 1. コンストラクタでxとyを受け取り、それぞれm_xとm_yに格納する
// 2. xとyはint型とする.
// 3. m_xとm_yを取得するためのgetterを作成する
// 4. m_xとm_yを設定するためのsetterを作成する
// 5. displayメソッドを作成する
//    このメソッドは、"Vector2D: "の後にm_xとm_yの値を出力する
// 6. operator+をオーバーロードして、2つのVector2Dを加算する
//    この演算子は、Vector2Dのxとyをそれぞれ加算したVector2Dを返す
//
#include "vector2d.hpp"

/**
 * @brief 演習問題のテストコード
 * 
 */
TEST_CASE("exercises", "")
{
    // 変更しないこと ======>

    // Vector2Dクラスのテスト
    Vector2D v1(1, 2);
    REQUIRE(v1.getX() == 1);
    REQUIRE(v1.getY() == 2);
    auto s = stringWrittentToStream([&v1](){ v1.display(); });
    REQUIRE("Vector2D: 1, 2\n" == s);
    v1.setX(3);
    v1.setY(4);
    REQUIRE(v1.getX() == 3);
    REQUIRE(v1.getY() == 4);
    s = stringWrittentToStream([&v1](){ v1.display(); });
    REQUIRE("Vector2D: 3, 4\n" == s);

    // <====== ここまで
}
