#ifndef NODE_H
#define NODE_H

class Node {
public:
    // Node constructor
    Node(int v = 0, Node* n = nullptr)
    {
        value = v;
        next = n;
    }
    //Destructor for Node
    ~Node(){
        cout<<"Node Destructor Called."<<endl;
        delete next;
        }

    //making LinkList a "friend" of Node class
    friend class LinkedList;

private:
    int value;
    Node* next;

};



#endif //NODE_H
