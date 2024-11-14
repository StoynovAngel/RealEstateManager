#ifndef OWNER_H
#define OWNER_H

#include "User.h"
#include <string>
#include <ostream>

using namespace std;

class Owner : public User{
    private:
        int propertyCounter;
        char *adr[5];
    public:
        Owner(string name, string egn, string address);
        ~Owner();
        Owner(const Owner& other);
        void addProperty(const string& property);
        void displayProperties() const;
        friend std::ostream& operator<<(std::ostream& os, const Owner& owner);
        void displayMatchingInfo() const;
        int getPropertyCounter() const;
        const char* getProperty(int index) const;

};

#endif