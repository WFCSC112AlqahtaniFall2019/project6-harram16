//
// Created by Addie Harrison on 10/29/19.
//
#include <iostream>
using namespace std;
#include "LinkedList.h"
//big three copy constructor, copy assignment, and destructor
LinkedList::LinkedList() {
    cout<<"Constructor called."<<endl;
    head=new Node;
    *head=0;
}
LinkedList:: LinkedList(const LinkedList &list){
    cout<<"Copy constructor called."<<endl;
    Node* current;

    if(list.head== nullptr){//if empty setting the head of copied to nullptr
        head= nullptr;
    }
    else{
        head= new Node(list.head->value);//setting the head value to the head of copied linked list
        current=head;
        Node* copy=current;//creating a new node to put in the copied linked list

        //loops through a while loop until hit end of linked list values to copy
        while(copy!=nullptr){
            current->next=new Node(copy->next->value);
            copy=copy->next;

        }
    }
}
LinkedList :: ~LinkedList(){
    cout<<"LinkedList Destructor called."<<endl;
    Node* current=head;
    Node* next;
    while(current!= nullptr){
        next=current->next;
        delete current;
        current=next;
    }
}

LinkedList &LinkedList:: operator=(const LinkedList &copyList){
    cout<<"Copy Assignment called."<<endl;
    Node* current;

    LinkedList temp(copyList);

    swap(temp.head, head);

    return *this;
}
void LinkedList:: append(int item) {
    if (head == nullptr) {
        head = new Node(item);
    }
    else{
        Node *cursor = head;
        while(cursor->next!=nullptr){
            cursor=cursor->next;
        }
        cursor->next=new Node(item);
    }
}
void LinkedList:: printList() const {
    Node *cursor = head;
    if(cursor==nullptr){
        cout << "empty list" << endl;
    }
    else{
        while (cursor != nullptr) {
            cout << cursor->value << endl;
            cursor = cursor->next;
        }
    }
}
/*bool LinkedList :: remove( int item ) {
      Node * current = head ; 
    Node * previous=head; 
    if(head == nullptr) {
        return false; //case1
    }
    if(head -> value == item ){ // case 2 
        head = head -> next; 
        current -> next = nullptr; // de - link! 
        delete current ; // then delete 
        return true; 
    }  
    while ( current ){ 
        if( current -> value== item ){ // case 3 
            previous -> next = current -> next ; 
            current -> next = nullptr; // de - link! 
            delete current ; // then delete 
            return true; 
        } 
        previous = current ; 
        current = current -> next ; 
    } 
    return false ; // case 4 
}*/

void LinkedList:: InsertionSort(){
    Node* current;
    Node* prev;

    //case1 if list is empty it returns
    if(head==nullptr){
        // does nothing because no sorting necessary if there are no nodes
    }
    //case 2 if list only has head
    else if(head->next== nullptr){

        //does nothing because no sorting is necessary if only one node
    }
    else {
        //case 3 if list is longer than just 1 node
        Node* end;
        Node* middle=head;
        Node* left;
        Node* right=current->next;

        int counter = 0;//counts the length of the linkedlist
        current = head;//starting current pointer at head
        //determining the number of values in the linked list
        while (current != nullptr) {
            if(right->value>middle->value){
                left=middle;
                middle=left;
               right=middle->next;
            }
            else{

            }

        }
        current = head;
        int i=1;
        while (i<counter) {
            prev = current;
            for (int i = 0; i < counter; i++) {
                if (prev->value > current->value) {
                    swap(prev->value, current->value);
                }
                prev = current;
                current = current->next;

            }

        }
    }
}

