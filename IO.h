#ifndef IO_H
#define IO_H
#include <iostream>
class IO
{
	protected:
		std::string lastMessage;
	public:
		virtual void display(std::string message) = 0;  // pure virtual//AI
	
};

#endif
