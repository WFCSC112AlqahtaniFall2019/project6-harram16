#include <iostream>
#include <vector>
#include <cassert>
#include "BinaryInsertionSort.h"
#include "LinkedList.h"

using namespace std;

int main() {

    int seed, length;
    cout<<"Enter a seed and then a length: "<<endl;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);
    LinkedList l;

    // generate linked list of random integers created above
    // generate vector of random integers
    for (int i = 0; i < v.size(); i++) {
        v[i] = rand() % 100;
        int a=v[i];
        l.append(a);
    }

    // print out UN-sorted list
    cout<<"UN-Sorted list before vector binary insertion sort: "<<endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;

    }


    clock_t start_insertionSortVector = clock();
    // binary insertion sort on vector
    insertionSort(v, v.size());
    clock_t end_insertionSortVector = clock();


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


    //printing UN-sorted linked list
    cout<<"UN-Sorted list before linked list binary insertion sort: "<<endl;
    l.printList();


    clock_t start_LinkedInsertionSort = clock();
    //binary insertion sort on linked list
    l.InsertionSort();
    clock_t end_LinkedInsertionSort = clock();


    // print out sorted list
    cout<<"Sorted list from linked list binary insertion sort: "<<endl;
    l.printList();


    // print elapsed time for vector and linkedlist insertion sort
    double elapsed_insertionSortVector = double(end_insertionSortVector - start_insertionSortVector) / CLOCKS_PER_SEC;
    double elapsed_LinkedInsertionSort = double(end_LinkedInsertionSort - start_LinkedInsertionSort) / CLOCKS_PER_SEC;

    cout <<"Elapsed Time for vector using insertion sort: "<< elapsed_insertionSortVector << "  Elapsed Time for linked list using insertion sort: "<< elapsed_LinkedInsertionSort << endl;

}