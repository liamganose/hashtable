#include <hash_table.hpp>
#include <string>
#include <iostream>

using namespace std;

// This is just an example custom data object to test the code and make sure templating was successful
struct Person {
    string name;
    int age;

    Person() : name(""), age(0) {}
    Person(string set_name, int set_age) : name(set_name), age(set_age) {}

    // overloaded the stream operator to get a nicer output
    // fustratingly can't define this in the main function so I do it
    // in here and make it a friend
    friend ostream& operator<<(ostream& os, Person ts) {
        if (ts.name != "" || ts.age != 0) {
            os << "Name: " << ts.name << " Age: " << ts.age;
        } else {
            os << "Empty Person object.";
        }
        return os;
    }
};

int main() {

    HashTable<string, Person> ht;

    Person liam("Liam", 24);
    Person bob("Bob", 54);

    ht.insert("liam", liam);
    ht.insert("bob", bob);
    cout << ht.get("liam") << endl;
    cout << ht.get("121021312") << endl;
    cout << ht.get("121432") << endl;

    ht.print_table();

}