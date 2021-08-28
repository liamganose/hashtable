#ifndef NODE_H
#define NODE_H

#include <utility>

using namespace std;

template<typename T_KEY, typename T_VALUE>
class Node {

    private:
        pair<T_KEY, T_VALUE> data;
        Node* next_node;

    public:

        Node();
        Node(T_KEY key, T_VALUE value);
        ~Node();
        Node* get_next_node();
        void set_next_node(Node* new_next_node);
        bool has_next_node();
        pair<T_KEY, T_VALUE> get_data();
        void set_data(pair<T_KEY, T_VALUE> new_data);

};

template<typename T_KEY, typename T_VALUE>
Node<T_KEY, T_VALUE>::Node(T_KEY key, T_VALUE value) {

    pair<T_KEY, T_VALUE> new_data = {key, value};
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
pair<T_KEY, T_VALUE> Node<T_KEY, T_VALUE>::get_data() {

    return data;

}

template<typename T_KEY, typename T_VALUE>
void Node<T_KEY, T_VALUE>::set_data(pair<T_KEY, T_VALUE> new_data) {

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