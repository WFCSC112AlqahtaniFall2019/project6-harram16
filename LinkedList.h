//
// Created by Addie Harrison on 10/29/19.
//
#ifndef BINARYINSERTIONSORT_LINKEDLIST_H
#define BINARYINSERTIONSORT_LINKEDLIST_H
#include <iostream>
#include "Node.h"
using namespace std;

class LinkedList{
public:
    LinkedList();
    LinkedList (const LinkedList &list);
    ~LinkedList();
    void append(int item);
   // bool remove(int item); 
    LinkedList &operator=(const LinkedList &rhs);
    void printList() const;
    void InsertionSort();

private:
    Node* head; // start of the list
};

#endif //BINARYINSERTIONSORT_LINKEDLIST_H
