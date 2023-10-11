//
//  main.cpp
//  project2
//
//  Created by Michael Olubode on 10/9/23.
//

#include <iostream>
#include "DoubleLinkedList.hpp"
using namespace std;


int main() {
    DoubleLinkedList list;
    list.appendNode(11);
    list.appendNode(22);
    list.appendNode(33);
    list.appendNode(44);
    list.appendNode(55);
    
    list.assignment();
    list.displayList();
    list.printTable();
    
    return 0;
}
