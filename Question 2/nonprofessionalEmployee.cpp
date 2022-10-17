#include <string>
#include <stdexcept>
#include <iostream>
#include "employee.h"
#include "nonprofessionalEmployee.h"


//Setter and getter definitions
double nonprofessionalEmployee::setHourlyWage(double hrlyWage) { hourlyWage = hrlyWage; return hrlyWage; }
double nonprofessionalEmployee::getHourlyWage() const { return hourlyWage; }
double nonprofessionalEmployee::setHoursPerWeek(double hrsPerWk) { hoursPerWeek = hrsPerWk; return hoursPerWeek; }
double nonprofessionalEmployee::getHoursPerWeek() const { return hoursPerWeek; }
char nonprofessionalEmployee::setInsurancePlan(char insurPlan) { insurancePlan = insurPlan; return insurancePlan; }
char nonprofessionalEmployee::getInsurancePlan() const { return insurancePlan; }
double nonprofessionalEmployee::setWeeklySalary(double hrlyWage, double hrsperweek) { weeklySalary = hrlyWage * hrsperweek; return weeklySalary; }
double nonprofessionalEmployee::getWeeklySalary() const { return weeklySalary; }
double nonprofessionalEmployee::setWeeklyVacationDays(double hrsperweek) { weeklyVacationDays = hrsperweek/40 * nonprofessionalVacationDays / 52; return weeklyVacationDays; }
double nonprofessionalEmployee::getWeeklyVacationDays() const { return weeklyVacationDays; }
double nonprofessionalEmployee::setWeeklyHealthInsuranceContributions(char insurPlan) {
	switch (insurPlan) {
	case 's':
		weeklyHealthInsuranceContributions = nonprofessionalPercentageOfHealthInsurance * singleMonthlyInsuranceRate * 12 / 52;
		break;
	case 'c':
		weeklyHealthInsuranceContributions = nonprofessionalPercentageOfHealthInsurance * coupleMonthlyInsuranceRate * 12 / 52;
		break;
	case 'f':
		weeklyHealthInsuranceContributions = nonprofessionalPercentageOfHealthInsurance * familyMonthlyInsuranceRate * 12 / 52;
		break;
	case 'n':
		weeklyHealthInsuranceContributions = nonprofessionalPercentageOfHealthInsurance * 0 * 12 / 52;
		break;
	default:
		throw std::runtime_error("An incorrect insurance plan was passed to setWeeklyHealthInsuranceContributions");
	}
	return weeklyHealthInsuranceContributions;
}
double nonprofessionalEmployee::getWeeklyHealthInsuranceContributions() const { return weeklyHealthInsuranceContributions; }


//Definition of printEmployee.  Overides abstract function from Employee
void nonprofessionalEmployee::printEmployee() const {
	std::cout <<
		"Unsalaried Employee" << std::endl <<
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
		"Weekly Insurance Contributions: " << getWeeklyHealthInsuranceContributions() << std::endl << std::endl << std::endl;
}

