// employeeTypeImp.cpp
// implementation file

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "employeeType.h"

using namespace std;

employeeType::employeeType(std::string setFirstName, std::string setLastName) {
	firstName = setFirstName;
	lastName = setLastName;
	sales = getRandomSales();
	expenses = getRandomExpenses();
};

double employeeType::getRandomSales() // creates random values for sales to test program
{
	double num = rand() % 100000;

	return num;
}

double employeeType::getRandomExpenses() // creates random values for expenses to test program
{
	double num = rand() % 6000;

	return num;
}

void employeeType::display()
{
	cout << fixed << showpoint << setprecision(2);
	cout << setw(12) << lastName << ", " << setw(12) << firstName << setw(12) << "Sales: $" << sales << setw(16) << "Expenses: $" << expenses;
};