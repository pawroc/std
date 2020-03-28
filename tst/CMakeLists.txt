add_executable(ut_mystd
    test_set_difference.cpp
    test_shared_ptr.cpp
)

target_link_libraries(ut_mystd
    my::std::algorithms
    my::std::memory
)
target_include_directories(ut_mystd PRIVATE inc)