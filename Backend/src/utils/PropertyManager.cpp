#include "PropertyManager.h"

using namespace std;

void PropertyManager::addOwner() {
    owners.push_back(addOwnerHandler());
    FileHandler::saveToFile(owners);
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

void PropertyManager::displayPropertiesByEgn() {
    FileHandler::loadFromFile(owners);
    string egn;
    cout << "Enter egn: ";
    cin >> egn;
    if(!Validation::isEgnCorrect(egn)) throw invalid_argument("Incorrect egn. It must be 10 letters");
    bool found = false;
    for (const auto& owner : owners) {
        if (owner.getEgn() == egn) {
            cout << "\nProperties owned by " << owner.getName() << "\n";
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

Owner PropertyManager::addOwnerHandler(){
    string name, egn, address, properties;
    int counter = 0;

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter address: ";
    getline(cin, address); 

    cout << "Enter egn: ";
    cin >> egn; 

    if (!Validation::isEgnCorrect(egn)) {
        throw invalid_argument("Incorrect egn. It must be 10 digits.");
    }

    cin.ignore();
    Owner owner(name, egn, address);

    while (counter < 5) {
        cout << "Enter property name (type 'done' to exit): ";
        getline(cin, properties);
        if (properties == "done") break;
        owner.addProperty(properties);
        ++counter;
    }
    return owner;
}