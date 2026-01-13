// intlist.cpp
// Implements class IntList
// Tanuj Siripurapu, 1/12/2026

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head = nullptr;
    tail = nullptr;
    
    if (source.head == nullptr) {
        return; // source is empty
    }
    
    // copy first node
    head = new Node{source.head->info, nullptr};
    tail = head;
    
    // copy remaining nodes
    Node* curr = source.head->next;
    while (curr) {
        Node* newNode = new Node{curr->info, nullptr};
        tail->next = newNode;
        tail = newNode;
        curr = curr->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* curr = head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
}


// return sum of values in list
int IntList::sum() const {
    int total = 0;
    Node* curr = head;
    while (curr) {
        total += curr->info;
        curr = curr->next;
    }
    return total;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr = head;
    while (curr) {
        if (value == curr->info) {
            return true;
        }
        curr = curr->next;
    }
    return false; 
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (head == nullptr) {
        return 0;
    }
    Node* curr = head;
    int max = curr->info;
    curr = curr->next; 

    while (curr) {
        if (curr->info > max) {
            max = curr->info;
        }
        curr = curr->next;
    }

    return max; 
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    double total = 0;
    double len = 0;
    Node* curr = head;
    while (curr) {
        total += curr->info;
        len++;
        curr = curr->next;
    }

    if (len > 0) {
        return total / len;
    } else {
        return 0.0;
    }
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newHead = new Node{value, head};
    head = newHead;
    if (tail == nullptr) {
        tail = newHead;
    }
}

// append value at end of list
void IntList::push_back(int value) {
    Node* newTail = new Node{value, nullptr};
    if (tail == nullptr) {
        // empty list
        head = newTail;
        tail = newTail;
    } else {
        tail->next = newTail;
        tail = newTail;
    }
}

// return count of values
int IntList::count() const {
   int len = 0;
   Node* curr = head;
   while (curr) {
        len++;
        curr = curr->next;
   }
   return len;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source) {
        return *this;
    }

    // delete existing nodes
    Node* curr = head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    // copy from source
    head = nullptr;
    tail = nullptr;
    
    if (source.head == nullptr) {
        return *this; // source is empty
    }
    
    // copy first node
    head = new Node{source.head->info, nullptr};
    tail = head;
    
    // copy remaining nodes
    curr = source.head->next;
    while (curr) {
        Node* newNode = new Node{curr->info, nullptr};
        tail->next = newNode;
        tail = newNode;
        curr = curr->next;
    }

    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = 0;
    tail = 0;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

