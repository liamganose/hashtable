# Basic hash table implementatio

## Info
 - created my own linked list class to use in it, not necessary but helped re-learn pointers (for the 3rd time) 
 - everything is templated so all sits in header files 
    - looked at using e.g. HashTable<pair<int, string>> TempObj; etc to instantiate all template types in the cpp file
    - ... but I wanted it to be any type pairing and didnt want to write every combination down 
 - main.cpp has an example of how it works with a random struct as the data in the table
 - made on windows using MSYS2 compiler so idk if it will port to other OS. Assume it would

## Todo
 - would be good to add some tests to see how they work
 - create my own hash function
 - add a way to auto change the hash_buckets size and array size
   - could be similar to how python dicts work where if (total elements / hash_buckets) >= 2/3 -> double hash_buckets
