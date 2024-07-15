//
// Created by Solomon's PC on 7/12/2024.
//
#include "node.h"
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
    node *copyNodes(node* copied_node);
    void insertSorted(node *sort_node);
    bool remove(const string &name, const string &breed);
    node *getHead();
    void setHead(node *head_node);
private:
    node *head;
};


#endif //DOGS_DOUBLY_LINKED_LIST_H
