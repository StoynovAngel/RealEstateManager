#ifndef PROPERTYMANAGER_H
#define PROPERTYMANAGER_H

#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
#include "Owner.h"

using namespace std;

class PropertyManager {
private:
    vector<Owner> owners;

public:
    void addOwner(const Owner& owner);
    void displayMatchingAddressOwners() const;
    void displayPropertiesByEgn(const string& egn) const;
};

#endif
