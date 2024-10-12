#include <caf/test/caf_test_main.hpp>
#include <caf/test/suite.hpp>
#include <caf/test/test.hpp>

#include <algorithm>
#include <vector>

SUITE("algorithms") {

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

} // SUITE("algorithms")

SUITE("containers") {

TEST("a default-construted vector is empty") {
  auto xs = std::vector<int>{};
  check(xs.empty());
  check_eq(xs.size(), 0u);
}

TEST("push_back increases the size of a vector") {
  auto xs = std::vector<int>{};
  xs.push_back(42);
  check_eq(xs.size(), 1u);
}

TEST("push_back adds elements to the end of a vector") {
  auto xs = std::vector<int>{};
  xs.push_back(42);
  xs.push_back(43);
  if (check_eq(xs.size(), 2u)) {
    check_eq(xs[0], 42);
    check_eq(xs[1], 43);
  }
}

} // SUITE("containers")

CAF_TEST_MAIN()
