#pragma once
#include <iostream>
#include <string>
#include "employee.h"

//This class stores information on hourly employees. Inherits from abstract Employee class
class nonprofessionalEmployee : public Employee {
public:

	//Default Constructor
	nonprofessionalEmployee() : familyName("None"), givenName("None"), employeeID(-1), insurancePlan('x'), weeklyVacationDays(-1), weeklyHealthInsuranceContributions(-1), weeklySalary(-1), hourlyWage(-1), hoursPerWeek(-1) {
		if (debug) { std::cout << "File: " << __FILE__ << ", Line: " << __LINE__ << ", inputChar = " << std::endl; }

	};

	//Parameterized insstructor
	nonprofessionalEmployee(std::string famName, std::string givName, int emplID, double hrlyWage, double hrsperwk, char insurPlan) :
		Employee(famName, givName, emplID), hourlyWage(hrlyWage), hoursPerWeek(hrsperwk) {
		setWeeklyVacationDays(hrsperwk);
		setInsurancePlan(insurPlan);
		setWeeklyHealthInsuranceContributions(insurPlan);
		setWeeklySalary(hrlyWage, hrsperwk);
		if (debug) { std::cout << "File: " << __FILE__ << ", Line: " << __LINE__ << std::endl; }
	};

	//Setters and getters for nonprofessionalEmployee variables
	double setHourlyWage(double hrlyWage);
	double getHourlyWage() const;
	double setHoursPerWeek(double hrsPerWk);
	double getHoursPerWeek() const;
	char setInsurancePlan(char insurPlan);
	char getInsurancePlan() const;
	double setWeeklySalary(double hrlyWage, double hrsperweek);
	double getWeeklySalary() const;
	double setWeeklyVacationDays(double hrsperweek);
	double getWeeklyVacationDays() const;
	double setWeeklyHealthInsuranceContributions(char insurPlan);
	double getWeeklyHealthInsuranceContributions() const;

	//Prints Employee details
	void printEmployee() const;

private:
	//variables
	std::string familyName;
	std::string givenName;
	int employeeID;
	double weeklySalary;
	double hourlyWage;
	double hoursPerWeek;
	double weeklyVacationDays;
	char insurancePlan;
	double weeklyHealthInsuranceContributions;

	//Variables that differentiate insurance and vacation between professional and nonprofessional
	double const nonprofessionalPercentageOfHealthInsurance = 0.65;
	double const nonprofessionalVacationDays = 21;
};