#pragma once
#include <string>
#include <iostream>

//Used during debugging with "if(debug) {...}
static const bool debug = false;

//Abstract class, Employee, Initialization
class Employee {
public:

	//Setters and getters
	void setFamilyName(std::string familyNam);
	std::string getFamilyName() const;

	void setGivenName(std::string givenNam);
	std::string getGivenName() const;

	void setEmployeeID(int emplID);
	int getEmployeeID() const;


	//Default constructor
	Employee() : familyName("None"), givenName("None"), employeeID(-1) {};

	//Parameterized instructor
	Employee(std::string famName, std::string givName, int emplID) : familyName(famName), givenName(givName), employeeID(emplID) {
		if (debug) { std::cout << "File: " << __FILE__ << ", Line: " << __LINE__ << std::endl; }

	};


	//Abstract functions.  Defined in derived classes.
	virtual double setWeeklySalary(double val1, double val2) = 0;
	virtual double getWeeklySalary() const= 0;

	virtual double setWeeklyVacationDays(double hrsperweek) = 0;
	virtual double getWeeklyVacationDays() const = 0;

	virtual double setWeeklyHealthInsuranceContributions(char insurPlan) = 0;
	virtual double getWeeklyHealthInsuranceContributions() const = 0;

	virtual char setInsurancePlan(char insurPlan) = 0;
	virtual char getInsurancePlan() const = 0;

	virtual void printEmployee() const = 0;

protected:
	//variables
	std::string familyName;
	std::string givenName;
	int employeeID;
	
	//variables used to calculate employee portion of premiums
	double const singleMonthlyInsuranceRate = 134.39;
	double const coupleMonthlyInsuranceRate = 215.37;
	double const familyMonthlyInsuranceRate = 299.99;
};