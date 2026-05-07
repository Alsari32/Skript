#include "Cpu.h"

Cpu::Cpu(Memory* mem) {
    memory = mem;
    accumulator = "0";
}

void Cpu::load(int index) {
    accumulator = memory->load(index);
}

void Cpu::store(int index) {
    memory->store(index, accumulator);//points to store in memory and sends index and accumlator
}

std::string Cpu::getAccumulator() {
    return accumulator;
}

void Cpu::setAccumulator(std::string value) {
    accumulator = value;
}

std::string Cpu::add(int indexA, int indexB) {
    int a = std::stoi(memory->load(indexA));
    int b = std::stoi(memory->load(indexB));
    accumulator = std::to_string(a + b);
    return accumulator;
}

std::string Cpu::addFloat(int indexA, int indexB)
{
    float a = std::stof(memory->load(indexA));
    float b = std::stof(memory->load(indexB));
    accumulator = std::to_string(a + b);
    return accumulator;
}

std::string Cpu::subtract(int indexA, int indexB) {
    int a = std::stoi(memory->load(indexA));
    int b = std::stoi(memory->load(indexB));
    accumulator = std::to_string(a - b);
    return accumulator;
}

std::string Cpu::subtractFloat(int indexA, int indexB)
{
    float a = std::stof(memory->load(indexA));
    float b = std::stof(memory->load(indexB));
    accumulator = std::to_string(a - b);
    return accumulator;
}

std::string Cpu::multiply(int indexA, int indexB) {
    int a = std::stoi(memory->load(indexA));
    int b = std::stoi(memory->load(indexB));
    accumulator = std::to_string(a * b);
    return accumulator;
}

std::string Cpu::multiplyFloat(int indexA, int indexB)
{
    float a = std::stof(memory->load(indexA));
    float b = std::stof(memory->load(indexB));
    accumulator = std::to_string(a * b);
    return accumulator;
}



std::string Cpu::divide(int indexA, int indexB) {
    int a = std::stoi(memory->load(indexA));
    int b = std::stoi(memory->load(indexB));
    accumulator = std::to_string(a / b);
    return accumulator;
}

std::string Cpu::divideFloat(int indexA, int indexB)
{
    float a = std::stof(memory->load(indexA));
    float b = std::stof(memory->load(indexB));
    accumulator = std::to_string(a / b);
    return accumulator;
}



bool Cpu::compare(int indexA, int indexB, std::string op) {
    int a = std::stoi(memory->load(indexA));
    int b = std::stoi(memory->load(indexB));
    if (op == ">")  return a > b;
    if (op == "<")  return a < b;
    if (op == "==") return a == b;
    return false;
}

bool Cpu::compareFloat(int indexA, int indexB, std::string op) 
{
    float a = std::stof(memory->load(indexA));
    float b = std::stof(memory->load(indexB));
    if (op == ">")  return a > b;
    if (op == "<")  return a < b;
    if (op == "==") return a == b;
    return false;
}
