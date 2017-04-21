#include <catch.hpp>

#include <array>
#include <vector>

#include "CLRS/core/accessor.hpp"

using namespace CLRS;

TEST_CASE("core::RandomAccessor/int[]", "overall") {
  int answer[]{3, 14, 42};
  auto a = make_random_accessor(answer);
  REQUIRE( a[0]     ==  3 );
  REQUIRE( a[1]     == 14 );
  REQUIRE( a[2]     == 42 );
  REQUIRE( a.length ==  3 );
}

TEST_CASE("core::RandomAccessor/std::vector<int>", "overall") {
  std::vector<int> answer{3, 14, 42};
  auto a = make_random_accessor(answer);
  REQUIRE( a[0]     ==  3 );
  REQUIRE( a[1]     == 14 );
  REQUIRE( a[2]     == 42 );
  REQUIRE( a.length ==  3 );
}

TEST_CASE("core::RandomAccessor/std::array<int>", "overall") {
  std::array<int, 3> answer{3, 14, 42};
  auto a = make_random_accessor(answer);
  REQUIRE( a[0]     ==  3 );
  REQUIRE( a[1]     == 14 );
  REQUIRE( a[2]     == 42 );
  REQUIRE( a.length ==  3 );
}
