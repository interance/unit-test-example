add_executable(outlines-test main.test.cpp)

target_compile_features(outlines-test PRIVATE cxx_std_${CXX_VERSION})

target_link_libraries(outlines-test PRIVATE CAF::test)

add_test(NAME outlines-test COMMAND outlines-test)
