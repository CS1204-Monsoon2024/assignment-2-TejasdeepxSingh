#include "HashTable.h"

int main() {
    int initialSize = 7; 
    HashTable ht(initialSize);

    // Example test case
    ht.insert(1);
    ht.print_table();
    ht.insert(6);
    ht.print_table();
    ht.insert(15);
    ht.print_table(); 
    ht.insert(25);
    ht.print_table();
    ht.remove(15);
    ht.print_table();
    ht.insert(29);  
    ht.print_table(); 

    int find = ht.search(22);
    std::cout << "Found at: " << find << std::endl;

    return 0;
}
