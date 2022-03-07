/*********************
Name: Darren Bowers
Coding 05
Purpose: Introduction to Linked Lists
**********************/

#include "linkedlist.h"


LinkedList::LinkedList(){
    head = NULL; 
}

LinkedList::~LinkedList(){
    Node *current = head;
    while(current != NULL){
        Node *next = current->next;
        delete current;
        current = next; 
    }
    head = NULL; 
}

bool LinkedList::addNode(int id, string* info){
    return true;
}

bool LinkedList::deleteNode(int id){
    return true;
}

bool LinkedList::getNode(int id, Data* returnBox){
    return true;
}

void LinkedList::printList(bool direction){
    if(head != NULL){
        int i = 1;
        Node *current = head;
        while(current != NULL){
            cout << i << ": " <<current->data.id << " : " << current->data.data << endl;
            i++;
            current = current->next;
        }
    }else{
        cout << "List is empty" << endl;
    }

}

int LinkedList::getCount(){
    return 0;
}

bool LinkedList::clearList(){
    return true;
}

bool LinkedList::exists(int id){
    return true;
}
