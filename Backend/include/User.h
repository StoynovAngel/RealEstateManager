#ifndef USER_H
#define USER_H

#include <string>
#include <ostream>

using namespace std;

class User{
    private:
        string name;
        string egn;
        string address;
    public:
        User(string name, string egn, string address);
        string getName() const;
        string getEgn() const;
        string getAddress() const;
        void setName(string name);
        void setEgn(string egn);
        void setAddress(string address);
        friend ostream& operator<<(ostream& os, const User& user);
};

#endif