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
}
LinkedList:: LinkedList(const LinkedList &list){
    cout<<"Copy constructor called."<<endl;
    Node* current;

    if(list.head== nullptr){//if empty setting the head of copied to nullptr
        head= nullptr;
    }
    else{
        head=new Node(list.head->value);//setting the head value to the head of copied linked list
        current=head;
        Node* copy;//creating a new node to put in the copied linked list
        copy=list.head;

        //loops through a while loop until hit end of linked list values to copy
        while(copy!=nullptr){
            current->next=new Node(current->next->value);
            current=current->next;
            copy=copy->next;

        }
    }
}
LinkedList :: ~LinkedList(){
    cout<<"LinkedList Destructor called."<<endl;
    delete head;

}

LinkedList &LinkedList:: operator=(const LinkedList &copyList){
    cout<<"Copy Assignment called."<<endl;

    LinkedList temp(copyList);

    swap(temp.head, head);

    return *this;
}
void LinkedList:: append(int item) {
    if (head->value==0) {
        head->value = item;
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
//do not need a remove function for insertion sort
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


void LinkedList::InsertionSort()//insertion sort function
{
    Node* current = new Node();// current to store head
    current -> next = head;
    Node* right = head -> next; //looks at next node
    Node* left = head; //is the next to the left aka the right of the left node
    Node* location;//saves loc where valInFront points to if in wrong order

    //only enters if node exists
    while(right != nullptr){
        location = current ;

        //while loop runs until sorted
        while((location -> next -> value) < (right -> value))
            location = location -> next;

            //if in correct order move to next node, next both
            if(left -> value <= right -> value){
                left = right;
                right = right -> next;
            }
            //if not in correct order switches the pointer
            else{//occurs if in wrong order
                // insert lead in the spot determined by location
                left -> next = right -> next;
                right -> next = location -> next;
                location -> next = right;
                right = left -> next;
                }
            }
    head = current -> next;//temp head becomes first value in list; delete temp head
    current -> next = nullptr;//setting head node to nullptr
    delete current;//deleting node at end
}

