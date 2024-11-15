#include "PropertyManager.h"

void PropertyManager::addOwner(const Owner& owner) {
    owners.push_back(owner);
}

void PropertyManager::displayMatchingAddressOwners() {
    FileHandler::loadFromFile(owners);

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

    bool found = false;
    for (const auto& owner : owners) {
        if (owner.getEgn() == egn) {
            cout << "Properties owned by " << owner.getName() << ":\n";
            owner.displayProperties();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No owner found with EGN: " << egn << endl;
    }
}

vector<Owner>& PropertyManager::getOwners(){
    return owners;
}
