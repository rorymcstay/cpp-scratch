//
// Created by Rory McStay on 04/11/2025.
//

#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H
#include <memory>
#include <vector>

namespace functional {

template <typename T> class Node {
  T _value;
  std::unique_ptr<Node> _left;
  std::unique_ptr<Node> _right;

public:
  explicit Node(const T &value_)
      : _value(value_), _left(nullptr), _right(nullptr) {};
  Node() : _value(), _left(nullptr), _right(nullptr) {};
  std::shared_ptr<Node<T>> find(const T &value_) const {
    if (value_ == _value) {
      return std::shared_ptr<Node>(this);
    } else if (value_ < _value) {
      return _left->find(value_);
    } else {
      return _right->find(value_);
    }
  };

  [[nodiscard]] std::string to_string() const {
    return "Node(" + _value + ")";
  };
};

template <typename T> T add(T a, T b) { return a + b; }

inline float max_profit(const std::vector<float> &prices) { return 1; }

} // namespace functional

#endif // FUNCTIONAL_H
