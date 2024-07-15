//
// Created by Solomon's PC on 7/12/2024.
//
#include "Node.h"
#include <string>
#include <iostream>
#ifndef DOGS_DOUBLY_LINKED_LIST_H
#define DOGS_DOUBLY_LINKED_LIST_H

using namespace std;
class doubly_linked_list {
public:
    doubly_linked_list();
    doubly_linked_list(const doubly_linked_list &copy_list);
    ~doubly_linked_list();
    bool isEmpty();
    Node *getHead();
    Node *copyNodes(Node* copied_node);
    void insertSorted(Node *sort_node);
    void deleteNode(Node* node);
    void setHead(Node *head_node);
    void printList();
private:
    Node *head;
    Node *tail;
};


#endif //DOGS_DOUBLY_LINKED_LIST_H
