#include <caf/log/test.hpp>
#include <caf/test/caf_test_main.hpp>
#include <caf/test/test.hpp>
#include <caf/type_id.hpp>

struct point {
  int x;
  int y;
};

CAF_BEGIN_TYPE_ID_BLOCK(log_test, caf::first_custom_type_id)

  CAF_ADD_TYPE_ID(log_test, (point))

CAF_END_TYPE_ID_BLOCK(log_test)

template <class Inspector>
bool inspect(Inspector& f, point& x) {
  return f.object(x).fields(f.field("x", x.x), f.field("y", x.y));
}

TEST("a simple test") {
  auto res = 0;
  caf::log::test::debug("run the for loop in line {}", __LINE__);
  for (int i = 0; i < 3; ++i) {
    caf::log::test::debug("i = {}", i);
    res += i;
  }
  check_eq(res, 3);
  auto p = point{1, 2};
  caf::log::test::info("{}", p);
  check_eq(p.x, 1);
  check_eq(p.y, 2);
}

CAF_TEST_MAIN(caf::id_block::log_test)
