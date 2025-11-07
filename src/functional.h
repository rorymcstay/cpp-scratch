//
// Created by Rory McStay on 04/11/2025.
//

#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H
#include <vector>

namespace functional {

    template<typename T>
    class Node {
        T _value;
        std::unique_ptr<Node> _left;
        std::unique_ptr<Node> _right;
    public:
        explicit Node(const T&  value_);
        Node();
        std::shared_ptr<Node<T>> find(const T& value_) const;
        [[nodiscard]] std::string to_string() const;
    };

    template<typename T>
    T add(T a, T b);

    float max_profit(const std::vector<float>& prices);

}

#endif //FUNCTIONAL_H
