//
// Created by Solomon's PC on 7/12/2024.
//

#include "node.h"
node::node(): name("na"), age(0), breed("na"), size(0), amount_of_energy(0), next(nullptr), previous(nullptr) {}

node::node(const string &nname, const int &nage, const string &nbreed, const int &nsize, const int &namount_of_energy)
    : name(nname), age(nage), breed(nbreed), size(nsize), amount_of_energy(namount_of_energy), next(nullptr), previous(nullptr) {}
node::~node() {
}
node* node::getNext() {
    return next;
}
node* node::getPrevious() {
    return previous;
}
string node::getName() {
    return name;
}
int node::getAge() {
    return age;
}
string node::getBreed() {
    return breed;
}
int node::getSize() {
    return size;
}
int node::getEnergy() {
    return amount_of_energy;
}
void node::setNext(node *new_next) {
    next = new_next;
}
void node::setPrevious(node *new_previous) {
    previous = new_previous;
}
void node::setName(string nname) {
    name = nname;
}
void node::setAge(int nage) {
    age = nage;
}
void node::setBreed(string nbreed) {
    breed = nbreed;
}
void node::setSize(int nsize) {
    size = nsize;
}
void node::setEnergy(int nenergy) {
    amount_of_energy = nenergy;
}

