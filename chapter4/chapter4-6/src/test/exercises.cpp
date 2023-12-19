#include <catch.hpp>
#include "catchhelper.hpp"

// 文字列を表すクラスを作成する
// 以下の要件を満たすこと
// 1. Stringクラスは、std:string型のm_strをメンバ変数として持つ
// 2. Stringクラスは、m_strをコンストラクタで初期化する
// 3. displayメソッドを作成する
//    このメソッドは、m_strを出力する
// 4. Srtingクラスを引数に取るコピーコンストラクタを作成する
// 5. std::stringを引数に取るコンストラクタを作成する
// 6. getStringメソッドを作成する
//    このメソッドは、m_strを返す
// 7. setStringメソッドを作成する
//    このメソッドは、m_strを引数の値で更新する

#include "string.hpp"

/**
 * @brief 演習問題のテストコード
 * 
 */
TEST_CASE("exercises", "")
{
    // 変更しないこと ======>

    String s1("Hello");
    auto s = stringWrittentToStream([&s1]() { s1.display(); });
    REQUIRE("Hello\n" == s);

    // コピーされている事
    String s2(s1);
    REQUIRE(s2.getString() == "Hello");
    s = stringWrittentToStream([&s2]() { s2.display(); });
    REQUIRE("Hello\n" == s);

    // s2のstrを書き換えてもs1に影響がない事
    s2.setString("World");
    s = stringWrittentToStream([&s2]() { s2.display(); });
    REQUIRE("World\n" == s);
    s = stringWrittentToStream([&s1]() { s1.display(); });
    REQUIRE("Hello\n" == s);

    // <====== ここまで
}
