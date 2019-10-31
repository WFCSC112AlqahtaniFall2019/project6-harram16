#include <iostream>
#include <vector>
#include <cassert>
#include "BinaryInsertionSort.h"
#include "Node.h"
#include "LinkedList.h"

using namespace std;

int main() {

    int seed, length;
    cout<<"Enter a seed and then a length: "<<endl;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);

    // generate vector of random integers
    for (int i = 0; i < v.size(); i++) {
        v[i] = rand() % 100;
    }

    // print out UN-sorted list
    cout<<"UN-Sorted list before vector binary insertion sort: "<<endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

    // binary insertion sort
    insertionSort(v, v.size());

    // check if sorted
    for (int i = 1; i < v.size(); i++) {
        assert(v[i-1] <= v[i]);
    }

    // print out sorted list
    cout<<"Sorted list from vector binary insertion sort: "<<endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

    // FINISH ME
    LinkedList l;
    // generate linked list of random integers created above
    for (int i = 0; i < v.size(); i++) {
        v[i] = rand() % 100;
        int a=i;
        l.append(a);
    }

    //printing UN-sorted linked list
    cout<<"UN-Sorted list before linked list binary insertion sort: "<<endl;
    l.printList();

    //binary insertion sort on linked list
    l.InsertionSort();

    // print out sorted list
    cout<<"Sorted list from linked list binary insertion sort: "<<endl;
    l.printList();

}