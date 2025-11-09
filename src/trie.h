#ifndef TRIE_H
#define TRIE_H
#include <memory>
#include <vector>

class Trie {
private:
  char _value;
  std::vector<std::unique_ptr<Trie>> _children;
  std::vector<std::string> collect_paths(std::string path_);
  std::vector<std::unique_ptr<Trie>>::iterator find(std::string_view prefix_);
  std::vector<std::string> paths(const std::string &prefix_);

public:
  Trie();
  Trie(char value_);

  void insert(std::string_view word_);
  std::vector<std::string> lookup(std::string_view prefix_);
};
#endif // !TRIE_H
