#include <caf/test/test.hpp>

#include <algorithm>
#include <vector>

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
