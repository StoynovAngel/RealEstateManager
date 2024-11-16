#ifndef MENU_H
#define MENU_H

#include "PropertyManager.h"
using namespace std;

class Menu {
    private:
        PropertyManager propertyManager;

    public:
        void showMenu() {
            cout << endl;
            cout << "1. Display all owners that share property with their personal address\n";
            cout << "2. Get specific owners by their identification number\n";
            cout << "3. Add owner\n";
            cout << "0. Stop\n";
        }
        void menuHandler(){
            int choice;
            do{
                showMenu();
                cout << "\nEnter choice: "; 
                cin >> choice;
                switch (choice){
                    case 1: propertyManager.displayMatchingAddressOwners(); break;
                    case 2: propertyManager.displayPropertiesByEgn(); break;
                    case 3: propertyManager.addOwner(); break;
                    case 0: cout << "Stopping...\n"; break;
                    default: cout << "Invalid choice try again.\n"; break;
                }
            }while(choice != 0);
        }


};

#endif