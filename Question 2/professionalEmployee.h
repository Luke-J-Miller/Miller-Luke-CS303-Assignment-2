#pragma once
#include <string>
#include "employee.h"

//Initialized professional Employee class
class professionalEmployee : public Employee {
public:

	//Default constructor
	professionalEmployee() : Employee(), insurancePlan('x'), weeklyVacationDays(-1), weeklyHealthInsuranceContributions(-1), weeklySalary(-1), annualSalary(-1) {};
	
	//Parameterized instructor
	professionalEmployee(std::string famName, std::string givName, int emplID, double annualSal, char insurPlan) :
		Employee(famName, givName, emplID), annualSalary(annualSal) {
		setInsurancePlan(insurPlan);
		setWeeklySalary(annualSal, 52);
		setWeeklyVacationDays(52);
		setWeeklyHealthInsuranceContributions(insurPlan); };

	//setters and getters
	double setAnnualSalary(double annualSal);
	double getAnnualSalary() const;
	double setWeeklySalary(double annualSal, double weeks);
	double getWeeklySalary() const;
	double setWeeklyVacationDays(double weeks);
	double getWeeklyVacationDays() const;
	char setInsurancePlan(char insurPlan);
	char getInsurancePlan() const;
	double setWeeklyHealthInsuranceContributions(char insurPlan);
	double getWeeklyHealthInsuranceContributions() const;

	//Prints an individual employee
	void printEmployee() const;

private:
	//variables
	std::string familyName;
	std::string givenName;
	int employeeID;
	double weeklySalary;
	double annualSalary;
	double weeklyVacationDays;
	char insurancePlan;
	double weeklyHealthInsuranceContributions;

	//variables used to compute vacation and health insurance
	double const professionalPercentageOfHealthInsurance = 0.50;
	double const professionalVacationDays = 28;
};