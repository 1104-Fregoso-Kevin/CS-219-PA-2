#include <iostream>
#include <string>
#include "Operations.h"  
#include "Read.h"

int main() {
    std::string filename = "programming_project_2.txt";
    Read PA2;
    PA2.readFromFile(filename);
    return 0;
}