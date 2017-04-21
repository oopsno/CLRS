#pragma once

#include <iterator>

namespace CLRS {

template<typename RandomIterator>
struct RandomImmutableAccessor {
  using difference_type = typename std::iterator_traits<RandomIterator>::difference_type;
  using value_type = typename std::iterator_traits<RandomIterator>::value_type;
  using referance = value_type&;
  using const_referance = typename std::add_const<referance>::type;

  explicit RandomImmutableAccessor(const RandomIterator first, const RandomIterator last) :
      first{first}, last{last}, length{std::distance(first, last)} {}

  inline const_referance operator[](difference_type offset) const {
    return *(first + offset);
  }

  const RandomIterator first, last;
  const difference_type length;
};

template<typename RandomIterator>
struct RandomAccessor: public RandomImmutableAccessor<RandomIterator> {
  using referance = typename RandomImmutableAccessor<RandomIterator>::referance;
  using difference_type = typename RandomImmutableAccessor<RandomIterator>::difference_type;

  explicit RandomAccessor(RandomIterator first, RandomIterator last) : RandomImmutableAccessor<RandomIterator>{first, last} {}

  inline referance operator[](difference_type offset) {
    return *(this->first + offset);
  }
};

template<typename Iterable>
inline auto make_random_accessor(Iterable& iterable) {
  using iterator = decltype(std::begin(iterable));
  return RandomAccessor<iterator>{std::begin(iterable), std::end(iterable)};
}

template<typename Iterable>
inline auto make_immutable_random_accessor(Iterable& iterable) {
  using iterator = decltype(std::cbegin(iterable));
  return RandomImmutableAccessor<iterator>{std::cbegin(iterable), std::cend(iterable)};
}

}
