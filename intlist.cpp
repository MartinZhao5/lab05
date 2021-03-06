// intlist.cpp
// Implements class IntList
// Ziheng Zhao 2018/11/3

#include "intlist.h"

#include <iostream>
using std::cout;

// return sum of values in list
int IntList::sum() const {
    int sum =0;
      Node *n = first;
      while (n) {
         sum+=n->info;
         n = n->next;
}
	return sum;
 // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node *n= first;
    while (n){
      if (value==n->info)
	return true;
      n=n->next;
} 
    return false;  // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
     if (first==0)
	return 0;
else{
    Node *n= first;
    int max = n->info;
    while (n){
	if (max<n->info)
	max= n->info;
	n=n->next;
}
	return max; // REPLACE THIS NON-SOLUTION
   } 
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (first==0)
	return 0;
 else{ double sum=0;
       double count=0;
 Node *n = first;
      while (n) {
         sum+=n->info;
	count++;
         n = n->next;
}
 return sum/count;
}
	 // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    // IMPLEMENT
    Node *list=new Node;
	list->info=value;
	list->next=first;
	first=list;
}

// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }

// destructor deletes all nodes
IntList::~IntList() {
    Node *n = first;
    while (n) {
        Node *garbage = n;
        n = n->next;
        delete garbage;
    }
}

// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
