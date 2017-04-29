#pragma once

#include "CLRS/algorithm/sort_utils.hpp"
#include "CLRS/core/accessor.hpp"

namespace CLRS {

template<typename Iterator, typename Compare>
void insert_sort(RandomAccessor<Iterator> A, Compare compare) {
  for (auto i = 0, j = 1; j < A.length; ++j) {
    auto key = A[j];
    for (i = j - 1; i >= 0 and not compare(A[i], key); --i) {
      A[i + 1] = A[i];
    }
    A[i + 1] = key;
  }
}

STUB_SORT_ALGORITHM(insert_sort);

}

#include "CLRS/algorithm/sort_utils_cleanup.hpp"
