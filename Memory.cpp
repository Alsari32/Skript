#include "Memory.h"

Memory::Memory()
{
}

void Memory::store(int index, std::string value) {
    memory[index] = value;
}

std::string Memory::load(int index) {
    return memory[index];
}



