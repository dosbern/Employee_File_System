// CSIS223_Final_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "employeeType.h"

using namespace std;

void sortData(employeeType employee[], int length);

int main()
{
    srand(time(0));
    double totalSales = 0;
    double totalExpenses = 0;

    employeeType employee[25]{ {"Devin", "Osbern"},
        {"Susan", "DeLay"},
        {"Dianne", "Conrow"},
        {"Myron", "Chou"},
        {"Shawn", "Oldham"},
        {"Bih", "Awasom"},
        {"David", "Eubank"},
        {"Abdelazim", "Khamis"},
        {"Demaris", "Dooley"},
        {"Grace", "Reesman"},
        {"Alexandria", "Paszkiewicz"},
        {"Magnim", "Ani"},
        {"Josiah", "Anderson"},
        {"Ryan", "Huynh"},
        {"Alex", "Ahern"},
        {"Lexi", "Chapman"},
        {"Colby", "Marshall"},
        {"Sammy", "Jolie"},
        {"Barny", "Merker"},
        {"Kaylyn", "Smith"},
        {"Tera", "McIntosh"},
        {"Lilly", "Calagin"},
        {"Leanne", "Obrien"},
        {"Amina", "Pace"},
        {"Eric", "French"}, };

    for (int i = 0; i < 25; i++)
    {
        totalSales = totalSales + employee[i].sales;
        totalExpenses = totalExpenses + employee[i].expenses;
    }

    sortData(employee, 25);

    bool running = true;
    string str = " ";

    do
    {
        cout << "Main Menu" << endl;
        cout << "1. Display Employee Data On Screen" << endl;
        cout << "2. Output Employee Data To File" << endl;
        cout << "3. Exit Program" << endl;
        int choice;

        try
        {
            cout << "Enter a number to make your selection:" << endl;
            cin >> choice;

            if (choice < 0 || choice > 3)
                throw - 1;
            if (!cin)
                throw str;
        }
            catch (int)
            {
                cout << "\nError catch 'int'. Invalid input.\n\n" << endl;
                cin.clear();
                cin.ignore(100, '\n');
            }
            catch (double)
            {
                cout << "\nError catch 'double'. Invalid input.\n\n" << endl;
                cin.clear();
                cin.ignore(100, '\n');
            }
            catch (string messageStr)
            {
                cout << messageStr << endl << "\nError catch 'string'. Invalid input.\n\n" << endl;
                cin.clear();
                cin.ignore(100, '\n');
            }
            if (choice == 1)
            {
                cout << "\nYour input \"1\" has selected to display data on screen.\n\n" << endl;
                cin.clear();
                cin.ignore(100, '\n');
                
                cout << "\n\n\n" << fixed << showpoint << setprecision(2)
                    << "List Of Current Sales Data For Each Salesperson" << endl
                    << "---------------------------------------------------------------------------------"
                    << "---------------------------------------------------------------------------------" << endl
                    << setw(0) << "Name:"
                    << setw(40) << "Sales:"
                    << setw(25) << "Expenses:"
                    << setprecision(1)
                    << setw(49) << "Percentage Of Total Sales: "
                    << setw(40) << "Percentage of Total Expenses: " << endl;
                for (int i = 0; i < 25; i++)
                {
                    cout << fixed << showpoint << setprecision(2)
                        << left
                        << setw(25) << (employee[i].lastName + ", " + employee[i].firstName)
                        << right
                        << setw(15) << "$" << employee[i].sales
                        << setw(15) << "$" << employee[i].expenses
                        << setprecision(1)
                        << setw(31) << " " << (employee[i].sales / totalSales) * 100 << "%"
                        << setw(34) << right << " " << (employee[i].expenses / totalExpenses) * 100 << "%" << endl;
                }
                cout << fixed << showpoint << setprecision(2) << "\n\n\n" << "Total Sales: $" << totalSales << "\nTotal Expenses: $" << totalExpenses << "\n" << endl;
            }
            else if (choice == 2)
            {
                cout << "\nYour input \"2\" has selected to output data to a file.\n\n" << endl;
                cin.clear();
                cin.ignore(100, '\n');
                
                ofstream outData;
                outData.open("EmployeeSalesData.txt");

                outData << "\n\n\n" << fixed << showpoint << setprecision(2)
                    << "List Of Current Sales Data For Each Salesperson" << endl
                    << "---------------------------------------------------------------------------------"
                    << "---------------------------------------------------------------------------------" << endl
                    << setw(0) << "Name:"
                    << setw(40) << "Sales:"
                    << setw(25) << "Expenses:"
                    << setprecision(1)
                    << setw(49) << "Percentage Of Total Sales: "
                    << setw(40) << "Percentage of Total Expenses: " << endl;
                for (int i = 0; i < 25; i++)
                {
                    outData << fixed << showpoint << setprecision(2)
                        << left
                        << setw(25) << (employee[i].lastName + ", " + employee[i].firstName)
                        << right
                        << setw(15) << "$" << employee[i].sales
                        << setw(15) << "$" << employee[i].expenses
                        << setprecision(1)
                        << setw(31) << " " << (employee[i].sales / totalSales) * 100 << "%"
                        << setw(34) << right << " " << (employee[i].expenses / totalExpenses) * 100 << "%" << endl;
                }
                outData << fixed << showpoint << setprecision(2) << "\n\n\n" << "Total Sales: $" << totalSales << "\nTotal Expenses: $" << totalExpenses << "\n" << endl;


                cout << "Employee data has been exported to a file.\n\n" << endl;
            }
            else if (choice == 3)
            {
                cout << "\nYour input \"3\" has selected to exit the program.\n\n" << endl;
                cin.clear();
                cin.ignore(100, '\n');
                
                running = false;
            }

    } while (running);

    system("pause");
    return 0;
}

void sortData(employeeType employee[], int length)
{
    employeeType temp;

    for (int iteration = 1; iteration < length; iteration++)
    {
        for (int index = 0; index < length - iteration; index++)
            if (employee[index].lastName > employee[index + 1].lastName)
            {
                temp = employee[index];
                employee[index] = employee[index + 1];
                employee[index + 1] = temp;
            }
    }
};