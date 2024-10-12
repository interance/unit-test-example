add_executable(fixtures-test main.test.cpp)

target_compile_features(fixtures-test PRIVATE cxx_std_${CXX_VERSION})

target_link_libraries(fixtures-test PRIVATE CAF::test)

add_test(NAME fixtures-test COMMAND fixtures-test)
