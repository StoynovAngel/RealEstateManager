#ifndef PROPERTYMANAGER_H
#define PROPERTYMANAGER_H

#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
#include "Owner.h"
#include "FileHandler.h"
#include "Validation.h"

using namespace std;

class PropertyManager {
private:
    vector<Owner> owners;

public:
    void addOwner(const Owner& owner);
    void displayMatchingAddressOwners();
    void displayPropertiesByEgn();
    vector<Owner>& getOwners();
};

#endif
