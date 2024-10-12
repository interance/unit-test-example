add_executable(sections-test main.test.cpp)

target_compile_features(sections-test PRIVATE cxx_std_${CXX_VERSION})

target_link_libraries(sections-test PRIVATE CAF::test)

add_test(NAME sections-test COMMAND sections-test)
