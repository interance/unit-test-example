#include <caf/log/test.hpp>
#include <caf/test/caf_test_main.hpp>
#include <caf/test/test.hpp>


using namespace std::literals;

TEST("sections showcase") {
  auto path = "test"s;
  SECTION("section 1") {
    path += " « section 1";
    SECTION("section 1.1") {
      path += ".1";
      SECTION("section 1.1.1") {
        path += ".1";
        caf::log::test::info("{}", path);
      }
      SECTION("section 1.1.2") {
        path += ".2";
        caf::log::test::info("{}", path);
      }
    }
    SECTION("section 1.2") {
      path += ".2";
      caf::log::test::info("{}", path);
    }
  }
  SECTION("section 2") {
    path += " « section 2";
    SECTION("section 2.1") {
      path += ".1";
      caf::log::test::info("{}", path);
    }
    SECTION("section 2.2") {
      path += ".2";
      caf::log::test::info("{}", path);
    }
  }
}

CAF_TEST_MAIN()
