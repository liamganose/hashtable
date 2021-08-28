#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <utility>
#include <unordered_map>
#include <linked_list.hpp>

using namespace std;

template<typename T_KEY, typename T_VALUE>
class HashTable {

    private:
        int hash_buckets = 50;
        LinkedList<T_KEY, T_VALUE> table[50];
    
    public:
        HashTable();
        ~HashTable();
        bool is_empty();
        int hash_function(T_KEY key);
        void insert(T_KEY key, T_VALUE value);
        void remove(T_KEY key);
        T_VALUE get(T_KEY key);
        void print_table();

};

template<typename T_KEY, typename T_VALUE>
HashTable<T_KEY, T_VALUE>::HashTable() {};

template<typename T_KEY, typename T_VALUE>
HashTable<T_KEY, T_VALUE>::~HashTable() {};

template<typename T_KEY, typename T_VALUE>
bool HashTable<T_KEY, T_VALUE>::is_empty() {

    for (int i=0; i<hash_buckets; i++) {
        if (table[i].get_size()) {
            return false;
        } 
    }

    return true;

}

// To do: create a hash function
// maybe (string) pointer -> polynomial rolling hash function
// or (string) pointer -> djb2 (http://www.cse.yorku.ca/~oz/hash.html)
template<typename T_KEY, typename T_VALUE>
int HashTable<T_KEY, T_VALUE>::hash_function(T_KEY key) {

    return hash<T_KEY>{}(key) % hash_buckets;

}

template<typename T_KEY, typename T_VALUE>
void HashTable<T_KEY, T_VALUE>::insert(T_KEY key, T_VALUE value) {

    int index = hash_function(key);
    LinkedList<T_KEY, T_VALUE> &ll = table[index];
    bool key_exists = false;

    for (Iterator<T_KEY, T_VALUE> ptr_node = ll.begin(); *ptr_node != nullptr; ptr_node++) {
        if ((*ptr_node)->get_data().first == key) {
            key_exists = true;
            (*ptr_node)->set_data(pair<T_KEY, T_VALUE>(key, value));
            cout << "[WARNING] Key esists. Value replaced." << endl;
            break;
        }
    }

    if (!key_exists) {
        ll.append(new Node<T_KEY, T_VALUE>(key, value));
    }

}

template<typename T_KEY, typename T_VALUE>
void HashTable<T_KEY, T_VALUE>::remove(T_KEY key) {

    int index = hash_function(key);
    LinkedList<T_KEY, T_VALUE> &ll = table[index];
    bool key_exists = false;

    for (Iterator<T_KEY, T_VALUE> ptr_node = ll.begin(); *ptr_node != nullptr; ptr_node++) {
        if ((*ptr_node)->get_data().first == key) {
            key_exists = true;
            ll.remove(*ptr_node);
            break;
        }
    }

    if (!key_exists) {
        cout << "[WARNING] Key not found." << endl;
    }

}

template<typename T_KEY, typename T_VALUE>
T_VALUE HashTable<T_KEY, T_VALUE>::get(T_KEY key) {

    int index = hash_function(key);
    LinkedList<T_KEY, T_VALUE> &ll = table[index];

    for (Iterator<T_KEY, T_VALUE> ptr_node = ll.begin(); *ptr_node != nullptr; ptr_node++) {
        if ((*ptr_node)->get_data().first == key) {
            return (*ptr_node)->get_data().second;
        }
    }

    cout << "[WARNING] Key not found." << endl;
    return T_VALUE();

}

template<typename T_KEY, typename T_VALUE>
void HashTable<T_KEY, T_VALUE>::print_table() {

    for (int i=0; i<hash_buckets; i++) {
        LinkedList<T_KEY, T_VALUE> &ll = table[i];
        if (!ll.get_size()) continue;
        ll.print_list();
    }

}

#endif