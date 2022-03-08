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

void LinkedList::fillNode(int id, string* info, Node* newNode){
    newNode->data.id = id;
    newNode->data.data = *info;
}

void LinkedList::addHead(int id, string* info, Node* current){
    Node *newNode = new Node;
    fillNode(id, info, newNode);
    if(current == NULL){
        newNode->prev = NULL;
        newNode->next = NULL;
    }else{
        newNode->prev = NULL;
        newNode->next = current;
        current->prev = newNode;
    }
    head = newNode;
}

void LinkedList::addTail(int id, string* info, Node* current){
    Node *newNode = new Node;
    fillNode(id, info, newNode);
    newNode->prev = current;
    newNode->next = NULL;
    current->next = newNode;
}

void LinkedList::addMiddle(int id, string* info, Node* current){
    Node *newNode = new Node;
    fillNode(id, info, newNode);
    newNode->prev = current;
    newNode->next = current->next;
    current->next->prev = newNode;
    current->next = newNode;
}


/*********************************
PUBLIC
*********************************/

bool LinkedList::addNode(int id, string* info){
    bool success = false;
    if((id > 0) && (info->length() > 0)){
        if(head == NULL || (id < head->data.id)){ //New Head
            addHead(id, info, head);
            success = true; 
        }else{
            Node *current = head;
            while(current->next != NULL && id > current->next->data.id){
                current = current->next;
            }if(current->next == NULL && id > current->data.id){ // New Tail
                addTail(id, info, current);
                success = true; 
            }else if(id > current->data.id && id < current->next->data.id){ // New Middle
                addMiddle(id, info, current);
                success = true;
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
    Node *current = head;
    int i = 1;
    if(head != NULL && !direction){ //forward
        cout << i << ": " <<current->data.id << " : " << current->data.data << endl;
        i++;
        while(current = current->next){
            cout << i << ": " <<current->data.id << " : " << current->data.data << endl;
            i++;
        }
    }else if(head != NULL){ //backward
        while(current->next){
            current = current->next;
        }
        cout << i << ": " << current->data.id << " : " << current->data.data << endl;
        i++;
        while(current = current->prev){
           cout << i << ": " <<current->data.id << " : " << current->data.data << endl;
            i++;
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
