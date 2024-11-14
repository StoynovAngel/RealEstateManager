#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cctype>

void FileHandler::saveToFile(const vector<Owner>& owners){
    ofstream outFile("owners.txt");
    if (!outFile) {
        cerr << "Error: Could not open file for writing: " << endl;
        return;
    }

    for(const auto& owner: owners){
        outFile << owner;
    }
    outFile.close();
    cout << "Data saved successfully" << endl;
}


void FileHandler::loadFromFile(vector<Owner>& owners) {
    ifstream inFile("owners.txt");
    if (!inFile) {
        cerr << "Error: Could not open file for reading." << endl;
        return;
    }

    owners.clear();

    string line, name, egn, address;
    int propertyCount = 0;

    while (getline(inFile, line)) {
        // Read "Name: "
        if (line.find("Name: ") == 0) {
            name = line.substr(6);  // Extract the name after "Name: "
            cout << "Loaded Name: " << name << endl;

            // Read the next line for "Egn: "
            getline(inFile, line);
            if (line.find("Egn: ") == 0) {
                egn = line.substr(5);  // Extract the EGN after "Egn: "
                egn.erase(remove_if(egn.begin(), egn.end(), ::isspace), egn.end()); // Trim whitespace
                cout << "Loaded EGN (after trimming): '" << egn << "'" << endl;
            }

            // Read the next line for "Address: "
            getline(inFile, line);
            if (line.find("Address: ") == 0) {
                address = line.substr(9);  // Extract the address after "Address: "
                cout << "Loaded Address: " << address << endl;
            }

            // Read the next line for "Properties:"
            getline(inFile, line);
            if (line == "Properties:") {
                Owner owner(name, egn, address);

                // Now read each property line starting with "- "
                while (getline(inFile, line) && line.find("- ") == 0) {
                    string property = line.substr(2);  // Extract property after "- "
                    cout << "Loaded Property: " << property << endl;
                    owner.addProperty(property);
                    propertyCount++;
                }

                owners.push_back(owner);
            }
        }
    }
    inFile.close();
}