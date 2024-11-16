#ifndef PROPERTYMANAGER_H
#define PROPERTYMANAGER_H

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
#include "Owner.h"
#include "FileHandler.h"
#include "Validation.h"

using namespace std;

class PropertyManager {
private:
    vector<Owner> owners;

public:
    void addOwner();
    Owner addOwnerHandler();
    void displayMatchingAddressOwners();
    void displayPropertiesByEgn();
    vector<Owner>& getOwners();
};

#endif
