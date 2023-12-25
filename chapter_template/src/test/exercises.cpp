#ifdef USING_CATCH2
#define CATCH_CONFIG_MAIN //! main()はCatch2が作ってくれる
#include <catch.hpp>      //! 環境に合わせて
#else
#include <doctest.h>
#define SECTION(name) DOCTEST_SUBCASE(name)

// only if tags are used: will concatenate them to the test name string literal
#undef TEST_CASE
#define TEST_CASE(name, tags) DOCTEST_TEST_CASE(tags " " name)

// catch exposes this by default outside of its namespace
using doctest::Approx;
#endif
#include "catchhelper.hpp"

/**
 * @brief 演習問題のテストコード
 * 
 */
// #include "XXXXX.hpp"
TEST_CASE("exercises", "")
{
    // 回答コードはここに記載する

}
