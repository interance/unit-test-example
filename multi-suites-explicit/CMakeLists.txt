add_executable(multi-suites-explicit
  # algorithms.test.cpp
  # containers.test.cpp
  main.test.cpp)

target_compile_features(multi-suites-explicit PRIVATE cxx_std_${CXX_VERSION})

target_link_libraries(multi-suites-explicit PRIVATE CAF::test)

add_test(NAME multi-suites-explicit COMMAND multi-suites-explicit)
