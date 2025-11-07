add_library(scratch
    trie.cpp
    trie.h
    functional.cpp
    functional.h
)

target_include_directories(scratch PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

