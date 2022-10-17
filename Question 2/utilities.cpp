#include "employee.h"
#include "nonprofessionalEmployee.h"
#include "professionalEmployee.h"
#include "utilities.h"
#include <stdexcept>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>


//returns a string of all lower case letters
std::string ConvertStringToLower() {
	std::string inputString;
	std::cin >> inputString;
	std::for_each(inputString.begin(), inputString.end(), [](char& c) { c = ::tolower(c); });
	return inputString;
}

//returns a single. lowercase letter
char ConvertCharacterToLower() {
	char inputChar;
	std::cin >> inputChar;
	inputChar = char(::tolower(inputChar));
	if (debug) { std::cout << "File: " << __FILE__ << ", Line: " << __LINE__ << ", inputChar = " << inputChar << std::endl; }
	return inputChar;
}

//returns a valid integer.  Loops until valid integer provided.
int ValidateIntegerInput() {
	int validInput;
	std::string userInput;
	while (true) {
		std::cin >> userInput;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		if (userInput == "q") { exit(0); }
		try {
			validInput = stoi(userInput);
			break;
		}
		catch (...) {
			std::cout << "An invalid input was received. Enter a valid integer. ";
		}
	}
	return validInput;
}

//returns a valid, positive double.  Loops until valid input received
double ValidatePositiveDoubleInput() {
	bool validInput = false;
	double userDouble;
	while (!validInput) {
		std::cin >> userDouble;
		try {
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				throw std::runtime_error("Invalid input received, you must enter a decimal number");
			}
			if (userDouble < 0) {
				throw std::runtime_error("Miles cannot be less than or equal to zero");
			}
		}
		catch (std::runtime_error& e) {
			std::cout << e.what() << std::endl;
		}
		validInput = true;
	}
	return userDouble;
}

//Prints the welcome message
void WelcomeMessage() {
	std::cout <<
		"Welcome to the LukeTec Employee Database." << std::endl <<
		std::endl;
}


//Displays available options.  Returns a character for use by menu operations
char MainMenu() {
	char userSelection = 'x';
	while (userSelection == 'x') {
		std::cout <<
			"               MAIN MENU" << std::endl <<
			std::endl <<
			"Please enter a selection" << std::endl <<
			std::endl <<
			"a - Add a new employee" << std::endl <<
			"p - Print a list of employees" << std::endl <<
			"q - Quit" << std::endl <<
			std::endl;

		std::cin >> userSelection;
		std::cout << std::endl;
		if (userSelection < 'a') { userSelection += 32; }
		switch (userSelection) {
		case 'q':
			exit(0);
			break;
		case 'a':
			break;
		case 'p':
			break;
		default:
			std::cout << "You entered an invalid character.  Please try again. " << std::endl <<
				std::endl;
			userSelection = 'x';
		}
	}
	return userSelection;
}

//Executes menu selections
void MenuOperations(std::vector<Employee*> &EmployeeList, char menuSelection) {
	switch (menuSelection) {
	case 'a':
		AddEmployee(EmployeeList);
		break;
	/*case 'e':
		EditEmployee(EmployeeList);
		break;*/
	case 'p':
		PrintEmployeeList(EmployeeList);
		break;
	/*case 's':
		SearchEmployee(EmployeeList);
		break;*/
	default:
		std::cout << "An Invalid value was passed to the MenuOperations function." << std::endl;
		break;
	}

}

//Provides user with choice to add professional or nonprofessional employee.  Executes appropriate function
void AddEmployee(std::vector<Employee*> &EmployeeList) {
	char userSelection = 'x';
	while (userSelection == 'x') {
		std::cout <<
			"p - Add new professional employee" << std::endl <<
			"n - Add new nonprofessional employee" << std::endl <<
			"b - go back" << std::endl <<
			std::endl;
		userSelection = ConvertCharacterToLower();
		std::cout << std::endl << std::endl;
		switch (userSelection) {
		case 'p':
			AddProfessionalEmployee(EmployeeList);
			break;
		case 'n':
			AddNonprofessionalEmployee(EmployeeList);
			break;
		case 'b':
			break;
		default:
			userSelection = 'x';
			break;

		}
	}
}

//Used by AddEmployee to add a professional employee
void AddProfessionalEmployee(std::vector<Employee*> &EmployeeList) {
	bool validEmployeeID = false;
	std::string givenName, familyName;
	int employeeID;
	char insurancePlan, commitDetails;
	double annualSalary;
	std::cout << "Enter the employee's given name. " << std::endl;
	givenName = ConvertStringToLower();
	std::cout << std::endl;
	std::cout << "Enter the employee's family name. " << std::endl;
	familyName = ConvertStringToLower();
	std::cout << std::endl;
	std::cout << "Enter the employee's identification number" << std::endl;
	employeeID = ValidateIntegerInput();
	std::cout << std::endl;
	if (EmployeeList.size() == 0) { validEmployeeID = true; }
	for (int i = 0; i < EmployeeList.size(); i++) {
		if (EmployeeList[i]->getEmployeeID() == employeeID) {
			std::cout << "That ID is already in the system.  Please try again with an unused ID or edit the entry." << std::endl << std::endl;
			EmployeeList[i]->printEmployee();
			return;
		}
		else {
			validEmployeeID = true;
		}
	}
	if (validEmployeeID) {
		insurancePlan = SelectHealthInsurance();
		std::cout << "Please enter the employee's annual salary." << std::endl << std::endl;
		annualSalary = ValidatePositiveDoubleInput();
		std::cout << "Please review the following details for accuracy before committing.\n" <<
			"Given name: " << givenName << std::endl <<
			"Family name: " << familyName << std::endl <<
			"Identification number: " << employeeID << std::endl <<
			"Insuraance Plan: " << insurancePlan << std::endl <<
			"(s - single, f - family, c - couple, n - none) " << std::endl <<
			"Annual salary: " << annualSalary << std::endl <<
			std::endl <<
			"Do all the details look correct (y/n)? :" << std::endl;
		commitDetails = ConvertCharacterToLower();
		std::cout << std::endl << std::endl;
		if (commitDetails != 'y') {
			std::cout << "You did not press 'y' for commit.  Please try again." << std::endl <<std::endl;
		}
		else {
			Employee* newEmployee = new professionalEmployee(familyName, givenName, employeeID, annualSalary, insurancePlan);
			if (debug) { std::cout << "File: " << __FILE__ << ", Line: " << __LINE__ << std::endl; 
			newEmployee->printEmployee();
			}
			EmployeeList.push_back(newEmployee);
		}
	}
		
}

//Used by AddEmployee to add a nonprofessional employee
void AddNonprofessionalEmployee(std::vector<Employee*>& EmployeeList) {
	bool validEmployeeID = false;
	std::string givenName, familyName;
	int employeeID;
	char insurancePlan, commitDetails;
	double hourlyWage, hoursPerWeek;
	std::cout << "Enter the employee's given name. " << std::endl;
	givenName = ConvertStringToLower();
	std::cout << "Enter the employee's family name. " << std::endl;
	familyName = ConvertStringToLower();
	std::cout << "Enter the employee's identification number" << std::endl;
	employeeID = ValidateIntegerInput();
	for (int i = 0; i < EmployeeList.size(); i++) {
		if (EmployeeList[i]->getEmployeeID() == employeeID) {
			std::cout << "That ID is already in the system.  Please try again with an unused ID or edit the entry." << std::endl;
			EmployeeList[i]->printEmployee();
			std::cout << std::endl;
			return;
		}
		else {
			validEmployeeID = true;
		}
	}
	if (validEmployeeID) {
		insurancePlan = SelectHealthInsurance();
		std::cout << "Please enter the employee's hourly wage." << std::endl;
		hourlyWage = ValidatePositiveDoubleInput();
		std::cout << "Please enter the employee's hours per week." << std::endl;
		hoursPerWeek = ValidatePositiveDoubleInput();
	}
	std::cout << "Please review the following details for accuracy before committing.\n" <<
		"Given name: " << givenName << std::endl <<
		"Family name: " << familyName << std::endl <<
		"Identification number: " << employeeID << std::endl <<
		"Insurance Plan: " << insurancePlan << std::endl <<
		"(s = single, c = couple, f = family, n = none)" << std::endl <<
		"Hourly wage: " << hourlyWage << std::endl <<
		"Hours per week: " << hoursPerWeek << std::endl <<
		std::endl <<
		"Do all the details look correct (y/n)?: ";
	std::cin >> commitDetails;
	std::cout << std::endl << std::endl;
	if (commitDetails != 'y') {
		std::cout << "You did not press 'y' for commit.  Please try again." << std::endl;
	}
	else {
		Employee* newEmployee = new nonprofessionalEmployee(familyName, givenName, employeeID, hourlyWage, hoursPerWeek, insurancePlan);
		EmployeeList.push_back(newEmployee);
	}
}


//Prints a list of all added employees to the screen
void PrintEmployeeList(std::vector<Employee*> &EmployeeList) {
	if (EmployeeList.size() == 0) {
		std::cout << "There aren't any employees in the system." << std::endl;
	}
	for (int i = 0; i < EmployeeList.size(); i++) {
		EmployeeList.at(i)->printEmployee();
	}
}


//Used by AddEmployee to select health insurance plans
char SelectHealthInsurance() {
	char insuranceSelection = 'x';
	while (insuranceSelection == 'x') {
		std::cout <<
			"Please select the health insurance for the employee" << std::endl <<
			"(s - Single, c - Couple, f - Family, n - None" << std::endl;
		insuranceSelection = ConvertCharacterToLower();
		std::cout << std::endl;
		if (debug) { std::cout << "File: " << __FILE__ << ", Line: " << __LINE__ << ", inputChar = " << insuranceSelection << std::endl; }

		if (insuranceSelection != 's' && insuranceSelection != 'c' && insuranceSelection != 'f' && insuranceSelection != 'n') {
			std::cout << "Please enter a valid selection. " << std::endl << std::endl;
			insuranceSelection = 'x';
		}
	}
	return insuranceSelection;
}




//Not used.  Saved for later implementation

//std::vector<int> SearchEmployee(std::vector<Employee*>& EmployeeList) {
//	char nameOrID;
//	std::vector<int> searchMatches;
//	std::string givenNam, familyNam;
//	int emplID;
//	if (EmployeeList.size() == 0) {
//		std::cout << "There are no employees entered yet." << std::endl;
//	}
//	else {
//		std::cout << "Do you want to search for the employee by:" << std::endl <<
//			"n - name" << std::endl <<
//			"i - or id number?" << std::endl;
//		nameOrID = ConvertCharacterToLower();
//		std::cout << std::endl;
//		switch (nameOrID) {
//		case 'n':
//			std::cout << "Enter the family name: " << std::endl;
//			familyNam = ConvertStringToLower();
//			std::cout << "Enter the given name: " << std::endl;
//			givenNam = ConvertStringToLower();
//			for (int i = 0; i < EmployeeList.size(); i++) {
//				if ((familyNam == EmployeeList.at(i)->getFamilyName()) && (givenNam == EmployeeList.at(i)->getGivenName())) {
//					EmployeeList.at(i)->printEmployee();
//					searchMatches.push_back(i);
//				}
//				else {
//					continue;
//				}
//			}
//			if (searchMatches.size() == 0) {
//				std::cout << "The name was not found." << std::endl;
//				searchMatches.push_back(-1);
//			}
//			break;
//		case 'i':
//			std::cout << "Enter the employee ID: " << std::endl;
//			emplID = ValidateIntegerInput();
//			for (int i = 0; i < EmployeeList.size(); i++) {
//				if (emplID == EmployeeList.at(i)->getEmployeeID()) {
//					searchMatches.push_back(i);
//					break;
//				}
//				break;
//			}
//			if (searchMatches.size() == 0) {
//				std::cout << "The ID was not found." << std::endl;
//				searchMatches.push_back(-1);
//			}
//			break;
//		default:
//			std::cout << "You did not press 'n' or 'i'.  Please try again." << std::endl;
//			searchMatches.push_back(-1);
//		}
//		return searchMatches;
//	}
//}

//void InsertNewEmployeeIntoVector(Employee* newEmployee, std::vector<Employee*> &employeeList) {
//	if (debug) { std::cout << "File: " << __FILE__ << ", Line: " << __LINE__ << std::endl; }
//
//	if (employeeList.size() == 0) { 
//		employeeList.push_back(newEmployee);
//		if (debug) { std::cout << "File: " << __FILE__ << ", Line: " << __LINE__ << ", Value inserted: " << std::endl;
//		employeeList.at(0)->printEmployee();
//		}
//	}
//	else {
//		for (int i = 0; i < employeeList.size(); i++) {
//			if (newEmployee->getFamilyName() < employeeList.at(i)->getFamilyName()) {
//				employeeList.insert(employeeList.begin() + i, newEmployee);
//			}
//			else if (newEmployee->getFamilyName() == employeeList.at(i)->getFamilyName()) {
//				if (newEmployee->getGivenName() < employeeList.at(i)->getGivenName()) {
//					employeeList.insert(employeeList.begin() + i, newEmployee);
//				}
//				else if (newEmployee->getGivenName() == employeeList.at(i)->getGivenName()) {
//					if (newEmployee->getEmployeeID() < employeeList.at(i)->getEmployeeID()) {
//						employeeList.insert(employeeList.begin() + i, newEmployee);
//					}else {continue;}
//				}else {continue;}
//			}else {continue;}
//		}
//	}
//}
//void EditEmployee(std::vector<Employee*> &EmployeeList) {
//	std::vector<int> searchMatches = SearchEmployee(EmployeeList);
//	if (searchMatches[0] == -1) {
//		return;
//	}
//	else if (searchMatches.size() > 1) {
//		std::cout << "Please enter the employee ID of the entry you wish to edit." << std::endl;
//		int emplID = ValidateIntegerInput();
//		if (debug) { std::cout << "File: " << __FILE__ << ", Line: " << __LINE__ << std::endl; }
//		for (int i = 0; i < searchMatches.size(); i++) {
//			if (EmployeeList.at(searchMatches[i])->getEmployeeID() != emplID) {
//				searchMatches.erase(searchMatches.begin() + i);
//			}
//		}
//
//		std::cout << "Warning: Proceding with editing the employee will delete previous data. Would you like to continue(y/n)?";
//		char userContinue;
//		std::cin >> userContinue;
//		if (userContinue != 'y') { return; }
//		else {
//			EmployeeList.erase(EmployeeList.begin() + searchMatches.at(0));
//			AddEmployee(EmployeeList);
//		}
//	}
//}