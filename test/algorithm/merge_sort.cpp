#include "CLRS/algorithm/merge_sort.hpp"
#include <catch.hpp>

using namespace CLRS;

TEST_CASE("CLRS::algorithm::merge_sort") {
  auto numbers = std::vector<int>{42, 21, 10, -4, 9};
  merge_sort(numbers);
  REQUIRE(std::is_sorted(numbers.cbegin(), numbers.cend()));
  merge_sort(numbers, std::greater<int>());
  REQUIRE(std::is_sorted(std::crbegin(numbers), std::crend(numbers)));
}
