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
    
    Engine engine("engine-001", "gasoline");
    Vehicle vehicle("vehicle-001", engine);
    
    REQUIRE(vehicle.getVehicleID() == "vehicle-001");
    REQUIRE(vehicle.getEngine().getEngineID() == "engine-001");
    REQUIRE(vehicle.getEngine().getFuelType() == "gasoline");

    // <====== ここまで
}
