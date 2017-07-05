#pragma once

#include <type_traits>

namespace CLRS {
namespace internal {

#define MAKE_DETECTOR(name, op)                                              \
  namespace sfinae {                                                         \
  template <typename LHS, typename RHS,                                      \
            typename = decltype(std::declval<LHS>() op std::declval<RHS>())> \
  static std::true_type detect_##name(const RHS&);                           \
  template <typename LHS, typename RHS,                                      \
            typename = decltype(std::declval<LHS>() op std::declval<RHS>())> \
  static std::false_type detect_##name(...);                                 \
  }                                                                          \
  template <typename LHS, typename RHS>                                      \
  struct has_##name                                                          \
      : decltype(sfinae::detect_##name<LHS, RHS>(std::declval<RHS>())) {}

MAKE_DETECTOR(shl, <<);
MAKE_DETECTOR(shr, >>);

#undef MAKE_DETECTOR

}  // namespace internal
}  // namespace CLRS
