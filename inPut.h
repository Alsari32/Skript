#ifndef INPUT_H
#define INPUT_H
#include "IO.h"
#include <string>
#include <iostream>
class inPut : public IO
{
	public:
		void display(std::string message); 
		std::string getInt(std::string name);    // asks user for an int
    	std::string getFloat(std::string name);  // asks user for a float
};

#endif
