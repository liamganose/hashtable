#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <node.hpp>
#include <iostream>

// Essentially is just a wrapper for a Node pointer
template<typename T_KEY, typename T_VALUE>
class Iterator {

    private:
      Node<T_KEY, T_VALUE>* node_ptr;

    public:
      Iterator();
      Iterator(Node<T_KEY, T_VALUE>* new_ptr);
      Iterator operator++(int);
      Node<T_KEY, T_VALUE>* operator*();

};

template<typename T_KEY, typename T_VALUE>
class LinkedList {

    private:
        int size;
        Node<T_KEY, T_VALUE>* tail = nullptr;
        Node<T_KEY, T_VALUE>* head = nullptr;

    public:
        LinkedList();
        ~LinkedList();
        Iterator<T_KEY, T_VALUE> begin();
        Iterator<T_KEY, T_VALUE> end();
        void push(Node<T_KEY, T_VALUE>* new_node);
        void append(Node<T_KEY, T_VALUE>* new_node);
        void insert(Node<T_KEY, T_VALUE>* new_node, Node<T_KEY, T_VALUE>* prev_node);
        void remove(Node<T_KEY, T_VALUE>* remove_node);
        int get_size();
        void print_list();

};

template<typename T_KEY, typename T_VALUE>
Iterator<T_KEY, T_VALUE>::Iterator(Node<T_KEY, T_VALUE>* new_ptr) : node_ptr(new_ptr) {}

template<typename T_KEY, typename T_VALUE>
Iterator<T_KEY, T_VALUE>::Iterator() : node_ptr(nullptr) {}

// Overloading the ++ operator on my custom Iterator class.
// Moves the iterator current node pointer to the next in the list and returns itself
template<typename T_KEY, typename T_VALUE>
Iterator<T_KEY, T_VALUE> Iterator<T_KEY, T_VALUE>::operator++(int) {
    Iterator temp = *this;
    node_ptr = node_ptr->get_next_node();
    return temp;
}

// Overload the * operator to return the pointer wrapped by the iterator
// as I'm not dereferencing I could just create a member function (e.g. .get_ptr())
template<typename T_KEY, typename T_VALUE>
Node<T_KEY, T_VALUE>* Iterator<T_KEY, T_VALUE>::operator*() {
    return node_ptr;
}

template<typename T_KEY, typename T_VALUE>
LinkedList<T_KEY, T_VALUE>::LinkedList() {

    size = 0;

}

template<typename T_KEY, typename T_VALUE>
LinkedList<T_KEY, T_VALUE>::~LinkedList() {}

template<typename T_KEY, typename T_VALUE>
Iterator<T_KEY, T_VALUE> LinkedList<T_KEY, T_VALUE>::begin() {

    return Iterator<T_KEY, T_VALUE>(head);

}

template<typename T_KEY, typename T_VALUE>
Iterator<T_KEY, T_VALUE> LinkedList<T_KEY, T_VALUE>::end() {

    return Iterator<T_KEY, T_VALUE>(tail);

}

// I wanted to set the head and tail variables to the same thing if there is only
// one node. If I didn't do this I could avoid the if statement but I felt it made 
// more sense like this
template<typename T_KEY, typename T_VALUE>
void LinkedList<T_KEY, T_VALUE>::push(Node<T_KEY, T_VALUE>* new_node) {

    if (size == 0) {
        head = new_node;
        tail = new_node;
        new_node->set_next_node(nullptr);
    } else {
        Node<T_KEY, T_VALUE>* old_head = head;
        head = new_node;
        new_node->set_next_node(old_head);
    }
    size++;

}

template<typename T_KEY, typename T_VALUE>
void LinkedList<T_KEY, T_VALUE>::append(Node<T_KEY, T_VALUE>* new_node) {

    if (size == 0) {
        head = new_node;
        tail = new_node;
        new_node->set_next_node(nullptr);
    } else {
        tail->set_next_node(new_node);
        tail = new_node;
        new_node->set_next_node(nullptr);
    }
    size++;

}

template<typename T_KEY, typename T_VALUE>
void LinkedList<T_KEY, T_VALUE>::insert(Node<T_KEY, T_VALUE>* new_node, Node<T_KEY, T_VALUE>* prev_node) {

    // This check is added to avoid pointing a node to itself and to stop any funny business with the tail
    // and the head looping - this is a list not a circle
    if (prev_node == new_node) {
        cout << "[WARNING] New node cannot be the same as the old node" << endl;
        return;
    }

    new_node->set_next_node(prev_node->get_next_node());
    prev_node->set_next_node(new_node);
    
    if (prev_node == tail) {
        tail = new_node;
    }
    size++;

}

// As this is a singly linked list I have to loop through the entire list to find the node before
// the one I want to delete. Sadly making this O(n) as apposed to O(1)
template<typename T_KEY, typename T_VALUE>
void LinkedList<T_KEY, T_VALUE>::remove(Node<T_KEY, T_VALUE>* remove_node) {

    Node<T_KEY, T_VALUE>* prev_node = head;
    Node<T_KEY, T_VALUE>* next_itr = head;
    bool node_found = false;
    // Did this out the loop to save instantiating the loop - would have to do this if statement
    // anyway so why not here
    if (remove_node == head) {
        Node<T_KEY, T_VALUE>* new_head = head->get_next_node();
        delete head;
        head = new_head;
        node_found = true;
    } else {
        for (int i=0; i<size; i++) {
            if (next_itr == remove_node) {
                prev_node->set_next_node(remove_node->get_next_node());
                delete remove_node;
                node_found = true;
                break;
            }
            prev_node = next_itr;
            next_itr = next_itr->get_next_node();
        }
    }

    if (!node_found) {
        cout << "[WARNING] Node is not in the list." << endl;
    } else {
        size--;
    }

}

template<typename T_KEY, typename T_VALUE>
int LinkedList<T_KEY, T_VALUE>::get_size() {

    return size;

}

template<typename T_KEY, typename T_VALUE>
void LinkedList<T_KEY, T_VALUE>::print_list() {

    Node<T_KEY, T_VALUE>* next_itr = head;
    for (int i=0; i<size; i++) {
        cout << "[INFO] Key: " << next_itr->get_data().first;
        cout << " Value: " << next_itr->get_data().second << endl;
        next_itr = next_itr->get_next_node();
    }

}

#endif