//
//  DoubleLinkedList.hpp
//  project2
//
//  Created by Michael Olubode on 10/9/23.
//

#ifndef DoubleLinkedList_hpp
#define DoubleLinkedList_hpp

#include <stdio.h>

class DoubleLinkedList {
private:
    struct Node{
        int value;
        struct Node* next;
        struct Node* prev;
    };
    Node* head;
    Node* tail;
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void appendNode(int num);
    void insertNode(int num);
    void deleteNode(int num);
    void displayList() const;
    void assignment();
    void clear();
    void printTable() const;
};

#endif /* DoubleLinkedList_hpp */
