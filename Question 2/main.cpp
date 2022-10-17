
#include <vector>
#include <string>
#include <cassert>
#include "nonprofessionalEmployee.h"
#include "professionalEmployee.h"
#include "employee.h"
#include "utilities.h"
#include "TestingSuite.h"

//if true, executes the test functions in TestingSuite.h
const bool testing = false;

//Main function
int main() {
	
	//Primary operation executes if testing == false
	if (testing == false) {
		//The list of Employees
		std::vector<Employee*> EmployeeList;

		//Standard Welcome message
		WelcomeMessage();
		
		//Loops until user Exits
		while (true) {

			//MenuOperations is an omnibus function that executes any option given by the main menu
			MenuOperations(EmployeeList, MainMenu());
		}
	}
	if(testing) {
		//The test suite in Testing.h
		TestingSuite();
	}
}