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
    std::shared_ptr<Airline> airline = std::make_shared<Airline>("ANA");
    Airplane airplane1("JA1234", airline);
    Airplane airplane2("JA5678", airline);
    Airplane airplane3("JA9012", airline);

    airline->addAirplane(airplane1);
    airline->addAirplane(airplane2);
    airline->addAirplane(airplane3);

    std::list<std::string> airplanes = airline->displayAirplanes();
    REQUIRE(airplanes.front() == "Airplanes in ANA: ");
    airplanes.pop_front();
    REQUIRE(airplanes.front() == "JA1234");
    airplanes.pop_front();
    REQUIRE(airplanes.front() == "JA5678");
    airplanes.pop_front();
    REQUIRE(airplanes.front() == "JA9012");
    // <====== ここまで
}
