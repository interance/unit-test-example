#include <caf/test/caf_test_main.hpp>
#include <caf/test/test.hpp>

TEST("a simple test") {
  check_eq(1, 1);
}

CAF_TEST_MAIN()
