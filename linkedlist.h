/*********************
Name: Darren Bowers
Coding 05
Purpose: Introduction to Linked Lists
**********************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "data.h" 

using std::cout;
using std::endl;

class LinkedList {

public:
    LinkedList();
    ~LinkedList();
    bool addNode(int, string*);
    bool deleteNode(int);
    bool getNode(int, Data*);
    void printList(bool = false);
    int getCount();
    bool clearList();
    bool exists(int);


private:
    Node *head;







};

#endif //LINKED_LIST_H