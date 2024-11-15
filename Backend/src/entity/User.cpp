#include "User.h"
#include "Validation.h"
#include <algorithm>

User::User(string name, string egn, string address){
    if(!Validation::isEgnCorrect(egn)){
        throw invalid_argument("Invalid egn. It should be 10 letters.");
    }
    this->name = name;
    this->address = address;
    this->egn = egn;
}

string User::getName() const{
    return name;
}

string User::getEgn() const{
    return egn;
}

string User::getAddress() const{
    return address;
}

void User::setName(string name){
    this->name = name;
}

void User::setEgn(string egn){
    egn.erase(std::remove_if(egn.begin(), egn.end(), ::isspace), egn.end());
    this->egn = egn;
}

void User::setAddress(string address){
    this->address = address;
}

ostream& operator<<(ostream& os, const User& user){
    os << "Name: " << user.getName() << "\nAddress: " << user.getAddress()  << "\nEgn: " << user.getEgn() << std::endl;
    return os;
}

