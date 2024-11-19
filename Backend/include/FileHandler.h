#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <vector>
#include "Owner.h"
#include <filesystem>

using namespace std;

class FileHandler{
    public:
        static void saveToFile(const vector<Owner>& owners);  
        static void loadFromFile(vector<Owner>& owners);  
};

#endif