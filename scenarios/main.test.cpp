#include <caf/test/caf_test_main.hpp>
#include <caf/test/scenario.hpp>

#include <algorithm>
#include <vector>

SCENARIO("std::sort sorts a sequence of elements") {
  GIVEN("a vector of integers") {
    auto xs = std::vector{3, 1, 4, 1, 5, 9, 2, 6};
    WHEN("sorting the vector using std::sort") {
      std::sort(xs.begin(), xs.end());
      THEN("the vector is sorted in ascending order") {
        check_eq(xs, std::vector{1, 1, 2, 3, 4, 5, 6, 9});
      }
    }
  }
}

SCENARIO("std::find searches for an element in a sequence") {
  GIVEN("a vector of integers") {
    auto xs = std::vector{3, 1, 4, 1, 5, 9, 2, 6};
    WHEN("searching for an existing element") {
      THEN("std::find returns an iterator to the element") {
        auto i = std::find(xs.begin(), xs.end(), 5);
        if (check_ne(i, xs.end())) {
          check_eq(*i, 5);
        }
      }
    }
    WHEN("searching for a non-existing element") {
      THEN("std::find returns an iterator to the end of the sequence") {
        check_eq(std::find(xs.begin(), xs.end(), 42), xs.end());
      }
    }
  }
}

CAF_TEST_MAIN()
