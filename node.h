//
// Created by Solomon's PC on 7/12/2024.
//

#ifndef DOGS_NODE_H
#define DOGS_NODE_H
#include <string>

using namespace std;
class node {
public:
    node();
    node(const string &nname, const int &nage, const string &nbreed, const int &nsize, const int &namount_of_energy);
    ~node();
    node* getNext();
    node* getPrevious();
    string getName();
    int getAge();
    string getBreed();
    int getSize();
    int getEnergy();
    void setNext(node *new_next);
    void setPrevious(node *new_previous);
    void setName(string nname);
    void setAge(int nage);
    void setBreed(string nbreed);
    void setSize(int nsize);
    void setEnergy(int nenergy);
private:
    string name;
    int age;
    string breed;
    int size;
    int amount_of_energy;
    node* next;
    node* previous;
};


#endif //DOGS_NODE_H
