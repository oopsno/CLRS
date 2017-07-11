#pragma once

#include <algorithm>
#include <limits>
#include <memory>
#include "CLRS/algorithm/sort_utils.hpp"
#include "CLRS/core/accessor.hpp"

namespace CLRS {

template <typename Iterator, typename Comparer>
void merge(RandomAccessor<Iterator> A, Comparer comparer, size_t begin, size_t pivot, size_t end) {
  using data_t = typename RandomAccessor<Iterator>::value_type;
  auto left_length = pivot - begin;
  auto right_length = end - pivot;
  auto left = new data_t[left_length];
  auto right = new data_t[right_length];
  std::copy(A.cbegin() + begin, A.cbegin() + pivot, left);
  std::copy(A.cbegin() + pivot, A.cbegin() + end, right);
  size_t i = 0, j = 0, k = begin;
  while (i < left_length and j < right_length) {
    if (comparer(left[i], right[j])) {
      A[k++] = left[i++];
    } else {
      A[k++] = right[j++];
    }
  }
  while (i < left_length) {
    A[k++] = left[i++];
  }
  while (j < right_length) {
    A[k++] = right[j++];
  }
  delete[](left);
  delete[](right);
}

template <typename Iterator, typename Comparer>
void merge_sort_on(RandomAccessor<Iterator> A, Comparer comparer, size_t begin,
                   size_t end) {
  if (end - begin > 1) {
    const size_t pivot = (begin + end) / 2;
    merge_sort_on(A, comparer, begin, pivot);
    merge_sort_on(A, comparer, pivot, end);
    merge(A, comparer, begin, pivot, end);
  }
}

template <typename Iterator, typename Comparer>
inline void merge_sort(RandomAccessor<Iterator> A, Comparer compare) {
  merge_sort_on(A, compare, 0, A.length);
}

STUB_SORT_ALGORITHM(merge_sort);

}  // namespace CLRS

#include "CLRS/algorithm/sort_utils_cleanup.hpp"
