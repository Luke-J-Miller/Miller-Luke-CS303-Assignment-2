#pragma once
#include <string>
#include "employee.h"
#include <stdexcept>

//Abstract class, Employee, implementation

//Setters and getters
void Employee::setFamilyName(std::string familyNam) { familyName = familyNam; }
std::string Employee::getFamilyName() const { return familyName; }

void Employee::setGivenName(std::string givenNam) { givenName = givenNam; }
std::string Employee::getGivenName() const { return givenName; }

void Employee::setEmployeeID(int emplID) { employeeID = emplID; }
int Employee::getEmployeeID() const { return employeeID; }





