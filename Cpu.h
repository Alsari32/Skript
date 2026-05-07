#ifndef CPU_H
#define CPU_H

#include <string>
#include "Memory.h"

class Cpu {
private:
    std::string accumulator;
    Memory* memory;  // CPU now holds pointer to Memory

public:
    Cpu(Memory* mem);
    void load(int index);           // loads from memory[index] into accumulator
    void store(int index);          // stores accumulator into memory[index]
    std::string getAccumulator();   // returns accumulator value
    void setAccumulator(std::string value); // sets accumulator directly

    std::string add(int indexA, int indexB);
    std::string addFloat(int indexA, int indexB);
    
    std::string subtract(int indexA, int indexB);
    std::string subtractFloat(int indexA, int indexB);
    
    std::string multiply(int indexA, int indexB);
    std::string multiplyFloat(int indexA, int indexB);
    
    std::string divide(int indexA, int indexB);
    std::string divideFloat(int indexA, int indexB);
    
    bool compare(int indexA, int indexB, std::string op);
    bool compareFloat(int indexA, int indexB,std::string op);
};

#endif
