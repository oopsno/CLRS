#include "CLRS/core/internal.hpp"
#include <catch.hpp>

using namespace CLRS::internal;

#define SUPPORT_BINARY(LHS, op, RHS) (has_##op<LHS, RHS>::value)
#define SUPPORT_UNARY(op, T) (has_##op<T>::value)

TEST_CASE("CLRS::internal::operator_detector") {
  REQUIRE(SUPPORT_BINARY(int, add, float));
  REQUIRE(SUPPORT_BINARY(int, sub, float));
  REQUIRE(SUPPORT_BINARY(int, mul, float));
  REQUIRE(SUPPORT_BINARY(int, div, float));
  REQUIRE(SUPPORT_BINARY(int, mod, int));
  REQUIRE(SUPPORT_BINARY(int, shl, int));
  REQUIRE(SUPPORT_BINARY(int, shr, int));
  REQUIRE(SUPPORT_BINARY(int, and, int));
  REQUIRE(SUPPORT_BINARY(int, or, int));
  REQUIRE(SUPPORT_BINARY(int, xor, int));

  REQUIRE(not SUPPORT_BINARY(int, mod, float));
  REQUIRE(not SUPPORT_BINARY(int, shl, float));
  REQUIRE(not SUPPORT_BINARY(int, shr, float));

  REQUIRE(SUPPORT_UNARY(pos, int));
  REQUIRE(SUPPORT_UNARY(neg, int));
  REQUIRE(SUPPORT_UNARY(not, int));

  // TODO fix non-const operator
  REQUIRE(not SUPPORT_UNARY(incr, int));
  REQUIRE(not SUPPORT_UNARY(decr, int));
}
