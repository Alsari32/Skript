#include "inPut.h"


void inPut::display(std::string message) {
    std::cout << message << "\n";
}

std::string inPut::getInt(std::string name) {
    int value;
    std::cout << "Enter int value for " << name << ": ";
    std::cin >> value;
    return std::to_string(value);
}

std::string inPut::getFloat(std::string name) {
    float value;
    std::cout << "Enter float value for " << name << ": ";
    std::cin >> value;
    return std::to_string(value);
}
