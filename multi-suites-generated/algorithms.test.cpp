#include <caf/test/test.hpp>

#include <algorithm>
#include <vector>

TEST("std::sort sorts a sequence of elements") {
  auto xs = std::vector{3, 1, 4, 1, 5, 9, 2, 6};
  std::sort(xs.begin(), xs.end());
  check_eq(xs, std::vector{1, 1, 2, 3, 4, 5, 6, 9});
}

TEST("std::find searches for an element in a sequence") {
  auto xs = std::vector{3, 1, 4, 1, 5, 9, 2, 6};
  auto i = std::find(xs.begin(), xs.end(), 5);
  if (check_ne(i, xs.end())) {
    check_eq(*i, 5);
  }
  check_eq(std::find(xs.begin(), xs.end(), 42), xs.end());
}
