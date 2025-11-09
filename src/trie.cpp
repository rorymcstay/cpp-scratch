#include "trie.h"
#include <cstddef>
#include <cstring>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

Trie::Trie() : _value('\0') {};

Trie::Trie(char value_) : _value(value_) {};

void Trie::insert(std::string_view word_) {
  if (word_.empty()) {
    for (auto &child : _children) {
      // duplicate in its entirety, nothing to do.
      if (child->_value == '\0') {
        return;
      }
    }
    // termination of a word
    _children.emplace_back(std::make_unique<Trie>());
    return;
  }
  for (auto &child : _children) {
    if (child->_value == word_[0]) {
      word_.remove_prefix(1);
      child->insert(word_);
      return;
    }
  };
  _children.push_back(std::make_unique<Trie>(word_[0]));
  word_.remove_prefix(1);
  _children.back()->insert(word_);
}

/*
 * Given a prefix find all the possible paths it could take
 * based on the contents of the trie.
 * */
std::vector<std::string> Trie::lookup(std::string_view prefix_) {
  auto node = find(prefix_);
  if (node == _children.end()) {
    return {};
  }
  std::vector<std::string> results;
  for (auto &child : (*node)->_children) {
    auto result = child->paths(std::string(prefix_));
    results.insert(results.end(), result.begin(), result.end());
  }
  return results;
}

std::vector<std::string> Trie::collect_paths(std::string path_) {
  if (_value != '\0') {
    path_.push_back(_value);
  }
  auto results = std::vector<std::string>();
  if (_children.empty()) {
    results.push_back(path_);
    return results;
  }
  for (auto &child : _children) {
    auto childPaths = child->collect_paths(path_);
    results.insert(results.end(), childPaths.begin(), childPaths.end());
  }
  return results;
}

std::vector<std::string> Trie::paths(const std::string &prefix_) {
  return collect_paths(prefix_);
}

/*
 * locates the node for a given prefix
 * */
std::vector<std::unique_ptr<Trie>>::iterator
Trie::find(std::string_view prefix_) {
  auto first = prefix_[0];
  prefix_.remove_prefix(1);
  for (auto it = _children.begin(); it != _children.end(); it++) {
    if ((*it)->_value == first) {
      if (prefix_.empty()) {
        return it; }
      else {
        return (*it)->find(prefix_);
      }
    }
  }
  return _children.end();
}
