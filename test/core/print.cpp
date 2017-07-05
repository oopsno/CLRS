#include <catch.hpp>

#include <algorithm>
#include <sstream>
#include <vector>

#include "CLRS/core/print.hpp"

using namespace CLRS;

TEST_CASE("core::Printer") {
  std::vector<int> xs{1, -1, 2, -3, 5, -8, 11};
  auto ss = std::ostringstream();
  auto printer = Printer<int>{ss};
  std::for_each(xs.cbegin(), xs.cend(), printer);
  REQUIRE(ss.str() == "1-12-35-811");
}
