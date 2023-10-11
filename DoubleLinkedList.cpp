//
//  DoubleLinkedList.cpp
//  project2
//
//  Created by Michael Olubode on 10/9/23.
//

#include "DoubleLinkedList.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

DoubleLinkedList::DoubleLinkedList() {
    head = nullptr;
    tail = nullptr;
};

DoubleLinkedList::~DoubleLinkedList( ) {
    clear();
};

void DoubleLinkedList::appendNode(int num) {
    Node *newNode;
    newNode = new Node;
    newNode->value = num;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (!head) {
        head = newNode;
        tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        tail = head->prev;
        tail->next = newNode;
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
    }
}

void DoubleLinkedList::insertNode(int num) {
    Node* newNode = new Node;
    newNode->value = num;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    
    if (!head) {
        head = newNode;
        tail = newNode;
    } 
    else if (num <= head->value) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } 
    else if (num >= tail->value) {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    } 
    else {
        Node* nodePtr = head;
        while (nodePtr && nodePtr->value < num) {
            nodePtr = nodePtr->next;
        }

        newNode->next = nodePtr;
        newNode->prev = nodePtr->prev;
        nodePtr->prev->next = newNode;
        nodePtr->prev = newNode;
    }
}


void DoubleLinkedList::deleteNode(int num) {
    Node* nodePtr = head;
    Node* prevPtr = nullptr;
    
    if(!head) {
        cout << "\nNothing to delete!\n";
        return;
    }
    
    while(nodePtr && nodePtr->value != num) {
        prevPtr = nodePtr;
        nodePtr = nodePtr->next;
    }
    
    if(nodePtr) {
        if(nodePtr == head) {
            head = nodePtr->next;
            if(head) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
        }
        else {
            prevPtr->next = nodePtr->next;
            if(nodePtr->next) {
                nodePtr->next->prev = prevPtr;
            }
            else {
                tail = prevPtr;
            }
        }
        delete nodePtr;
    }
}


void DoubleLinkedList::displayList() const {
    Node* nodePtr;
    nodePtr = head;
    while(nodePtr) {
        cout << nodePtr->value << endl;
        nodePtr = nodePtr->next;
        if(nodePtr == head) {
            break;
        }
    }
    
}

void DoubleLinkedList::clear() {
    if (!head) {
        return;
    }
    Node* current = head;
    Node* nextNode;
    
    while (current) {
        nextNode = current->next;
        delete current;
        current = nextNode;
        
        if (current == head) {
            head = nullptr;
            tail = nullptr;
            break;
        }
    }
}


void DoubleLinkedList::assignment() {
    if(!head) {
        return;
    }
    head->next->next->next = head->prev;
    head->prev->prev->prev = head->next->next->next->prev;
    head->next->next->next->prev = head->prev->prev->prev;
    head->next = head->next->next;
    head->next->prev->next = head->next->next->next;
}


void DoubleLinkedList::printTable() const {
    if (head != nullptr) {
        Node* current = head;
        
        int columnWidth = 20;

        cout << setw(30) << "1st node" << setw(columnWidth) << "2nd node" << setw(columnWidth) << "3rd node" << setw(columnWidth) << "4th node" << setw(columnWidth+4) << "5th node" << endl;
        cout << setfill('+') << setw(30 + 4 * columnWidth+5) << "+" << setfill(' ') << endl;
        
        cout << "Node Value";
        for (int i = 0; i < 5; i++) {
            cout << setw(columnWidth) << current->value;
            current = current->next;
        }
        cout << endl;
        
        cout << setfill('+') << setw(30 + 4 * columnWidth+5) << "+" << setfill(' ') << endl;
        current = head;
        
        cout << "Value of Previous node:";
        for (int i = 0; i < 5; i++) {
            cout << setw(columnWidth-4) << current->prev->value;
            current = current->next;
        }
        cout << endl;
        
        cout << setfill('+') << setw(30 + 4 * columnWidth+5) << "+" << setfill(' ') << endl;
        current = head;
        
        cout << "Value of Next node:";
        for (int i = 0; i < 5; i++) {
            cout << setw(columnWidth-4) << current->next->value;
            current = current->next;
        }
        cout << endl;
        
        cout << setfill('+') << setw(30 + 4 * columnWidth+5) << "+" << setfill(' ') << endl;
    }
}
