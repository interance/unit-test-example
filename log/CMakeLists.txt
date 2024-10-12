add_executable(log-test main.test.cpp)

target_compile_features(log-test PRIVATE cxx_std_${CXX_VERSION})

target_link_libraries(log-test PRIVATE CAF::test)

add_test(NAME log-test COMMAND log-test)
