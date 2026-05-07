#ifndef MEMORY_H
#define MEMORY_H
#include <map>
#include <string>
//lang is the middle man between the cpu and memory
class Memory
{
	private:
		std::map<int,std::string> memory;
	
	public:
		Memory();
		void store(int index,std::string value);//put a value INTO a memory box
		std::string load(int index);// GET a value OUT of a memory box
		
		
		
};

#endif
