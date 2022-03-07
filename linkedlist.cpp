/*********************
Name: Darren Bowers
Coding 05
Purpose: Introduction to Linked Lists
**********************/

#include "linkedlist.h"


/*********************************
CONSTRUCTORS / DESTRUCTORS
*********************************/

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

/*********************************
PRIVATE
*********************************/




/*********************************
PUBLIC
*********************************/

bool LinkedList::addNode(int id, string* info){
    bool success = false;
    if((id > 0) && (info->length() > 0)){
        if(head == NULL){
            Node *newNode = new Node;
            newNode->data.id = id;
            newNode->data.data = *info; 
            head = newNode;
            newNode->prev = NULL;
            newNode->next = NULL;
            success = true; 
        }else{
            if(id < head->data.id){
                Node *newNode = new Node;
                newNode->data.id = id;
                newNode->data.data = *info; 
                newNode->prev = NULL;
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }
    }

    return success;
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
        while(current != NULL){ // TEST IF != is necessary
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
