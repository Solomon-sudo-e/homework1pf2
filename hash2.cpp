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
            node *head = temp.getHead();
            node *temporary = head;
            temp.setHead(head->getNext());
            delete temporary;
        }
    }
    delete[] table;
}

//-----------------------------------------------------------
// Insert method
//-----------------------------------------------------------
bool HashTable::Insert(node *dog)
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
bool HashTable::Search(string key, int &value)
{
    // Find desired key
    int index = Hash(key);
    while ((Key[index] != key) && (Key[index] != EMPTY))
        index = Hash2(index);

    // Return value from hash table
    if (Key[index] == key)
        value = Value[index];
    return (Key[index] == key);
}

//-----------------------------------------------------------
// Delete method
//-----------------------------------------------------------
bool HashTable::Delete(string key)
{
    // Find desired key
    int index = Hash(key);
    while ((Key[index] != key) && (Key[index] != EMPTY))
        index = Hash2(index);

    // Delete value from hash table
    if (Key[index] == key)
    {
        Value[index] = NONE;
        Key[index] = DELETED;
        return true;
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
int HashTable::Hash2(int index)
{
    // cout << "collision\n";
    return (index + 1) % Size;
}

//-----------------------------------------------------------
// Print function for debugging
//-----------------------------------------------------------
void HashTable::Print()
{
    for (int index = 0; index < Size; index++)
        if (Value[index] > 0)
            cout << Value[index] << "\t" << Key[index] << "\n";
}

//-----------------------------------------------------------
// Print function for debugging
//-----------------------------------------------------------
void HashTable::Print(ofstream & dout)
{
    for (int index = 0; index < Size; index++)
        if (Value[index] > 0)
            dout << Value[index] << "\t" << Key[index] << "\n";
}
