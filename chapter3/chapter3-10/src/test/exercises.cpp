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
    std::vector<std::string> ingredients1 = {"rice", "egg", "beef", "onion"};
    std::vector<std::string> ingredients2 = {"rice", "egg", "pork", "onion"};
    std::vector<std::string> ingredients3 = {"rice", "egg", "chicken", "onion"};
    Dish dish1("Gyudon", ingredients1, 500);
    Dish dish2("Butadon", ingredients2, 450);
    Dish dish3("Oyakodon", ingredients3, 400);
    
    Restaurant restaurant;
    restaurant.addDish(dish1);
    restaurant.addDish(dish2);
    restaurant.addDish(dish3);

    std::list<std::string> menu = restaurant.displayMenu();
    REQUIRE(menu.front() == "Menu for the restaurant:\n");
    menu.pop_front();
    REQUIRE(menu.front() == "Gyudon");
    menu.pop_front();
    REQUIRE(menu.front() == "Butadon");
    menu.pop_front();
    REQUIRE(menu.front() == "Oyakodon");

    // <====== ここまで
}
