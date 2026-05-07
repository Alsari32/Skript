#include <iostream>
#include "WeatherLang.h"
int main() {
	Memory mem;
	Cpu cpu(&mem);
	outPut out;
	IO* io = new outPut();//AI
	WeatherLang lang(&cpu,&out ,io);
	
		// create an array of IO pointers
	IO* ioObjects[2];
	ioObjects[0] = new outPut();  // first one is outPut
	ioObjects[1] = new inPut();   // second one is inPut
	
	// call display on both using the same IO pointer
	// each one behaves differently!
	ioObjects[0]->display("I am outPut!");   // outPut's display runs
	ioObjects[1]->display("I am inPut!");
	
	for (int i = 0; i < 2; i++) {
    ioObjects[i]->display("polymorphism test");
}
	
	
//   lang << "wind a = 5.7;";
//	lang << "wind b = 10.4;";
//	lang << "c = x<y;";
//	//lang << "c = a + b;";
//	lang << "forecast c;";
    
    
    lang << "temp x = 5;";
    lang << "temp y = 10;";
    lang << "temp limit = 10;";
    lang << "c = x < limit;";
	
	
	 

	
	return 0;
}
