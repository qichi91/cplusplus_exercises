#include <catch.hpp>
#include "catchhelper.hpp"

// templateを使ったジェネリックなPairクラスを作成する
// 以下の要件を満たすこと
// 1. コンストラクタで2つの値を受け取り、それぞれfirstとsecondに格納する
// 2. firstとsecondを取得するためのgetterを作成する
// 3. firstとsecondを設定するためのsetterを作成する
// 4. displayメソッドを作成する
//    このメソッドは、"Pair: "の後にfirstとsecondの値を出力する
//
// 
// Pairクラスを特殊化してfirstだけを保持するクラスを作成する
// 以下の要件を満たすこと
// 1. コンストラクタで1つの値を受け取り、それをfirstに格納する
// 2. firstを取得するためのgetterを作成する
// 3. firstを設定するためのsetterを作成する
// 4. displayメソッドを作成する
//    このメソッドは、"Single: "の後にfirstの値を出力する

#include "Pair.hpp"


/**
 * @brief 演習問題のテストコード
 * 
 */
TEST_CASE("exercises", "")
{
    // 変更しないこと ======>
    
    // Pairクラスのテスト
    // int型のテスト
    Pair<int, int> intPair(1, 2);
    REQUIRE(intPair.getFirst() == 1);
    REQUIRE(intPair.getSecond() == 2);
    auto s = stringWrittentToStream([&intPair](){ intPair.display(); });
    REQUIRE("Pair: 1, 2\n" == s);
    intPair.setFirst(3);
    intPair.setSecond(4);
    REQUIRE(intPair.getFirst() == 3);
    REQUIRE(intPair.getSecond() == 4);
    s = stringWrittentToStream([&intPair](){ intPair.display(); });
    REQUIRE("Pair: 3, 4\n" == s);

    // double型のテスト
    Pair<double, double> doublePair(1.1, 2.2);
    REQUIRE(doublePair.getFirst() == 1.1);
    REQUIRE(doublePair.getSecond() == 2.2);
    s = stringWrittentToStream([&doublePair](){ doublePair.display(); });
    REQUIRE("Pair: 1.1, 2.2\n" == s);
    doublePair.setFirst(3.3);
    doublePair.setSecond(4.4);
    REQUIRE(doublePair.getFirst() == 3.3);
    REQUIRE(doublePair.getSecond() == 4.4);
    s = stringWrittentToStream([&doublePair](){ doublePair.display(); });
    REQUIRE("Pair: 3.3, 4.4\n" == s);

    // float型のテスト
    Pair<float, float> floatPair(1.1f, 2.2f);
    REQUIRE(floatPair.getFirst() == 1.1f);
    REQUIRE(floatPair.getSecond() == 2.2f);
    s = stringWrittentToStream([&floatPair](){ floatPair.display(); });
    REQUIRE("Pair: 1.1, 2.2\n" == s);
    floatPair.setFirst(3.3f);
    floatPair.setSecond(4.4f);
    REQUIRE(floatPair.getFirst() == 3.3f);
    REQUIRE(floatPair.getSecond() == 4.4f);
    s = stringWrittentToStream([&floatPair](){ floatPair.display(); });
    REQUIRE("Pair: 3.3, 4.4\n" == s);

    // std::string型のテスト
    Pair<std::string, std::string> stringPair("Hello", "World");
    REQUIRE(stringPair.getFirst() == "Hello");
    REQUIRE(stringPair.getSecond() == "World");
    s = stringWrittentToStream([&stringPair](){ stringPair.display(); });
    REQUIRE("Pair: Hello, World\n" == s);
    stringPair.setFirst("Good");
    stringPair.setSecond("Bye");
    REQUIRE(stringPair.getFirst() == "Good");
    REQUIRE(stringPair.getSecond() == "Bye");
    s = stringWrittentToStream([&stringPair](){ stringPair.display(); });
    REQUIRE("Pair: Good, Bye\n" == s);


    // Pairクラスの特殊化のテスト
    // int型のテスト
    Pair<int, void> intPair2(1);
    REQUIRE(intPair2.getFirst() == 1);
    s = stringWrittentToStream([&intPair2](){ intPair2.display(); });
    REQUIRE("Single: 1\n" == s);

    // double型のテスト
    Pair<double, void> doublePair2(1.1);
    REQUIRE(doublePair2.getFirst() == 1.1);
    s = stringWrittentToStream([&doublePair2](){ doublePair2.display(); });
    REQUIRE("Single: 1.1\n" == s);

    // float型のテスト
    Pair<float, void> floatPair2(1.1f);
    REQUIRE(floatPair2.getFirst() == 1.1f);
    s = stringWrittentToStream([&floatPair2](){ floatPair2.display(); });
    REQUIRE("Single: 1.1\n" == s);

    // std::string型のテスト
    Pair<std::string, void> stringPair2("Hello");
    REQUIRE(stringPair2.getFirst() == "Hello");
    s = stringWrittentToStream([&stringPair2](){ stringPair2.display(); });
    REQUIRE("Single: Hello\n" == s);

    // <====== ここまで
}
