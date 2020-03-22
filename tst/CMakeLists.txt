add_executable(ut_algorithms test_set_difference.cpp)

target_link_libraries(ut_algorithms my::std::algorithms)
target_include_directories(ut_algorithms PRIVATE inc)