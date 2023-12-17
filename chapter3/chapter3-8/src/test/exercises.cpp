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

    // テストデータ
    Book book1("The C++ Programming Language", "Bjarne Stroustrup", "978-0321563842");
    Book book2("Effective Modern C++", "Scott Meyers", "978-1491903995");
    Book book3("Effective C++", "Scott Meyers", "978-0321334879");

    // テスト
    Library library;
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    REQUIRE(library.searchBook("The C++ Programming Language").getAuthor() == "Bjarne Stroustrup");
    REQUIRE(library.searchBook("Effective Modern C++").getISBN() == "978-1491903995");
    REQUIRE(library.searchBook("Effective C++").getTitle() == "Effective C++");
    REQUIRE(library.searchBook("Effective C++").getAuthor() == "Scott Meyers");
    REQUIRE(library.searchBook("Effective C++").getISBN() == "978-0321334879");

    // <====== ここまで
}
