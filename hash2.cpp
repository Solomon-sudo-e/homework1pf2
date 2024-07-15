#include "hash2.h"
#include "doubly_linked_list.h"
//-----------------------------------------------------------
// Constructor
//-----------------------------------------------------------
HashTable::HashTable(int size)
{
    Size = size * 4;
    table = new doubly_linked_list[Size];

    collision_counter = 0;
}

//-----------------------------------------------------------
// Copy constructor
//-----------------------------------------------------------
HashTable::HashTable(const HashTable & ht)
{
    Size = ht.Size;
    table = new doubly_linked_list[Size];

    for (int index = 0; index < Size; index++)
    {
        table[index] = ht.table[index];
    }
    collision_counter = ht.collision_counter;
}

//-----------------------------------------------------------
// Destructor
//-----------------------------------------------------------
HashTable::~HashTable()
{
    int i = 0;
    while(i < Size) {
        doubly_linked_list temp = table[i];
        while(temp.getHead() != nullptr) {
            Node *head = temp.getHead();
            Node *temporary = head;
            temp.setHead(head->getNext());
            delete temporary;
        }
    }
    delete[] table;
}

//-----------------------------------------------------------
// Insert method
//-----------------------------------------------------------
bool HashTable::Insert(Node *dog)
{
    // Find desired key
    int index = Hash(dog->getBreed());
    if(!table[index].isEmpty()) {
        collision_counter++;
    }

    table[index].insertSorted(dog);
    return true;
}

//-----------------------------------------------------------
// Search method
//-----------------------------------------------------------
bool HashTable::Search(string breed, string &name)
{
    // Find desired key
    int index = Hash(breed);
    Node* node = table[index].getHead();
    while(node != nullptr) {
        if(node->getBreed() == breed) {
            name = node->getName();
            return true;
        }
        node = node->getNext();
    }
    return false;
}

//-----------------------------------------------------------
// Delete method
//-----------------------------------------------------------
bool HashTable::Delete(string breed, string name)
{
    // Find desired key
    int index = Hash(breed);
    Node* node = table[index].getHead();

    while(node != nullptr) {
        if(node->getBreed() == breed) {
            if(node->getName() == name) {
                table[index].deleteNode(node);
                return true;
            } else {
                node = node->getNext();
            }
        } else {
            node = node->getNext();
        }
    }
    return false;
}

//-----------------------------------------------------------
// Primary hash function
//-----------------------------------------------------------
int HashTable::Hash(string key)
{
    long int num = 42;
    for (int i = 0; i < int(key.length()); i++)
        num = (num * 17 + key[i]) % Size;
    return num;
}

//-----------------------------------------------------------
// Secondary hash function
//-----------------------------------------------------------
int HashTable::Hash2(string key)
{
    unsigned long hash = 5381;
    int c;
    const char* str = key.c_str();

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % Size;
}

int HashTable::Hash3(string key) {
    unsigned long hash = 0;
    int c;
    const char* str = key.c_str();

    while ((c = *str++))
        hash = c + (hash << 6) + (hash << 16) - hash;

    return hash % Size;
}

//-----------------------------------------------------------
// Print function for debugging
//-----------------------------------------------------------
void HashTable::Print()
{
    for (int index = 0; index < Size; index++) {
        if (!table[index].isEmpty()) {
            table[index].printList();
        }
    }
}

void HashTable::print_collision() {
    cout << "Number of collisions: " << collision_counter << endl;
}

void HashTable::read_file() {
    ifstream infile;
    infile.open("dogs.txt");
    string line;
    string read_name, read_age, read_breed, read_sizeInPounds, read_amountOfEnergy;
    while(!infile.eof()) {
        getline(infile, read_name, ',');
        getline(infile, read_age, ',');
        getline(infile, read_breed, ',');
        getline(infile, read_sizeInPounds, ',');
        getline(infile, read_amountOfEnergy, '\n');

        try {
            Node *node;
            node->setName(read_name);
            node->setAge(stod(read_age));
            node->setBreed(read_breed);
            node->setSize(stod(read_sizeInPounds));
            node->setEnergy(stod(read_amountOfEnergy));
            Insert(node);
        }
        catch(exception e) {
            cout << "It seems there may have been a error in the file. We apologize for the inconvenience!";
        }

    }
    infile.close();
    Print();
}
