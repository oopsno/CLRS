#include <catch.hpp>

#include "CLRS/algorithm/insert_sort.hpp"

using namespace CLRS;

TEST_CASE("algorithm::insert_sort/int[]", "overall") {
  int numbers[] = { 42, 21, 10 };
  insert_sort(numbers);
  REQUIRE( std::is_sorted(numbers, numbers + 3) );
  insert_sort(numbers, std::greater<int>());
  REQUIRE( std::is_sorted(std::crbegin(numbers), std::crend(numbers)) );
}
