include(FetchContent)

# Fetch GoogleTest (no need to install manually)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
# Prevent GoogleTest from overriding compiler settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add test executable
add_executable(scratch_tests
    test_trie.cpp
)

# Link with your library and GoogleTest
target_link_libraries(scratch_tests
    PRIVATE
        scratch
        GTest::gtest_main
)

# Register tests with CTest
include(GoogleTest)
gtest_discover_tests(scratch_tests)

