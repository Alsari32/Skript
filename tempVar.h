#ifndef TEMPVAR_H
#define TEMPVAR_H
#include "Variable.h"
//inherits from the parent class Variables
//is called when the user types temp x =5; in lang and then it creates an index for it
class tempVar : public Variable
{
		
	public:
		tempVar(std::string name);
		
};

#endif
