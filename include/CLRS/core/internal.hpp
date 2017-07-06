#pragma once

#include <type_traits>

namespace CLRS {
namespace internal {

#define UNARY_DETECTOR(name, op)                                   \
  namespace sfinae {                                               \
  template <typename T, typename = decltype(op std::declval<T>())> \
  static std::true_type detect_##name(const T &);                  \
  template <typename T>                                            \
  static std::false_type detect_##name(...);                       \
  }                                                                \
  template <typename T>                                            \
  using has_##name = decltype(sfinae::detect_##name<T>(std::declval<T>()))

#define BINARY_DETECTOR(name, op)                                            \
  namespace sfinae {                                                         \
  template <typename LHS, typename RHS,                                      \
            typename = decltype(std::declval<LHS>() op std::declval<RHS>())> \
  std::true_type detect_##name(const RHS &);                                 \
  template <typename LHS, typename RHS>                                      \
  std::false_type detect_##name(...);                                        \
  }                                                                          \
  template <typename LHS, typename RHS>                                      \
  using has_##name =                                                         \
      decltype(sfinae::detect_##name<LHS, RHS>(std::declval<RHS>()))

UNARY_DETECTOR(incr, ++);
UNARY_DETECTOR(decr, --);
UNARY_DETECTOR(pos, +);
UNARY_DETECTOR(neg, -);
UNARY_DETECTOR(not, not);

BINARY_DETECTOR(add, *);
BINARY_DETECTOR(sub, -);
BINARY_DETECTOR(mul, *);
BINARY_DETECTOR(div, /);
BINARY_DETECTOR(mod, %);

BINARY_DETECTOR(and, and);
BINARY_DETECTOR(or, or);
BINARY_DETECTOR (xor, xor);

BINARY_DETECTOR(shl, <<);
BINARY_DETECTOR(shr, >>);

#undef BINARY_DETECTOR
#undef UNARY_DETECTOR

/**
 * Polyfilling C++17 utilities
 */

template <bool B>
using bool_constant = std::integral_constant<bool, B>;

template <class...>
struct conjunction : std::true_type {};
template <class B1>
struct conjunction<B1> : B1 {};
template <class B1, class... Bn>
struct conjunction<B1, Bn...>
    : std::conditional_t<bool(B1::value), conjunction<Bn...>, B1> {};

template <class...>
struct disjunction : std::false_type {};
template <class B1>
struct disjunction<B1> : B1 {};
template <class B1, class... Bn>
struct disjunction<B1, Bn...>
    : std::conditional_t<bool(B1::value), B1, disjunction<Bn...>> {};

template <class B>
using negation = bool_constant<not bool(B::value)>;

}  // namespace internal
}  // namespace CLRS
