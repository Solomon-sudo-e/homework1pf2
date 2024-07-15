//
// Created by Solomon's PC on 7/12/2024.
//

#include "Node.h"
Node::Node(): name("na"), age(0), breed("na"), size(0), amount_of_energy(0), next(nullptr), previous(nullptr) {}

Node::Node(const string &nname, const double &nage, const string &nbreed, const double &nsize, const double &namount_of_energy)
    : name(nname), age(nage), breed(nbreed), size(nsize), amount_of_energy(namount_of_energy), next(nullptr), previous(nullptr) {}
Node::~Node() {
}
Node* Node::getNext() {
    return next;
}
Node* Node::getPrevious() {
    return previous;
}
string Node::getName() {
    return name;
}
double Node::getAge() {
    return age;
}
string Node::getBreed() {
    return breed;
}
double Node::getSize() {
    return size;
}
double Node::getEnergy() {
    return amount_of_energy;
}
void Node::setNext(Node *new_next) {
    next = new_next;
}
void Node::setPrevious(Node *new_previous) {
    previous = new_previous;
}
void Node::setName(string nname) {
    name = nname;
}
void Node::setAge(double nage) {
    age = nage;
}
void Node::setBreed(string nbreed) {
    breed = nbreed;
}
void Node::setSize(double nsize) {
    size = nsize;
}
void Node::setEnergy(double nenergy) {
    amount_of_energy = nenergy;
}

