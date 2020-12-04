#include <iostream>

#include "helpers.hpp"

void print_ascii(std::string value) {
    for (char& ch : value) {
        std::cout << (int)ch << " ";
    }
    std::cout << std::endl;
}