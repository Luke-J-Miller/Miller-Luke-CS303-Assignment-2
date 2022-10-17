#pragma once
#include <cassert>
#include <string>
#include "nonprofessionalEmployee.h"
#include "employee.h"
#include "professionalEmployee.h"
#include "TestingSuite.h"

//function used to combine individual tests
void TestingSuite() {
	TestNonprofessionalEmployee();
	TestProfessionalEmployee();
}

//tests the nonprofessionalEmployee class
void TestNonprofessionalEmployee() {
	std::string givnam = "john", famnam = "smith";
	int emplID = 123456789;
	double hrlywage = 22, hrsprwk = 40;
	char insPlan = 's';
	nonprofessionalEmployee testNonprofessionalEmployee(std::string("smith"), std::string("john"), 123456789, 22, 40, 's');
	assert(testNonprofessionalEmployee.getGivenName() == givnam);
	assert(testNonprofessionalEmployee.getFamilyName() == famnam);
	assert(testNonprofessionalEmployee.getEmployeeID() == emplID);
	assert(testNonprofessionalEmployee.getHourlyWage() == hrlywage);
	assert(testNonprofessionalEmployee.getHoursPerWeek() == hrsprwk);
	assert(testNonprofessionalEmployee.getInsurancePlan() == insPlan);
	testNonprofessionalEmployee.setGivenName("bill");
	testNonprofessionalEmployee.setFamilyName("johnson");
	testNonprofessionalEmployee.setEmployeeID(999999999);
	testNonprofessionalEmployee.setHourlyWage(7.20);
	testNonprofessionalEmployee.setHoursPerWeek(32);
	testNonprofessionalEmployee.setInsurancePlan('f');
	assert(testNonprofessionalEmployee.getGivenName() != givnam);
	assert(testNonprofessionalEmployee.getFamilyName() != famnam);
	assert(testNonprofessionalEmployee.getEmployeeID() != emplID);
	assert(testNonprofessionalEmployee.getHourlyWage() != hrlywage);
	assert(testNonprofessionalEmployee.getHoursPerWeek() != hrsprwk);
	assert(testNonprofessionalEmployee.getInsurancePlan() != insPlan);
}

//Tests the professionalEmployee class
void TestProfessionalEmployee() {
	std::string givnam = "jack", famnam = "black";
	int emplID = 123456789;
	double annSal = 52000;
	char insPlan = 'f';
	professionalEmployee TestProfessionalEmployee(std::string("black"), std::string("jack"), 123456789, 52000, 'f');
	assert(TestProfessionalEmployee.getGivenName() == givnam);
	assert(TestProfessionalEmployee.getFamilyName() == famnam);
	assert(TestProfessionalEmployee.getEmployeeID() == emplID);
	assert(TestProfessionalEmployee.getAnnualSalary() == annSal);
	assert(TestProfessionalEmployee.getInsurancePlan() == insPlan);
	TestProfessionalEmployee.setGivenName("bill");
	TestProfessionalEmployee.setFamilyName("johnson");
	TestProfessionalEmployee.setEmployeeID(999999999);
	TestProfessionalEmployee.setAnnualSalary(7.20);
	TestProfessionalEmployee.setInsurancePlan('c');
	assert(TestProfessionalEmployee.getGivenName() != givnam);
	assert(TestProfessionalEmployee.getFamilyName() != famnam);
	assert(TestProfessionalEmployee.getEmployeeID() != emplID);
	assert(TestProfessionalEmployee.getAnnualSalary() != annSal);
	assert(TestProfessionalEmployee.getInsurancePlan() != insPlan);
}