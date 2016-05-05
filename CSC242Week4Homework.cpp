/*
Duane Michael
CSC 242 - Intro. to Programming Concepts & Methods
Week 4 - Homework
Professor - Dr. Alireza Farahani*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
The employee class stores objects of type employee with the employee's
name, weekly pay, marital status, and number of dependents.
*/
class employee
{

//Method documentation will be prior to each individual method.
public:
	employee();
	employee(string n, double wp, string s, int d);
	void setEmployeeName(string n);
	void setWeeklyPay(double wp);
	void setMaritalStatus(string s);
	void setDependents(int d);
	string getEmployeeName() const;
	double getWeeklyPay() const;
	string getMaritalStatus() const;
	int getDependents() const;
	void print() const;
	double taxDeduction(employee);
	double payAfterTax(employee) const;

private:
	string employeeName;
	double weeklyPay;
	string maritalStatus;
	int  dependents;
};

//Default constructor -- Used to initialize private members.
employee::employee()
{
	employeeName = "none";
	weeklyPay = 0.0;
	maritalStatus = "none";
	dependents = 0;
}

//Constructor with parameters to assign variables to private members.
employee::employee(string n, double wp, string s, int d)
{
	employeeName = n;
	weeklyPay = wp;
	maritalStatus = s;
	dependents = d;
}

//Sets the private member value to that of a parameter passed to the method.
void employee::setEmployeeName(string n)
{
	employeeName = n;
}

//Sets the private member value to that of a parameter passed to the method.
void employee::setWeeklyPay(double wp)
{
	weeklyPay = wp;
}

//Sets the private member value to that of a parameter passed to the method.
void employee::setMaritalStatus(string s)
{
	maritalStatus = s;
}

//Sets the private member value to that of a parameter passed to the method.
void employee::setDependents(int d)
{
	dependents = d;
}

//Returns the value of the private data member to the method call.
string employee::getEmployeeName() const
{
	return employeeName;
}

//Returns the value of the private data member to the method call.
double employee::getWeeklyPay() const
{
	return weeklyPay;
}

//Returns the value of the private data member to the method call.
string employee::getMaritalStatus() const
{
	return maritalStatus;
}

//Returns the value of the private data member to the method call.
int employee::getDependents() const
{
	return dependents;
}

//Prints formatted output containing the private members.
void employee::print() const
{

	cout << "Employee name: " << employeeName << ".\n" << "Weekly Pay: " << weeklyPay
		<< ".\n" << "Marital status: " << maritalStatus << ".\n" << "Number of dependents: "
		<< dependents << ".\n";
}

/*Receives a passed object parameter and compares it against the following table:
Dependents  Married %   Single %
    <= 2       20%        25%
	 3         15%        20%
	 4         10%        15%
	>=5         8%        10%

Uses a switch statement to first determine the number of dependents. From there,
it checks against the marital status and sets deduction to the proper tax percentage,
then returns deduction to the method call.
*/
double employee::taxDeduction(employee lEmp)
{
	
	double taxPercent = 0.0; //The percentage of pay to be deducted for taxes.
	double deduction = 0.0;  //The monetary value of pay deducted for taxes.

	switch (lEmp.getDependents())
	{
		case 0:
		case 1:
		case 2:
		{
			if (lEmp.getMaritalStatus() == "m")
			{
				taxPercent = 0.20;
				deduction = lEmp.getWeeklyPay() * taxPercent;
				return deduction;
			}
			else
			{
				taxPercent = 0.25;
				deduction = lEmp.getWeeklyPay() * taxPercent;
				return deduction;
			}
		}
		case 3:
		{
			if (lEmp.getMaritalStatus() == "m")
			{
				taxPercent = 0.15;
				deduction = lEmp.getWeeklyPay() * taxPercent;
				return deduction;
			}
			else
			{
				taxPercent = 0.20;
				deduction = lEmp.getWeeklyPay() * taxPercent;
				return deduction;
			}
		}
		case 4:
		{
			if (lEmp.getMaritalStatus() == "m")
			{
				taxPercent = 0.10;
				deduction = lEmp.getWeeklyPay() * taxPercent;
				return deduction;
			}
			else
			{
				taxPercent = 0.15;
				deduction = lEmp.getWeeklyPay() * taxPercent;
				return deduction;
			}
		}
		default:
		{
			if (lEmp.getMaritalStatus() == "m")
			{
				taxPercent = 0.08;
				deduction = lEmp.getWeeklyPay() * taxPercent;
				return deduction;
			}
			else
			{
				taxPercent = 0.10;
				deduction = lEmp.getWeeklyPay() * taxPercent;
				return deduction;
			}
		}
	}
}

/*Takes an object parameter and calls the getWeeklyPay method,
then subtracts the tax deduction amount from it, and returns the value.*/
double employee::payAfterTax(employee lE) const
{
	return lE.getWeeklyPay() - lE.taxDeduction(lE);
}

/*A separate method to print the amount of money deducted for taxes,
and also the employee's net pay after taxes.*/
void printTaxInfo(employee i)
{
	cout << "Tax deduction: " << i.taxDeduction(i) << endl;
	cout << "Pay after taxes: " << i.payAfterTax(i) << endl;
}

int main()
{
	employee* ptr1 = NULL; //Creates an employee pointer, initializes to NULL;
	employee* ptr2 = NULL; //Creates an employee pointer, initializes to NULL;
	employee myE("POINTER", 0.0, "None", 0); //Creates and initializes an employee object.

	ptr1 = &myE;        //ptr1 points to myE
	ptr2 = new employee;//ptr2 points to a new, dynamically allocated employee object.
	ptr1->print();      //ptr1 calls the print method of the object it's pointing to.
	ptr2->print();      //ptr2 calls the print method of the object it's pointing to.
	ptr1->setDependents(7);//ptr1 calls the setDependents method and passes a value of 7.
	delete ptr2;        //deletes the dynamically allocated object. This is what you are
	                    //SUPPOSED to do before reassigning ptr2, otherwise you'd be left
	                    //with a dangling pointer.
	ptr2 = &myE;        //ptr2 points to myE
	//There are now two pointers (ptr1 and ptr2) pointing at myE.

	//A vector of 3 employee objects
	vector<employee> myList(3);

	employee e0("Jim", 800.0, "m", 2);
	myList[0] = e0;

	employee e1("Mike", 600.0, "s", 6);
	myList[1] = e1;

	employee e2("Duane", 1500.0, "s", 0);
	myList[2] = e2;

	//Cycles through the array printing information for all employees.
	for (int i = 0; i < myList.size(); i++)
	{
		myList[i].print();
		printTaxInfo(myList[i]);
	}	

	system("PAUSE");
    return 0;
}

