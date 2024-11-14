#include <iostream>
#include "User.h"

int main() {
    try {
        // Creating a User with a valid EGN
        User user1("John Doe", "1234567890", "123 Main St");
        std::cout << "User created successfully:\n";
        std::cout << user1;

        // Attempt to create a User with an invalid EGN (less than 10 characters)
        User user2("Jane Smith", "12345", "456 Elm St");
        std::cout << "User created successfully:\n";
        std::cout << user2;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}