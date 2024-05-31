//
// Created by Solomon Hufford on 5/29/24.
//

#ifndef DOGS_DOG_H
#define DOGS_DOG_H
#include<iostream>
#include<fstream>

using namespace std;
static const int MAX_DOGS = 20;
class dog {

public:
    dog();
    dog(string name, double age, string breed, double sizeInPounds, int amountOfEnergy);
    dog(const dog &doggo);
    ~dog();
    string getName();
    void setName(string name);
    double getAge();
    void setAge(double age);
    string getBreed();
    void setBreed(string breed);
    double getSizeInPounds();
    void setSizeInPounds(double sizeInPounds);
    int getAmountOfEnergy();
    void setAmountOfEnergy(int amountOfEnergy);
    void Print();
private:
    string name;
    double age;
    string breed;
    double sizeInPounds;
    int amountOfEnergy;
};

class Daycare {
public:
    Daycare();
    Daycare(dog new_Dog[]);
    Daycare(const Daycare &daycare);
    ~Daycare();
    void setDaycare(dog Dog[]);
    void add_dog();
    void remove_dog(string check_name);
    void compare_dogs(int energy);
    int call_menu();
    void print_all();
    void read_dogs();
    void save();

private:
    dog Dogs[MAX_DOGS];
};


#endif //DOGS_DOG_H
