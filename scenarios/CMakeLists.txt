add_executable(scenarios-test main.test.cpp)

target_compile_features(scenarios-test PRIVATE cxx_std_${CXX_VERSION})

target_link_libraries(scenarios-test PRIVATE CAF::test)

add_test(NAME scenarios-test COMMAND scenarios-test)
