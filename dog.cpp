//
// Created by Solomon Hufford on 5/29/24.
//

#include "dog.h"
dog::dog() {
    name = "none";
    age = 0.0;
    breed = "none";
    sizeInPounds = 0.0;
    amountOfEnergy = 0;
}

dog::dog(string new_name, double new_age, string new_breed, double new_sizeInPounds, int new_amountOfEnergy) {
    name = new_name;
    age = new_age;
    breed = new_breed;
    sizeInPounds = new_sizeInPounds;
    amountOfEnergy = new_amountOfEnergy;
}

dog::dog(const dog &doggo) {
    name = doggo.name;
    age = doggo.age;
    breed = doggo.breed;
    sizeInPounds = doggo.sizeInPounds;
    amountOfEnergy = doggo.amountOfEnergy;
}

dog::~dog() = default;

string dog::getName() {
    return name;
}

void dog::setName(string new_name) {
    name = new_name;
}

double dog::getAge() {
    return age;
}

void dog::setAge(double new_age) {
    age = new_age;
}

string dog::getBreed() {
    return breed;
}

void dog::setBreed(string new_breed) {
    breed = new_breed;
}

double dog::getSizeInPounds() {
    return sizeInPounds;
}

void dog::setSizeInPounds(double new_sizeInPounds) {
    sizeInPounds = new_sizeInPounds;
}

int dog::getAmountOfEnergy() {
    return amountOfEnergy;
}

void dog::setAmountOfEnergy(int new_amountOfEnergy) {
    amountOfEnergy = new_amountOfEnergy;
}

void dog::Print() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Breed: " << breed << endl;
    cout << "Size In Pounds: " << sizeInPounds << endl;
    cout << "Amount of Energy: " << amountOfEnergy << endl;
    cout << endl;
}

Daycare::Daycare() {
    dog doggy;
    for(int i = 0; i < MAX_DOGS; i++){
        Dogs[i] = doggy;
    }
}

Daycare::Daycare(dog new_Dog[]) {
    for(int i = 0; i < MAX_DOGS; i++) {
        Dogs[i] = new_Dog[i];
    }
}

Daycare::Daycare(const Daycare &daycare) {
    cout << "Copy constuctor" << endl;


    for(int i = 0; i < MAX_DOGS; i++) {
        Dogs[i] = daycare.Dogs[i];
    }
}

Daycare::~Daycare() = default;

void Daycare::setDaycare(dog Dog[]) {
    for(int i = 0; i < MAX_DOGS; i++) {
        Dogs[i] = Dog[i];
    }
}

void Daycare::add_dog() {
    cout << "Please tell me the name, age, breed, size (in pounds), and amount of energy (out of 10)" << endl;
    string new_name, new_breed;
    double new_age, new_sizeInPounds;
    int new_amountOfEnergy;
    cin >> new_name >> new_age >> new_breed >> new_sizeInPounds >> new_amountOfEnergy;

    dog Dog(new_name, new_age, new_breed, new_sizeInPounds, new_amountOfEnergy);

    for(int i = 0; i < MAX_DOGS; i++) {
        if(Dogs[i].getName() == "none") {
            Dogs[i] = Dog;
            return;
        }
    }
}

void Daycare::remove_dog(string check_name) {
    int label[MAX_DOGS];
    int count = 0;
    for(int i = 0; i < MAX_DOGS; i++) {
        if(check_name == Dogs[i].getName()) {
            label[count] = i;
            count++;
        }
    }
    if(count > 1) {
        cout << "There is multiple dogs with the same name, which breed is your dog?" << endl;
        cout << "These are the dogs with the same name: " << endl;
        for(int i = 0; i < count; i++) {
            Dogs[label[i]].Print();
        }
        cout << "Which breed is yours?";
        string breed;
        cin >> breed;
        for(int i = 0; i < count; i++){
            if (Dogs[label[i]].getBreed() == breed) {
                dog del_dog;
                Dogs[label[i]] = del_dog;
            }
        }
    } else if (count == 1) {
        dog del_dog;
        Dogs[label[0]] = del_dog;
    } else {
        cout << "There was no dog with that name";
    }
}

void Daycare::compare_dogs(int energy) {
    cout << "Let me check if there is any dogs similar to this energy level!" << endl;
    int energy_count = 0;
    for(int i = 0; i < MAX_DOGS; i++){
        if((Dogs[i].getAmountOfEnergy() == energy)
        || (Dogs[i].getAmountOfEnergy() == energy-1)
        || (Dogs[i].getAmountOfEnergy() == energy + 1)) {
            cout << Dogs[i].getName() << " has an energy level of: " << Dogs[i].getAmountOfEnergy() << endl;
            energy_count++;
        }
    }
    cout << endl;
    if(energy_count == 0) {
        cout << "There are no dogs of matching energy level yet, but more will probably enroll in daycare soon" << endl;
    }
}

int Daycare::call_menu() {
    cout << "Please select an option to do to the doggy daycare: " << endl;
    cout << "1) Load dogs from a file." << endl;
    cout << "2) Enroll a new dog into daycare." << endl;
    cout << "3) Find a dog with the same energy level." << endl;
    cout << "4) Show all dogs." << endl;
    cout << "5) Move the dogs into a new array." << endl;
    cout << "6) Close menu and save daycare to a file." << endl;
    int option;
    cin >> option;
    if((option == 1) || (option == 2) || (option == 3) || (option == 4) || (option == 5) || (option == 6)) {
        return option;
    } else
        call_menu();
}

void Daycare::print_all() {
    int i = 0;
    while(i < MAX_DOGS) {
        if(Dogs[i].getName() == "none") {
            i = 20;
        } else {
            Dogs[i].Print();
        }
        i++;
    }
}

void Daycare::read_dogs() {
    ifstream infile;
    infile.open("dogs.txt");
    string line;
    string read_name, read_age, read_breed, read_sizeInPounds, read_amountOfEnergy;
    int i = 0;
    while(!infile.eof()) {
        getline(infile, read_name, ',');
        getline(infile, read_age, ',');
        getline(infile, read_breed, ',');
        getline(infile, read_sizeInPounds, ',');
        getline(infile, read_amountOfEnergy, '\n');

        dog doggy;
        doggy.setName(read_name);

//        dog doggy(read_name, stod(read_age),
//                  read_breed, stod(read_sizeInPounds),
//                  stoi(read_amountOfEnergy));
        doggy.setAge(stod(read_age));
        doggy.setBreed(read_breed);
        doggy.setSizeInPounds(stod(read_sizeInPounds));
        doggy.setAmountOfEnergy(stoi(read_amountOfEnergy));
        Dogs[i] = doggy;
        i++;
        doggy.Print();
    }

    infile.close();
}

void Daycare::save() {
    ofstream outfile("dogs.txt");
    if(outfile.is_open()) {
        for(int i = 0; i < MAX_DOGS; i++) {
            if(Dogs[i].getName() == "none") {
                return;
            } else {
                outfile << Dogs[i].getName() << ", ";
                outfile << Dogs[i].getAge() << ", ";
                outfile << Dogs[i].getBreed() << ", ";
                outfile << Dogs[i].getSizeInPounds() << ", ";
                outfile << Dogs[i].getAmountOfEnergy() << "\n";
            }
        }
        outfile.close();
    }
}
