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

    void createNode(int, string*, Node*);
    void addHead(int, string*, Node*);
    void addTail(int, string*, Node*);
    void addMiddle(int, string*, Node*);





};

#endif //LINKED_LIST_H