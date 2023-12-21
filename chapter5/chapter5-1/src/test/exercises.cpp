#include <catch.hpp>

// リングバッファ（別名：サーキュラーバッファ）を実装してください。
// リングバッファは、指定されたサイズの配列で構成され、要素の挿入と参照ができます。
// バッファする型はテンプレートで定義してください。
// バッファのサイズは、コンストラクタで指定できるようにしてください。
// 配列はstd::vectorで実装してください。

// リングバッファの実装は、以下のメンバ関数を持つこと
// - push() : バッファの末尾に要素を追加する
// - front() : バッファの先頭の要素を取得する
// - back() : バッファの末尾の要素を取得する
// - size() : バッファの要素数を返す
// - capacity() : バッファのサイズを返す
// - empty() : バッファが空かどうかを返す
// - full() : バッファが満杯かどうかを返す



/**
 * @brief 演習問題のテストコード
 *
 */
// #include "XXXXX.hpp"
TEST_CASE("exercises", "")
{
    // 変更しないこと ======>

    RingBuffer<int> buffer(3);
    REQUIRE(buffer.empty());
    REQUIRE(!buffer.full());
    REQUIRE(buffer.size() == 0);
    REQUIRE(buffer.capacity() == 3);

    buffer.push(1);
    REQUIRE(!buffer.empty());
    REQUIRE(!buffer.full());
    REQUIRE(buffer.size() == 1);
    REQUIRE(buffer.capacity() == 3);
    REQUIRE(buffer.front() == 1);
    REQUIRE(buffer.back() == 1);

    buffer.push(2);
    REQUIRE(!buffer.empty());
    REQUIRE(!buffer.full());
    REQUIRE(buffer.size() == 2);
    REQUIRE(buffer.capacity() == 3);
    REQUIRE(buffer.front() == 1);
    REQUIRE(buffer.back() == 2);

    buffer.push(3);
    REQUIRE(!buffer.empty());
    REQUIRE(buffer.full());
    REQUIRE(buffer.size() == 3);
    REQUIRE(buffer.capacity() == 3);
    REQUIRE(buffer.front() == 1);
    REQUIRE(buffer.back() == 3);

    buffer.push(4);
    REQUIRE(!buffer.empty());
    REQUIRE(buffer.full());
    REQUIRE(buffer.size() == 3);
    REQUIRE(buffer.capacity() == 3);
    REQUIRE(buffer.front() == 2);
    REQUIRE(buffer.back() == 4);

    buffer.push(5);
    REQUIRE(!buffer.empty());
    REQUIRE(buffer.full());
    REQUIRE(buffer.size() == 3);
    REQUIRE(buffer.capacity() == 3);
    REQUIRE(buffer.front() == 3);
    REQUIRE(buffer.back() == 5);

    buffer.push(6);
    REQUIRE(!buffer.empty());
    REQUIRE(buffer.full());
    REQUIRE(buffer.size() == 3);
    REQUIRE(buffer.capacity() == 3);
    REQUIRE(buffer.front() == 4);
    REQUIRE(buffer.back() == 6);

    buffer.push(7);
    REQUIRE(!buffer.empty());
    REQUIRE(buffer.full());
    REQUIRE(buffer.size() == 3);
    REQUIRE(buffer.capacity() == 3);
    REQUIRE(buffer.front() == 5);
    REQUIRE(buffer.back() == 7);

    buffer.push(8);
    REQUIRE(!buffer.empty());
    REQUIRE(buffer.full());
    REQUIRE(buffer.size() == 3);
    REQUIRE(buffer.capacity() == 3);
    REQUIRE(buffer.front() == 6);
    REQUIRE(buffer.back() == 8);

    buffer.push(9);
    REQUIRE(!buffer.empty());
    REQUIRE(buffer.full());
    REQUIRE(buffer.size() == 3);

    // <====== ここまで
}
