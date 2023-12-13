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

    Zoo zoo;
    zoo.addAnimal(Animal("Dog", "Bow"));
    zoo.addAnimal(Animal("Cat", "Meow"));
    zoo.addAnimal(Animal("Cow", "Moo"));

    std::vector<Animal> animals = zoo.getAnimals();
    REQUIRE(animals.size() == 3);
    REQUIRE(animals[0].getAnimalName() == "Dog");
    REQUIRE(animals[0].getSound() == "Bow");
    REQUIRE(animals[1].getAnimalName() == "Cat");
    REQUIRE(animals[1].getSound() == "Meow");
    REQUIRE(animals[2].getAnimalName() == "Cow");
    REQUIRE(animals[2].getSound() == "Moo");
    
    // <====== ここまで
}
