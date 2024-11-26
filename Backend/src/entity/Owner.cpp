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

Owner::Owner(const Owner& other) : User(other), propertyCounter(other.propertyCounter){
    for(int i = 0; i < propertyCounter; ++i){
        if(other.adr[i]){
            adr[i] = new char[strlen(other.adr[i])+1];
            strcpy(adr[i], other.adr[i]);
        }else{
            adr[i] = nullptr;
        }
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

int Owner::getPropertyCounter() const {
    return propertyCounter;
}

const char* Owner::getProperty(int index) const {
    if (index >= 0 && index < propertyCounter) {
        return adr[index];
    }
    return nullptr;
}