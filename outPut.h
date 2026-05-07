#ifndef OUTPUT_H
#define OUTPUT_H
#include "IO.h"
#include <iostream>
class outPut : public IO
{
	public:
		void display(std::string message);
		
		template <typename T>//this way it works for both int and float
		void print(std::string name,T value)
		{
			std::cout << "[forecast] " << name << " = " << value << "\n";
		}
	
};

#endif
