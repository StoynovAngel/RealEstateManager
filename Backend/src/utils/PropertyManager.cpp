#include "PropertyManager.h"

void PropertyManager::addOwner(const Owner& owner) {
    owners.push_back(owner);
}

void PropertyManager::displayMatchingAddressOwners() const {
    bool matchFound = false;
    for (const auto& owner : owners) {
        for (int i = 0; i < owner.getPropertyCounter(); ++i) {
            if (owner.getProperty(i) != nullptr && strcmp(owner.getProperty(i), owner.getAddress().c_str()) == 0) {
                cout << "Match found for Owner:\n";
                cout << owner; 
                matchFound = true;
                break; 
            }
        }
    }
    if (!matchFound) {
        cout << "No owners with matching property addresses found.\n";
    }
}

void PropertyManager::displayPropertiesByEgn(const string& egn) const {
    bool ownerFound = false;
    for (const auto& owner : owners) {
        if (owner.getEgn() == egn) {
            owner.displayProperties(); 
            ownerFound = true;
            break;
        }
    }
    if (!ownerFound) {
        cout << "No owner found with EGN: " << egn << endl;
    }
}