#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>

class HashTable {
private:
    std::vector<int> table;
    std::vector<bool> is_occupied;
    int current_size;
    int table_size;
    const double load_factor_threshold = 0.8;

    // Helper functions
    bool is_prime(int n);
    int next_prime(int n);
    int hash_function(int key) const;
    void resize_table();

public:
    HashTable(int initial_size);
    void insert(int key);
    void remove(int key);
    int search(int key);
    void print_table();
};

#endif
