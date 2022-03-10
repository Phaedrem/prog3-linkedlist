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
    clearList(); 
}

/*********************************
PRIVATE
*********************************/

void LinkedList::findId(int id, Node** currentBox){
    Node* current = head;
    while(id != current->data.id && current->next != NULL){
        current = current->next;
    }
    *currentBox = current;
}

void LinkedList::fillNode(int id, string* info, Node** nodeBox){
    Node *newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *info;
    *nodeBox = newNode;
}

void LinkedList::addHead(int id, string* info, Node* current, Node* &nodeBox){
    fillNode(id, info, &nodeBox);
    if(current == NULL){
        nodeBox->prev = NULL;
        nodeBox->next = NULL;
    }else{
        nodeBox->prev = NULL;
        nodeBox->next = current;
        current->prev = nodeBox;
    }
    head = nodeBox;
}

void LinkedList::addTail(int id, string* info, Node* current, Node* &nodeBox){
    fillNode(id, info, &nodeBox);
    nodeBox->prev = current;
    nodeBox->next = NULL;
    current->next = nodeBox;
}

void LinkedList::addMiddle(int id, string* info, Node* current, Node* &nodeBox){
    fillNode(id, info, &nodeBox);
    nodeBox->prev = current->prev;
    nodeBox->next = current;
    current->prev->next = nodeBox;
    current->prev = nodeBox;
}


/*********************************
PUBLIC
*********************************/

bool LinkedList::addNode(int id, string* info){
    bool success = false;
    if((id > 0) && (info->length() > 0)){
        Node **nodeBox;
        if(head == NULL || (id < head->data.id)){ //New Head
            addHead(id, info, head, *nodeBox);
            success = true; 
        }else{
            Node *current = head;
            while(id > current->data.id && current->next != NULL){
                current = current->next;
            }
            if(id > current->data.id && current->next == NULL){ // New Tail
                addTail(id, info, current,*nodeBox);
                success = true; 
            }else if(id < current->data.id){ // New Middle
                addMiddle(id, info, current,*nodeBox);
                success = true;
            }
        }
    }
    return success;
}
 
bool LinkedList::deleteNode(int id){ 
    bool success = false;
    if(head != NULL){
        Node *current;
        findId(id, &current);
        if(id == current->data.id && current->prev == NULL && current->next == NULL){ // if theres only one node
            head = NULL;
            delete current;
            success = true;
        }else if(id == current->data.id && current->prev == NULL){ // if node is the head
            current->next->prev = NULL;
            head = current->next;
            delete current;
            success = true;
        }else if(id == current->data.id && current->next == NULL){ // if node is the tail
            current->prev->next = NULL;
            delete current;
            success = true;
        }else if(id == current->data.id){ // if node is in the middle
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            success = true;
        }// if node doesn't exist
    }
    return success;
}

bool LinkedList::getNode(int id, Data* returnBox){
    bool success = false;
    if(head != NULL){
        Node *current;
        findId(id, &current);
        if(id == current->data.id){
            returnBox->data = current->data.data;
            returnBox->id = current->data.id;
            success = true;
        }else{
            returnBox->data = "";
            returnBox->id = -1;
        }
    }
    return success;
}

void LinkedList::printList(bool direction){
    Node *current = head;
    int currentCount = PRINTSTART;
    if(head != NULL && !direction){ //forward
        while(current){
            cout << currentCount << ": " <<current->data.id << " : " << current->data.data << endl;
            currentCount++;
            current = current->next;
        }
    }else if(head != NULL){ //backward
        while(current->next){
            current = current->next;
        }
        while(current){
           cout << currentCount << ": " <<current->data.id << " : " << current->data.data << endl;
            currentCount++;
            current = current->prev;
        }
    }else{
        cout << "List is empty" << endl;
    }
}

int LinkedList::getCount(){
    int nodeCount = COUNTSTART;
    if(head != NULL){
        nodeCount++;
        Node *current = head;
        while(current = current->next){
            nodeCount++;
        }
    }
    return nodeCount;
}

bool LinkedList::clearList(){
    bool success = false;
    if(head != NULL){
        Node *current = head;
        while(current != NULL){
            head = current->next;
            delete current;
            current = head; 
        }
        head = NULL;
        success = true;
    }
    return success;
}

bool LinkedList::exists(int id){
    bool exists = false;
    if(head != NULL){
        Node *current;
        findId(id, &current);
        if(id == current->data.id){
            exists = true;
        }
    }
    return exists;
}
