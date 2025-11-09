#include <gtest/gtest.h>

#include "functional.h"
#include "trie.h"

TEST(TrieTests, AddIntegers) { EXPECT_EQ(functional::add(2, 3), 5); }


/*
 *      roost
 *      rooster
 *      roaster
 *      rock
 *
 *          r
 *        o
 *       o
 *      s
 *
 * */
TEST(TrieTests, test_insert) {
  Trie trie;
  trie.insert("rory");
  trie.insert("roost");
  trie.insert("rooster");
  trie.insert("roast");

  const std::vector<std::string> expectedResult = {"rory", "roost", "rooster", "roast"};
  const auto result = trie.lookup("ro");
  ASSERT_EQ(result, expectedResult);
}
