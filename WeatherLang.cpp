#include "WeatherLang.h"


WeatherLang::WeatherLang(Cpu *c,outPut* o,IO* io)
{
	
	cpu = c;
	out = o;	// cpu now points to main's cpu object
	this->io = io;// output now points to main's out object
	
}


void WeatherLang::temp(std::string name, int value) 
{
    tempVar* v = new tempVar(name);
    variables.push_back(v);
    cpu->setAccumulator(std::to_string(value));
    cpu->store(v->getMemIndex());
}

void WeatherLang::wind(std::string name, float value) 
{
    WindVar* v = new WindVar(name);
    variables.push_back(v);
    cpu->setAccumulator(std::to_string(value));
    cpu->store(v->getMemIndex());
}

int WeatherLang::findVar(std::string name) {//loops through the vector to find the var 
    for (int x = 0; x < (int)variables.size(); x++) {
        if (variables[x]->getName() == name)
            return x;   // found it, return position
    }
    return -1;  // not found
}

void WeatherLang::storm(std::string dest, std::string src) {
    int di = findVar(dest);
    int si = findVar(src);
    if (variables[di]->getType() == "float") {
        cpu->addFloat(variables[di]->getMemIndex(), variables[si]->getMemIndex());
    } else {
        cpu->add(variables[di]->getMemIndex(), variables[si]->getMemIndex());
    }
    cpu->store(variables[di]->getMemIndex());
}


void WeatherLang::forecast(std::string name) {
    int var = findVar(name);
    cpu->load(variables[var]->getMemIndex());

    if (variables[var]->getType() == "float") {
        float value = std::stof(cpu->getAccumulator());
        out->print(name, value);   // template handles float//AI
    } else {
        int value = std::stoi(cpu->getAccumulator());
        out->print(name, value);   // template handles int
    }
}

void WeatherLang::assign(std::string dest, std::string a, std::string op, std::string b) {
    int di = findVar(dest);
    int ai = findVar(a);
    int bi = findVar(b);

    // arithmetic operators
    if (op == "+" || op == "-" || op == "*" || op == "/") {
        if (variables[di]->getType() == "float") {
            if (op == "+") cpu->addFloat(variables[ai]->getMemIndex(), variables[bi]->getMemIndex());//AI
            else if (op == "-") cpu->subtractFloat(variables[ai]->getMemIndex(), variables[bi]->getMemIndex());
            else if (op == "*") cpu->multiplyFloat(variables[ai]->getMemIndex(), variables[bi]->getMemIndex());
            else if (op == "/") cpu->divideFloat(variables[ai]->getMemIndex(), variables[bi]->getMemIndex());
        } else {
            if (op == "+") cpu->add(variables[ai]->getMemIndex(), variables[bi]->getMemIndex());
            else if (op == "-") cpu->subtract(variables[ai]->getMemIndex(), variables[bi]->getMemIndex());
            else if (op == "*") cpu->multiply(variables[ai]->getMemIndex(), variables[bi]->getMemIndex());
            else if (op == "/") cpu->divide(variables[ai]->getMemIndex(), variables[bi]->getMemIndex());
        }
        cpu->store(variables[di]->getMemIndex());

    // comparison operators
    } else if (op == ">" || op == "<" || op == "==") {
        bool result;
        if (variables[ai]->getType() == "float") {
            result = cpu->compareFloat(variables[ai]->getMemIndex(), variables[bi]->getMemIndex(), op);
        } else {
            result = cpu->compare(variables[ai]->getMemIndex(), variables[bi]->getMemIndex(), op);
        }
        std::string resultStr = result ? "true" : "false";
        out->print(dest + " " + op + " " + b, resultStr);
    }
}

void WeatherLang::run(std::string line) {//AI=============
    // step 1 - strip the semicolon
    if (!line.empty() && line.back() == ';')
        line.pop_back();

	// step 2 - check for assignment pattern FIRST (c = a + b)
    std::string tokens[5];
    std::istringstream ss2(line);
    int count = 0;
    while (ss2 >> tokens[count] && count < 5) count++;

    if (count == 5 && tokens[1] == "=") {
        assign(tokens[0], tokens[2], tokens[3], tokens[4]);
        return;  // done, no need to check keywords
    }
	
    // step 4 - read word by word
    std::istringstream ss(line);
    std::string keyword;
    ss >> keyword;

    // step 5 - check keyword and call right function
    if (keyword == "temp") {
    	try{
	        std::string name, eq;
	        int value;
	        ss >> name >> eq >> value;   // reads temp "x" "=" 5
	        temp(name, value);
    	} catch(std::exception& e){
    		std::cout << "WeatherLang error: invalid value for temp\n";
		}
	}
        
    else if (keyword == "wind") {
        try{
	        std::string name, eq;
	        float value;
	        ss >> name >> eq >> value;   // reads wind "x" "=" 5
	        wind(name, value);
    	} catch(std::exception& e){
    		std::cout << "WeatherLang error: invalid value for wind\n";
		}
	}
    else if (keyword == "storm") {
    	try{
		
	        std::string dest, src;
	        ss >> dest >> src;           // reads "x" "y"
	        storm(dest, src);
    	} catch (std::exception& e){
    		 std::cout << "WeatherLang error: unknown variable in storm\n";
		}
    	
    		
		
	}
    else if (keyword == "forecast") {
    	try{
		
	        std::string name;
	        ss >> name;                  // reads "x"
	        forecast(name);
    	} catch(std::exception& e){
    		std::cout << "WeatherLang error: unknown variable in forecast\n";
		}
	}
	
    else {
        std::cout << "error: unknown keyword '" << keyword << "'\n";
    }
    
    
    
}

WeatherLang& WeatherLang::operator<<(std::string line) {//AI
    run(line);
    return *this;
}


