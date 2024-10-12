add_executable(simple-test main.test.cpp)

target_compile_features(simple-test PRIVATE cxx_std_${CXX_VERSION})

target_link_libraries(simple-test PRIVATE CAF::test)

add_test(NAME simple-test COMMAND simple-test)
