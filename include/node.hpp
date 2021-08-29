#ifndef NODE_H
#define NODE_H

#include <utility>

template<typename T_KEY, typename T_VALUE>
class Node {

    private:
        std::pair<T_KEY, T_VALUE> data;
        Node* next_node;

    public:

        Node();
        Node(T_KEY key, T_VALUE value);
        ~Node();
        Node* get_next_node();
        void set_next_node(Node* new_next_node);
        bool has_next_node();
        std::pair<T_KEY, T_VALUE> get_data();
        void set_data(std::pair<T_KEY, T_VALUE> new_data);

};

template<typename T_KEY, typename T_VALUE>
Node<T_KEY, T_VALUE>::Node(T_KEY key, T_VALUE value) {

    std::pair<T_KEY, T_VALUE> new_data = {key, value};
    data = new_data;
    next_node = NULL;

}

template<typename T_KEY, typename T_VALUE>
Node<T_KEY, T_VALUE>::Node() {

    data = T_VALUE();
    next_node = NULL;

}

template<typename T_KEY, typename T_VALUE>
Node<T_KEY, T_VALUE>::~Node() {}

template<typename T_KEY, typename T_VALUE>
std::pair<T_KEY, T_VALUE> Node<T_KEY, T_VALUE>::get_data() {

    return data;

}

template<typename T_KEY, typename T_VALUE>
void Node<T_KEY, T_VALUE>::set_data(std::pair<T_KEY, T_VALUE> new_data) {

    data = new_data;

}

template<typename T_KEY, typename T_VALUE>
Node<T_KEY, T_VALUE>* Node<T_KEY, T_VALUE>::get_next_node() {

    return next_node;

}

template<typename T_KEY, typename T_VALUE>
void Node<T_KEY, T_VALUE>::set_next_node(Node* new_next_node) {

    next_node = new_next_node;

}

template<typename T_KEY, typename T_VALUE>
bool Node<T_KEY, T_VALUE>::has_next_node() {

    return next_node != NULL;

}

#endif