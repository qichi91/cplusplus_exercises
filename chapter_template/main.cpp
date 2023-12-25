#ifdef USING_CATCH2
#define CATCH_CONFIG_MAIN //! main()はCatch2が作ってくれる
#include <catch.hpp>      //! 環境に合わせて
#else
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#endif
