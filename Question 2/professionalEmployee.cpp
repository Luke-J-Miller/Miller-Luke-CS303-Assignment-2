#include <string>
#include <stdexcept>
#include <iostream>
#include "employee.h"
#include "professionalEmployee.h"


	//setters and getters
	double professionalEmployee::setAnnualSalary(double annualSal) { annualSalary = annualSal; return annualSalary; }
	double professionalEmployee::getAnnualSalary() const { return annualSalary; }
	double professionalEmployee::setWeeklySalary(double annualSal, double weeks) { weeklySalary = annualSal / weeks; return weeklySalary; }
	double professionalEmployee::getWeeklySalary() const { return weeklySalary; }
	double professionalEmployee::setWeeklyVacationDays(double weeks = 52) { 
		weeklyVacationDays = professionalVacationDays / weeks; 
		if (debug) { std::cout << "File: " << __FILE__ << ", Line: " << __LINE__ << std::endl;
		std::cout << "Weekly vacation days calculated = " << weeklyVacationDays << std::endl;
		}

		return weeklyVacationDays; }
	double professionalEmployee::getWeeklyVacationDays() const { return weeklyVacationDays; }
	char professionalEmployee::setInsurancePlan(char insurPlan) { insurancePlan = insurPlan; return insurancePlan; }
	char professionalEmployee::getInsurancePlan() const { return insurancePlan; }
	double professionalEmployee::setWeeklyHealthInsuranceContributions(char insurPlan) {
		if (debug) { std::cout << "File: " << __FILE__ << ", Line: " << __LINE__ << "insurancePlan value: " << insurPlan << std::endl; }
		switch (insurPlan) {
		case 's':
			weeklyHealthInsuranceContributions = professionalPercentageOfHealthInsurance * singleMonthlyInsuranceRate * 12 / 52;
			break;
		case 'c':
			weeklyHealthInsuranceContributions = professionalPercentageOfHealthInsurance * coupleMonthlyInsuranceRate * 12 / 52;
			break;
		case 'f':
			weeklyHealthInsuranceContributions = professionalPercentageOfHealthInsurance * familyMonthlyInsuranceRate * 12 / 52;
			break;
		case 'n':
			weeklyHealthInsuranceContributions = professionalPercentageOfHealthInsurance * 0 * 12 / 52;
			break;
		default:
			std::cout << "An incorrect insurance plan was passed to setWeeklyHealthInsuranceContributions" << std::endl;
			break;
		}
		return weeklyHealthInsuranceContributions;
	}
	double professionalEmployee::getWeeklyHealthInsuranceContributions() const { return weeklyHealthInsuranceContributions; }

	//prints an individual employee
	void professionalEmployee::printEmployee() const {
		std::cout <<
			"Salaried Employee" << std::endl <<
			"Name: " << getFamilyName() << ", " << getGivenName() << std::endl <<
			"Employee ID: " << getEmployeeID() << std::endl <<
			"Weekly Pay: " << getWeeklySalary() << std::endl <<
			"Weekly Vacation Days: " << getWeeklyVacationDays() << std::endl <<
			"Current Insuarance Plan: ";
		switch (insurancePlan) {
		case 's':
			std::cout << "Single" << std::endl;
			break;
		case 'c':
			std::cout << "Couple" << std::endl;
			break;
		case 'f':
			std::cout << "Family" << std::endl;
			break;
		case 'n':
			std::cout << "None" << std::endl;
			break;
		default:
			std::cout << "Unknown" << std::endl;
			break;
		}
		std::cout <<
			"Weekly Insurance Contributions: " << getWeeklyHealthInsuranceContributions() << std::endl <<std::endl <<std::endl;
	}

