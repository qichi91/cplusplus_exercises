#include <catch.hpp>

// Ringbufferクラスを用いて移動平均(MovingAverage)クラスを作成します。
// このクラスは指定されたサイズのリングバッファを持ちます。
// バッファはint型の数値を格納します。

// リングバッファの実装は、以下のメンバ関数を持つこと
// - addValue() : バッファの末尾に要素を追加する
// - getAverage() : バッファの要素の平均を返す


/**
 * @brief 演習問題のテストコード
 *
 */
// #include "XXXXX.hpp"
TEST_CASE("exercises", "")
{
    // 変更しないこと ======>

    // MovingAverageのテスト
    MovingAverage ma(3);
    ma.addValue(1);
    ma.addValue(2);
    ma.addValue(3);
    CHECK(ma.getAverage() == 2.0);
    ma.addValue(4);
    CHECK(ma.getAverage() == 3.0);
    ma.addValue(5);
    CHECK(ma.getAverage() == 4.0);
    ma.addValue(6);
    CHECK(ma.getAverage() == 5.0);
    ma.addValue(-3);
    CHECK(ma.getAverage() == 2.6666666666666665);
    ma.addValue(2);
    CHECK(ma.getAverage() == 1.6666666666666667);
    ma.addValue(1);
    CHECK(ma.getAverage() == 0.0);
    ma.addValue(133);
    CHECK(ma.getAverage() == 45.333333333333336);
    ma.addValue(41);
    CHECK(ma.getAverage() == 58.333333333333336);
    ma.addValue(-61); 
    CHECK(ma.getAverage() == 37.666666666666664);
    ma.addValue(0);
    CHECK(ma.getAverage() == -6.666666666666667);
    ma.addValue(0);
    CHECK(ma.getAverage() == -20.333333333333332);
    ma.addValue(0);
    CHECK(ma.getAverage() == 0.0);


    // <====== ここまで
}
