#pragma once

#include <functional>

#define STUB_SORT_ALGORITHM(fn)                                                   \
  template<typename Array>                                                        \
  inline void fn(Array& array) {                                                  \
    auto A = make_random_accessor(array);                                         \
    fn(A, std::less<typename decltype(A)::value_type>());                         \
  }                                                                               \
                                                                                  \
  template<typename RandomIterator>                                               \
  inline void fn(RandomIterator first, RandomIterator last) {                     \
    using value_type = typename std::iterator_traits<RandomIterator>::value_type; \
    fn(RandomAccessor<RandomIterator>{first, last}, std::less<value_type>());     \
  }                                                                               \
                                                                                  \
  template<typename Array, typename Compare>                                      \
  inline void fn(Array& array, Compare compare) {                                 \
    fn(make_random_accessor(array), compare);                                     \
  }                                                                               \
                                                                                  \
  template<typename RandomIterator, typename Compare>                             \
  inline void fn(RandomIterator first, RandomIterator last, Compare compare) {    \
    fn(RandomAccessor<RandomIterator>{first, last}, compare);                     \
  }
