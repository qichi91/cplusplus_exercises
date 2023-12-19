#include <catch.hpp>

#include "stack.hpp"

/**
 * @brief 演習問題のテストコード
 * 
 */
TEST_CASE("exercises", "")
{
    // 変更しないこと ======>

    // int型のテスト
    Stack<int> intStack;
    REQUIRE(intStack.empty() == true);
    REQUIRE(intStack.size() == 0);
    
    intStack.push(1);
    REQUIRE(intStack.empty() == false);
    REQUIRE(intStack.size() == 1);
    REQUIRE(intStack.pop() == 1);
    REQUIRE(intStack.empty() == true);
    REQUIRE(intStack.size() == 0);

    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    REQUIRE(intStack.empty() == false);
    REQUIRE(intStack.size() == 3);
    REQUIRE(intStack.pop() == 3);
    REQUIRE(intStack.pop() == 2);
    REQUIRE(intStack.pop() == 1);
    REQUIRE(intStack.empty() == true);
    REQUIRE(intStack.size() == 0);

    // double型のテスト
    Stack<double> doubleStack;
    REQUIRE(doubleStack.empty() == true);
    REQUIRE(doubleStack.size() == 0);

    doubleStack.push(1.1);
    REQUIRE(doubleStack.empty() == false);
    REQUIRE(doubleStack.size() == 1);
    REQUIRE(doubleStack.pop() == 1.1);
    REQUIRE(doubleStack.empty() == true);
    REQUIRE(doubleStack.size() == 0);

    doubleStack.push(1.1);
    doubleStack.push(2.2);
    doubleStack.push(3.3);
    REQUIRE(doubleStack.empty() == false);
    REQUIRE(doubleStack.size() == 3);
    REQUIRE(doubleStack.pop() == 3.3);
    REQUIRE(doubleStack.pop() == 2.2);
    REQUIRE(doubleStack.pop() == 1.1);
    REQUIRE(doubleStack.empty() == true);
    REQUIRE(doubleStack.size() == 0);

    // std;;string型のテスト
    Stack<std::string> stringStack;
    REQUIRE(stringStack.empty() == true);
    REQUIRE(stringStack.size() == 0);
    
    stringStack.push("Hello");
    REQUIRE(stringStack.empty() == false);
    REQUIRE(stringStack.size() == 1);
    REQUIRE(stringStack.pop() == "Hello");
    REQUIRE(stringStack.empty() == true);
    REQUIRE(stringStack.size() == 0);

    stringStack.push("Hello");
    stringStack.push("World");
    stringStack.push("!");
    REQUIRE(stringStack.empty() == false);
    REQUIRE(stringStack.size() == 3);
    REQUIRE(stringStack.pop() == "!");
    REQUIRE(stringStack.pop() == "World");
    REQUIRE(stringStack.pop() == "Hello");
    REQUIRE(stringStack.empty() == true);
    REQUIRE(stringStack.size() == 0);
    
    // <====== ここまで
}
