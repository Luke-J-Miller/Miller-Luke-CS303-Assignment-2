#pragma once
#include "employee.h"
#include "nonprofessionalEmployee.h"
#include "professionalEmployee.h"
#include "utilities.h"
#include <string>
#include <vector>
#include <iostream>

//Header file for utitlites.cpp.  Contains function declarations for functions that aren't part of a class or testing

//returns a valid integer input. Loops internally until valid input provided
int ValidateIntegerInput();

//Prints the welcome message
void WelcomeMessage();

//Provides user with choices to execute
char MainMenu();

//Paired with MainMenu() executes menu options
void MenuOperations(std::vector<Employee*> &EmployeeList, char menuSelection);

//Used to select health insurance plans
char SelectHealthInsurance();

//The following functions are executed by MenuOperations(...)
void AddEmployee(std::vector<Employee*> &EmployeeList);
void AddProfessionalEmployee(std::vector<Employee*> &EmployeeList);
void AddNonprofessionalEmployee(std::vector<Employee*> &EmployeeList);
void PrintEmployeeList(std::vector<Employee*> &EmployeeList);


//Not used.  Saved for later implementation
//void InsertNewEmployeeIntoVector(Employee* newEmployee, std::vector<Employee*> employeeList);
//std::vector<int> SearchEmployee(std::vector<Employee*>& EmployeeList);
//void EditEmployee(std::vector<Employee*> &EmployeeLIst);
