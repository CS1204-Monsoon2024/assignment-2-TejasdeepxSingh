#include "HashTable.h"

// Helper function to check if a number is prime
bool HashTable::is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Helper function to find the next prime number larger than n
int HashTable::next_prime(int n) {
    while (!is_prime(n)) {
        n++;
    }
    return n;
}

// Hash function
int HashTable::hash_function(int key) const {
    return key % table_size;
}

// Resizes the table when the load factor exceeds the threshold
void HashTable::resize_table() {
    int old_size = table_size;
    table_size = next_prime(table_size * 2);

    std::vector<int> old_table = table;
    std::vector<bool> old_is_occupied = is_occupied;

    table.clear();
    table.resize(table_size, -1);
    is_occupied.clear();
    is_occupied.resize(table_size, false);
    current_size = 0;

    for (int i = 0; i < old_size; ++i) {
        if (old_is_occupied[i]) {
            insert(old_table[i]);
        }
    }
}

// Constructor
HashTable::HashTable(int initial_size) {
    table_size = next_prime(initial_size);
    table.resize(table_size, -1);
    is_occupied.resize(table_size, false);
    current_size = 0;
}

// Insert a key into the hash table
void HashTable::insert(int key) {
    if (current_size >= load_factor_threshold * table_size) {
        resize_table();
    }

    int index = hash_function(key);
    int original_index = index;
    int i = 0;

    while (is_occupied[index]) {
        if (table[index] == key) {
            std::cout << "Duplicate key insertion is not allowed" << std::endl;
            return;
        }
        i++;
        index = (original_index + i * i) % table_size;
        if (i >= table_size) {
            std::cout << "Max probing limit reached!" << std::endl;
            return;
        }
    }

    table[index] = key;
    is_occupied[index] = true;
    current_size++;
}

// Remove a key from the hash table
void HashTable::remove(int key) {
    int index = hash_function(key);
    int original_index = index;
    int i = 0;

    while (is_occupied[index]) {
        if (table[index] == key) {
            table[index] = -1;
            is_occupied[index] = false;
            current_size--;
            return;
        }
        i++;
        index = (original_index + i * i) % table_size;
        if (i >= table_size) {
            break;
        }
    }
    std::cout << "Element not found" << std::endl;
}

// Search for a key in the hash table and return the index
int HashTable::search(int key) {
    int index = hash_function(key);
    int original_index = index;
    int i = 0;

    while (is_occupied[index]) {
        if (table[index] == key) {
            return index;
        }
        i++;
        index = (original_index + i * i) % table_size;
        if (i >= table_size) {
            break;
        }
    }
    return -1;
}

// Print the hash table
void HashTable::print_table() {
    for (int i = 0; i < table_size; i++) {
        if (is_occupied[i]) {
            std::cout << table[i] << " ";
        } else {
            std::cout << "- ";
        }
    }
    std::cout << std::endl;
}
