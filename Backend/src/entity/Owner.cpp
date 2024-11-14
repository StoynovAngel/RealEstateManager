#include "Owner.h"
#include <iostream>
#include <cstring>

Owner::Owner(string name, string egn, string address) : User(name, egn, address), propertyCounter(0){
    for(int i = 0; i < 5; i++){
        adr[i] = nullptr;
    }
}

Owner::~Owner(){
    for(int i = 0; i < propertyCounter; i++){
        delete[] adr[i];
    }
}

void Owner::addProperty(const string& property) {
    if (propertyCounter < 5) {
        adr[propertyCounter] = new char[property.length() + 1];
        strcpy(adr[propertyCounter], property.c_str());
        ++propertyCounter;
    } else {
        cout << "Maximum number of properties reached." << endl;
    }
}

void Owner::displayProperties() const {
    cout << "Properties owned by " << getName() << ":" << endl;
    for (int i = 0; i < propertyCounter; ++i) {
        cout << "- " << adr[i] << endl;
    }
}

ostream& operator<<(ostream& os, const Owner& owner) {
    os << static_cast<const User&>(owner);
    os << "Properties:\n";
    if (owner.propertyCounter == 0) {
        os << "- No properties owned\n";
    } else {
        for (int i = 0; i < owner.propertyCounter; ++i) {
            os << "- " << owner.adr[i] << "\n";
        }
    }
    return os;
}