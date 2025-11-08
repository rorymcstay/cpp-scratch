add_library(scratch
    trie.cpp
    trie.h
    functional.h
)

target_include_directories(scratch PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

