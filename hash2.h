#ifndef HASH_H
#define HASH_H
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "doubly_linked_list.h"
using namespace std;
const int NONE = 0;
const string EMPTY = "-1";
const string DELETED = "-2";

//-----------------------------------------------------------
// Define the HashTable class interface
//-----------------------------------------------------------
class HashTable
{
public:
    // Constructors
    HashTable(int size);
    HashTable(const HashTable & ht);
    ~HashTable();

    // Methods
    bool Insert(node *dog);
    bool Search(string key, int &value);
    bool Delete(string key);
    void Print();
    void Print(ofstream & dout);
    void print_collision();

private:
    // Private methods
    int Hash(string key);
    int Hash2(string key);
    int Hash3(string key);

    // Private data
    int Size;
    doubly_linked_list *table;
    int collision_counter;
};

#endif