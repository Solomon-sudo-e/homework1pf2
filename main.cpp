#include <iostream>
#include <fstream>
#include <string>
#include "dog.h"
using namespace std;

void handle_case_5(Daycare daycares) {
    Daycare new_daycare = daycares;
    new_daycare.print_all();
}

int main() {
    ifstream infile;
    string line;

    while(true) {
        dog menu;
        Daycare daycare;
        int option = daycare.call_menu();

        switch(option){
            case 1:
                daycare.read_dogs();
                break;
            case 2:
                daycare.add_dog();
                break;
            case 3:
                cout << "What energy level are you looking for?" << endl;
                int energy;
                cin >> energy;
                daycare.compare_dogs(energy);
                break;
            case 4:
                daycare.print_all();
                break;
            case 5:
                handle_case_5(daycare);
                break;
            case 6:
                return false;
            default:
                break;
        }
    }
}
/*
 * 1. Problem Statement:
The objective of this programming assignment is to bring together several key programming
concepts (file input/output, arrays, and classes) to build an interactive program for storing
information about a doggy daycare. Students must read an ascii file called dogs.txt which
contains five pieces of information, separated by commas:
• dog name
• age
• breed
• size, in pounds
• amount of energy, rated from 1-10
If you look at the dogs.txt file, you will notice that the dog name and breed are strings that
could have multiple tokens, and age, size, and amount of energy are numeric values. The
two string fields could have a variable number of words, so you will need to use an
overloaded method of getline() that uses a delimiter that will split on ‘,’ in each line of the
file to get each individual field.
Specifically, your task is to design, implement, and test a “Dog” class that stores the
information above in an object-oriented data structure.
2. Design:
Your first design task is to decide what data types and initial values are appropriate for all of
the data fields in the Dog class. Once you have this worked out, it should be
straightforward to design and implement a no-argument constructor, parameterized
constructor, copy constructor, destructor, the get and set methods, and the print method
to output all of the data in an object. You are welcome to add more methods to this class
as needed.
Once the Dog class has been implemented, your second task is to create a main program
that contains a doggy daycare client array of a maximum of 20 Dog objects, and allows the
user to use a text-based menu to do the following possible things:
• load dogs from an ascii file
• enroll a new dog into daycare by prompting the user for the appropriate fields
CSCE 2014 Programming Foundations II Summer 2024
University of Arkansas, Fayetteville
• prompt the user to for energy level of their dog, then loop over the array of
daycare clients to find other dogs that are close to their dog’s energy for possible
playmates (+/-1 for a match; if the user inputs 8, your search should return dogs
with an energy level of 7, 8, or 9). If none are found, print a message to the user
saying that there are no dogs of matching energy level yet, but more will probably
enroll in daycare soon
• print out information for all dogs currently enrolled
• create a new Daycare array that copies the current clients and prints the dog
information from this copied array (this will use your Dog copy constructor)
• quit the program, and save the array back into the ascii file
Finally, you need to create an ASCII text file that contains information about at least FOUR
daycare clients. Feel free to use “Fido”, “Fluffy”, “Rover”, and “Sir Fluffington the Second”,
or your own pets’ names to start! ☺
 */
