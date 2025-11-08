#include "functional.h"
#include "trie.h"
#include <gtest/gtest.h>

TEST(TrieTests, AddIntegers) { EXPECT_EQ(functional::add(2, 3), 5); }
