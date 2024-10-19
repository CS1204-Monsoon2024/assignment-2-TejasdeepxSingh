#include <iostream>

const int P = 31;  // Prime for polynomial hashing
const int M = 1e9 + 9;  // Large prime number for modulus

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    long long hashValue;  // Hash value for fast equivalence check
    long long currentPowerP;  // Store the current power of P
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), hashValue(0), currentPowerP(1), size(0) {}

    // Insert at the end of the list
    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        // Update the hash value using the current power of P
        hashValue = (hashValue + data * currentPowerP) % M;

        // Update the current power of P for the next insertion
        currentPowerP = (currentPowerP * P) % M;
        size++;
    }

    // Delete an element from the front of the list
    void deleteFront() {
        if (head == nullptr) return;  // Empty list, nothing to delete

        // Update the hash value by removing the contribution of the head's data
        hashValue = (hashValue - head->data + M) % M;

        // Move the head pointer to the next node
        Node* temp = head;
        head = head->next;
        delete temp;

        // Recalculate the currentPowerP for the new size (decrease by one power)
        currentPowerP = (currentPowerP * modInverse(P, M)) % M;  // Adjust current power back by dividing by P
        size--;
    }

    // Function to compute the modular inverse of P modulo M
    long long modInverse(long long base, long long mod) {
        return power(base, mod - 2, mod);  // Fermat's Little Theorem: P^(M-2) mod M is the modular inverse of P mod M
    }

    // Power function using exponentiation by squaring
    long long power(int base, int exp, int mod) {
        long long result = 1;
        long long b = base;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * b) % mod;
            }
            b = (b * b) % mod;
            exp /= 2;
        }
        return result;
    }

    // Get the hash value of the list
    long long getHash() const {
        return hashValue;
    }

    // Compare two linked lists for equivalence
    bool isEquivalent(LinkedList& other) {
        return this->hashValue == other.getHash();
    }
};


int main() {
    LinkedList list1;
    LinkedList list2;

    list1.insert(10);
    list1.insert(201);
    list1.insert(3);
    list1.insert(108);
    list1.insert(1099);
    list1.insert(10567);
    list1.insert(75858);
        

    list2.insert(10);
    list2.insert(201);
    list2.insert(3);
    list2.insert(108);
    list2.insert(1099);
    list2.insert(10567);
    list2.insert(75858);

    // Fast equivalence check
    if (list1.isEquivalent(list2)) {
        std::cout << "Lists are equivalent\n";
    } else {
        std::cout << "Lists are not equivalent\n";
    }

    return 0;
}
