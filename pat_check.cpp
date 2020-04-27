/***************************************************************
Problem: Classes lab- Pat_check.cpp
Description: You are to write a program that computes a patient s bill for a hospital stay. The different components
of the program are:
 The PatientAccount class
- Will keep patient’s personal information: Name, age, address, SSN
- Will keep track of patient’s chargeable items, mainly surgeries and pharmacy items
- Can print an itemized bill listing each item, its cost and the total cost.
- It will also keep track of the number of days spent in the hospital. The group must
decide on the hospital s daily rate.
 The Surgery class
- The Surgery class will have stored within it the charges for at least 5 types of surgery
- Has get/set methods to get/set the selected surgeries item for each object
- Has a function that prints a list of types of surgery items and their costs
The Pharmacy class
-The Pharmacy class will have stored within it the price of at least 5 types of medication
and the price of each.
- Has get/set methods to get/set the selected medication item for each object
- Has a function that prints a list of types of medications items and their costs
Note: you should use inheritance (if applicable) to avoid repeating code. Remember however that
inheritance must follow a natural relationship to its ancestors.
In the main program, there will be a menu that allows the user to:
1. Add new patient
a. Creates a new patient account object and asks user to supply the patient’s personal
information to populate this object
2. Display a patient’s detailed bill.
a. Display a numbered list of patients’ names
b. Asks user to select the patient’s number
c. Display a detailed FORMATTTED table of medications used, surgeries taken, and the
charge of each item.
d. The table will display a total cost at the end of table.
3. Check out a patient
a. Display a numbered list of patients’ names
b. Asks user to select the patient’s number
c. The patient’s record will be removed from the list of patients
4. Add surgery item to a patient’s account
a. Display a numbered list of patients’ names
b. Asks user to select the patient’s number
c. Display a numbered list of surgeries and their costs
d. Asks user to select the surgery to add
e. Adds the given surgery to the user’s account
5. Add pharmacy item to a patient’s account
a. Display a numbered list of patients’ names
b. Asks user to select the patient’s number
c. Display a numbered list of medications and their costs
d. Asks user to select the medication to add
e. Adds the given medication to the user’s account
NOTE: 1st design your objects and let me review your design before going further

Name: John Bennett
Partner:Jake Forester
ID: 1104771
Date: 3/18/2017
Status: complete
****************************************************************/



#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<cctype>
#include<iomanip>
#include"Pharm.h"
#include "PatientAccount.h"
#include "Surgery.h"
using namespace std;
const double DAILY_RATE = 425.81;
/*************************************
functions
**************************************/
void sentence(int flag)
{
	switch (flag)
	{
	case 0: cout << "\n select a patient to view bill." << endl;
		break;
	case 1: cout << "\n select a patient to add surgery item" << endl;
		break;
	case 2: cout << "\n select a patient to add medicine to" << endl;
		break;
	case 3: cout << "\n select a patient to check out" << endl;
		break;
	default: break;
	}
	return;
}
void printList(vector<PatientAccount> &list)
{
	int counter = 1;

	//cout << "         NAME              SSN         AGE                      ADDRESS        DAYS IN HOSPITAL" << endl;
	cout << "   "
		<< setw(20) << setfill(' ') << "Name"
		<< setw(15) << setfill(' ') << "SSN"
		<< setw(7) << setfill(' ') << "AGE"
		<< setw(30) << setfill(' ') <<  "ADDRESS"
		<< setw(5) << setfill(' ') << "DAYS" <<endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	for (PatientAccount P : list)
	{
		cout << counter << "."
			<< setw(20) << setfill(' ') << P.getName()
			<< setw(16) << setfill(' ') << P.getSSN()
			<< setw(7) << setfill(' ') << P.getAge()
			<< setw(30) << setfill(' ') << P.getAddress()
			<< setw(5) << setfill(' ') << P.getDays() << "  " << endl;
		counter++;
	}
}
int SelectPatient(vector<PatientAccount> &list, int flag)
{
	string input;
	int choice;
	printList(list);
	sentence(flag);
	do {
		cout << "enter the number of the patient: ";
		getline(cin, input);
		istringstream(input) >> choice;
	} while (!(istringstream(input) >> choice) || (choice>list.size() || choice<1));
	return (choice-1);
}
void addPatient(vector<PatientAccount> &list)
{
	PatientAccount newPat;
	string name, SSN, address, strAge, strDays;
	int age, daysIn;
	double totalCharges, dailyRate;
	do {
		cout << "Enter the patient's full Name: ";
		getline(cin, name);
		if (name.size() > 20)
			cout << "max 20 characters." << endl;
	} while (name.size() > 20 || name.size()<=0);
	newPat.setName(name);
	do {
		cout << "\nEnter the patient's SSN: ";
		getline(cin, SSN);
		if (SSN.size() != 11)
			cout<<"must contain 11 characters" << endl;
	} while (SSN.size()!=11);
	
	newPat.setSSN(SSN);
	cout << "Enter the patient's address: ";
	getline(cin, address);
	newPat.setAddress(address);
	do {
		cout << "Enter the patient's age: ";
		getline(cin, strAge);
		istringstream(strAge) >> age;
	} while (age < 0 || !(istringstream(strAge) >> age));
	newPat.setAge(age);
	do {
		cout << "Enter the patient's days in the hospital: ";
		getline(cin, strDays);
		istringstream(strDays) >> daysIn;
	} while (daysIn < 0 || !(istringstream(strDays) >> daysIn));
	newPat.setDays(daysIn);
	newPat.setRate(DAILY_RATE);
	newPat.setSurgeries();
	list.push_back(newPat);
	return;
	
}
void displayBill(vector<PatientAccount> &list)
{
	
	string input;
	int flag = 0;
	int pos = SelectPatient(list, flag);
	cout << "\n\n\n\n\n" << endl;
	list.at(pos).printBill();
	return;

}
void checkOutPatient(vector<PatientAccount> &list)
{

		int flag = 3;
		int pos = SelectPatient(list, flag);
		cout << "\n" << endl;
		//list.at(pos).~PatientAccount();
		list.erase(list.begin() + pos);
		return;
}
void addSurgery(vector<PatientAccount> &list)
{
	
	string input, input1;
	int flag = 1;
	int choice;
	int pos=SelectPatient(list, flag);
	char YorN;
	Surgery s1;
	s1.printSurgeryList();
	do {

		do {
			cout << "Enter item number (1-5): ";
			getline(cin, input);
			istringstream(input) >> choice;
		} while (!(istringstream(input) >> choice || (choice > 5) || choice < 1));
		switch (choice)
		{
		case 1:
			list.at(pos).addSurgery("femur");
			break;
		case 2:
			list.at(pos).addSurgery("wrist");
			break;
		case 3:
			list.at(pos).addSurgery("heart");
			break;
		case 4:
			list.at(pos).addSurgery("brain");
			break;
		case 5:
			list.at(pos).addSurgery("eye");
			break;
		default: break;
		}
		cout << "add another item to account?(Y/N)" << endl;
		getline(cin, input1);
		istringstream(input1) >> YorN;
	} while (!(istringstream(input1) >> YorN) || toupper(YorN) == 'Y');
	return;
}
void addMeds(vector<PatientAccount> &list)
{
	
	string input, input1;
	int flag = 2;
	int choice;
	int pos= SelectPatient(list, flag);
	char YorN;
	Pharmacy s1;
	s1.printMeds();
	do {

		do {
			cout << "Enter item number (1-5): ";
			getline(cin, input);
			istringstream(input) >> choice;
		} while (!(istringstream(input) >> choice || (choice > 5) || choice < 1));
		switch (choice)
		{
		case 1:
			list.at(pos).addMeds("Insulin");
			break;
		case 2:
			list.at(pos).addMeds("Zanax");
			break;
		case 3:
			list.at(pos).addMeds("Morphine");
			break;
		case 4:
			list.at(pos).addMeds("Acetaminophen");
			break;
		case 5:
			list.at(pos).addMeds("Penicillin");
			break;
		default: break;
		}
		cout << "add another item to account?(Y/N)" << endl;
		getline(cin, input1);
		istringstream(input1) >> YorN;
	} while (!(istringstream(input1) >> YorN) || toupper(YorN) == 'Y');
	return;
}



/*************************************
main
**************************************/
int main()
{
	vector<PatientAccount> patientList;
	int choice;
	string input;
do{
	cout << "1. add new patient."
		<< "\n2. display patient's bill."
		<< "\n3. check out a patient."
		<< "\n4. add surgery item."
		<< "\n5. add pharmacy item."
		<< "\n6. exit." << endl;
	
	do
	{
		cout << "\nEnter Choice: ";
		getline(cin, input);
		istringstream(input) >> choice;
	} while (!(istringstream(input) >> choice) || ((choice < 1) || (choice > 6)));

		switch (choice)
		{
		case 1:
			addPatient(patientList);
			break;
		case 2:
			displayBill(patientList);
			break;
		case 3:
			checkOutPatient(patientList);
			break;
		case 4:
			addSurgery(patientList);
			break;
		case 5:
			addMeds(patientList);
			break;
		case 6:
			cout << "\n\n\ngoodbye\n\n\n";
			break;
		default:
			break;
		}
	} while (choice != 6);
	return 0;
}