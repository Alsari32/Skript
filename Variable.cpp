#include "Variable.h"

int Variable::nextIndex = 0;


Variable::Variable(std::string name)
		
		{
			this -> name = name;
			memIndex = nextIndex;
			nextIndex++;
		}

std::string Variable::getName()
{
	return name;
}

int Variable::getMemIndex()
{
	return memIndex;
}
std::string Variable::getType() {
    return type;
}
