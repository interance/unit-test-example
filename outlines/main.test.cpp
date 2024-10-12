#include <caf/test/caf_test_main.hpp>
#include <caf/test/outline.hpp>

#include <algorithm>
#include <vector>

OUTLINE("adding two numbers") {
  GIVEN("the numbers <a> and <b>") {
    auto [a, b] = block_parameters<int, int>();
    WHEN("adding the numbers") {
      auto result = a + b;
      THEN("the result is <sum>") {
        auto sum = block_parameters<int>();
        check_eq(result, sum);
      }
    }
  }
  EXAMPLES = R"_(
    | a  | b  | sum |
    | 1  | 7  | 8   |
    | 7  | 1  | 8   |
    | -7 | 11 | 4   |
  )_";
}

OUTLINE("std::sort sorts a sequence of elements") {
  GIVEN("a vector containing the values <input>") {
    auto input = block_parameters<std::vector<int>>();
    WHEN("sorting the vector using std::sort") {
      std::sort(input.begin(), input.end());
      THEN("the vector should contain <output>") {
        auto output = block_parameters<std::vector<int>>();
        check_eq(input, output);
      }
    }
  }
  EXAMPLES = R"_(
    | input                    | output                   |
    | 1                        | [1]                      |
    | [1, 3, 2]                | [1, 2, 3]                |
    | 3, 1, 4, 1, 5, 9, 2, 6   | 1, 1, 2, 3, 4, 5, 6, 9   |
  )_";
}

namespace {

struct point {
  int x;
  int y;

  point& operator+=(int scalar) {
    x += scalar;
    y += scalar;
    return *this;
  }
};

inline bool operator==(const point& x, const point& y) {
  return x.x == y.x && x.y == y.y;
}

template <class Inspector>
bool inspect(Inspector& f, point& x) {
  return f.object(x).fields(f.field("x", x.x), f.field("y", x.y));
}

} // namespace

OUTLINE("points can be scaled by adding a scalar to both coordinates") {
  GIVEN("the point <input>") {
    auto value = block_parameters<point>();
    WHEN("adding the scalar <scalar> to it") {
      auto scalar = block_parameters<int>();
      value += scalar;
      THEN("the result point is <output>") {
        auto output = block_parameters<point>();
        check_eq(value, output);
      }
    }
  }
  EXAMPLES = R"_(
    | input            | scalar | output           |
    | {"x": 7, "y": 5} |  2     | {"x": 9, "y": 7} |
    | {"x": 0, "y": 0} |  0     | {"x": 0, "y": 0} |
    | {"x": 1, "y": 2} | -1     | {"x": 0, "y": 1} |
  )_";
}

CAF_TEST_MAIN()
