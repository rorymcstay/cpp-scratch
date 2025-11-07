//
// Created by Rory McStay on 04/11/2025.
//

#include "functional.h"

#include <vector>


namespace functional {

float max_profit(const std::vector<float>& prices) {
    return 1;
}


template<typename T>
std::shared_ptr<Node<T>> Node<T>::find(const T& value_) const {
    if (value_ == _value) {
        return std::shared_ptr<Node>(this);
    } else if (value_ < _value){
        return _left->find(value_);
    } else {
        return _right->find(value_);
    }
}

template<typename T>
std::string Node<T>::to_string() const {
    return "Node(" + _value + ")";
}


template<typename T>
Node<T>::Node(const T&  value_)
    :
    _value(value_),
    _left(nullptr),
    _right(nullptr)
    {
}


template<typename T>
Node<T>::Node()
    :
    _value(),
    _left(nullptr),
    _right(nullptr)
    {}

}

template<typename T> T add(T a, T b) {
  return a + b;
}
