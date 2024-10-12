set(test_suites algorithms containers)

add_executable(multi-suites-generated main.test.cpp)

foreach(test_suite IN LISTS test_suites)
    set_property(SOURCE ${test_suite}.test.cpp PROPERTY COMPILE_DEFINITIONS
                 CAF_TEST_SUITE_NAME=${test_suite})
    target_sources(multi-suites-generated PRIVATE ${test_suite}.test.cpp)
    add_test(NAME multi-suites-generated-${test_suite}
             COMMAND multi-suites-generated -s "^${test_suite}\$")
endforeach()

target_compile_features(multi-suites-generated PRIVATE cxx_std_${CXX_VERSION})

target_link_libraries(multi-suites-generated PRIVATE CAF::test)
