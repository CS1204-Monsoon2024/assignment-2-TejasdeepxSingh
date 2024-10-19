#include "HashTable.cpp"
#include <iostream>

int main() {
    int initialSize = 7; 
    HashTable ht(initialSize);

    // Example test cases
    ht.insert(1);
    ht.printTable();
    
    ht.insert(6);
    ht.printTable();
    
    ht.insert(15);
    ht.printTable();
    
    ht.insert(25);
    ht.printTable();
    
    ht.remove(15);
    ht.printTable();
    
    ht.insert(29);  
    ht.printTable(); 

    int find = ht.search(25);
    if (find != -1) {
        std::cout << "Element found at index: " << find << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}
