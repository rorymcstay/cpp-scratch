#ifndef TRIE_H
#define TRIE_H
#include <string>

class trie {
private:
  char _value;
  trie[10] _children;

public:
  trie();

  void insert(const std::string &word_) {
    char this_char = word_.at(0);
    if (this_char == _value) {
    }
  };
};
#endif // !TRIE_H
