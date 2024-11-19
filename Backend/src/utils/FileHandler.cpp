#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cctype>

namespace fs = std::filesystem;
const fs::path directory = "files";
const fs::path filePath = directory / "owners.txt";

void FileHandler::saveToFile(const vector<Owner>& owners){
    if (!fs::exists(directory)) {
        fs::create_directory(directory);
    }
    ofstream outFile(filePath, ios::app);
    if (!outFile) {
        cerr << "Error: Could not open file for writing: " << endl;
        return;
    }

    for(const auto& owner: owners){
        outFile << owner;
    }
    outFile.close();
    
}


void FileHandler::loadFromFile(vector<Owner>& owners) {
    ifstream inFile(filePath);
    if (!inFile) {
        cerr << "Error: Could not open file for reading." << endl;
        return;
    }

    owners.clear();

    string line, name, egn, address;
    vector<string> properties;

    while (getline(inFile, line)) {
        if (line.find("Name: ") == 0) {
            if (!name.empty()) {
                Owner owner(name, egn, address);
                for (const auto& property : properties) {
                    owner.addProperty(property);
                }
                owners.push_back(owner);
                name.clear();
                egn.clear();
                address.clear();
                properties.clear();
            }          
            name = line.substr(6);  

        } else if (line.find("Address: ") == 0) {
            address = line.substr(9);     
        } else if (line.find("Egn: ") == 0) {
            egn = line.substr(5);  
            egn.erase(remove_if(egn.begin(), egn.end(), ::isspace), egn.end());           
        } else if (line == "Properties:") {
            properties.clear();
        } else if (line.find("- ") == 0) {
            string property = line.substr(2);         
            properties.push_back(property);
        }
    }
    
    if (!name.empty()) {
        Owner owner(name, egn, address);
        for (const auto& property : properties) {
            owner.addProperty(property);
        }
        owners.push_back(owner);
    }
    inFile.close();
    
}
