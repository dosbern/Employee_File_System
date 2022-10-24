// employeeType.h
// header file

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "employeeType.h"

using namespace std;

class employeeType
{
public:
	employeeType()
	{
		firstName = "";
		lastName = "";
		sales = 0;
		expenses = 0;
	};
	employeeType(std::string setFirstName, std::string setLastName);
	double getRandomSales();
	double getRandomExpenses();
	void display();
	double sales;
	double expenses;
	std::string firstName;
	std::string lastName;
};