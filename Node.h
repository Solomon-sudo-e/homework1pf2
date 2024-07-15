//
// Created by Solomon's PC on 7/12/2024.
//

#ifndef DOGS_NODE_H
#define DOGS_NODE_H
#include <string>

using namespace std;
class Node {
public:
    Node();
    Node(const string &nname, const double &nage, const string &nbreed, const double &nsize, const double &namount_of_energy);
    ~Node();
    Node* getNext();
    Node* getPrevious();
    string getName();
    double getAge();
    string getBreed();
    double getSize();
    double getEnergy();
    void setNext(Node *new_next);
    void setPrevious(Node *new_previous);
    void setName(string nname);
    void setAge(double nage);
    void setBreed(string nbreed);
    void setSize(double nsize);
    void setEnergy(double nenergy);
private:
    string name;
    int age;
    string breed;
    int size;
    int amount_of_energy;
    Node* next;
    Node* previous;
};


#endif //DOGS_NODE_H
