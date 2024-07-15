#include <iostream>
#include <fstream>
#include <string>
#include "hash2.h"
using namespace std;

int main() {
    HashTable table(250000);
    table.read_file();

    return 0;
}

