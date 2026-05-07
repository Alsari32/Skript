#ifndef VARIABLE_H
#define VARIABLE_H
#include <iostream>
#include <string>
//Parent class to tempVar(int) and winVar(float)
class Variable
{
	protected:
		std::string name;
		int memIndex;
		static int nextIndex;
		std::string type;
	public:
		Variable(std::string name);
		std::string getName();
		int getMemIndex();
		std::string getType();
};

#endif
