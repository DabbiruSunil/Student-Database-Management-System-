// Standard (system) header files
#include <iostream>
#include <cstdlib>
#include "SimpleUI.h"

// Add more standard header files as required
// #include <string>

using namespace std;

// Add your project's header files here
// #include "CFraction.h"

// Main program
int main ()
{
    // TODO: Add your program code here
	cout << "StudentDB started." << endl << endl;
	StudentDb database;
	SimpleUI simpleUIObject(database);
	simpleUIObject.run();
	return 0;
}
