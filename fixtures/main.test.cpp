#include <caf/test/caf_test_main.hpp>
#include <caf/test/test.hpp>

struct my_fixture {
  int x = 0;
  int y = 0;

  void setup() {
    x = 42;
    y = 23;
  }
};

WITH_FIXTURE(my_fixture) {

TEST("tests can access fixture members") {
  check_eq(x, 0);
  check_eq(y, 0);
  setup();
  check_eq(x, 42);
  check_eq(y, 23);
}

} // WITH_FIXTURE(my_fixture)

CAF_TEST_MAIN()
