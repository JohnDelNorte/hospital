#include<string>
#include<iostream>
#include<iomanip>
#include<cctype>
#include<vector>
#include "PatientAccount.h"
using namespace std;


void printList(vector<PatientAccount> &list)
{
	int counter = 1;

	//cout << "         NAME              SSN         AGE                      ADDRESS        DAYS IN HOSPITAL" << endl;
	cout << "   "
		<< setw(20) << setfill(' ') << "Name"
		<< setw(15) << setfill(' ') << "SSN"
		<< setw(7) << setfill(' ') <<  "AGE"
		<< setw(25) << setfill(' ') <<left<< "ADDRESS"<<right
		<< setw(5) << setfill(' ') << "DAYS IN" << "  " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	for (PatientAccount P : list)
	{
		cout << counter << ". "
			<< setw(20) << setfill(' ') << P.getName()
			<< setw(15) << setfill(' ') << P.getSSN()
			<< setw(7) << setfill(' ') << P.getAge()
			<< setw(30) << setfill(' ') << P.getAddress()
			<< setw(5) << setfill(' ') << P.getDays() << "  " << endl;
		counter++;
	}
}
int main()
{
	vector<PatientAccount> patList;
	PatientAccount P1, P2, P3;
	P1.setName("John");
	P1.setSSN("222-22-2222");
	P1.setAge(29);
	P1.setDays(14);
	P1.setAddress("123 fake road denver co.");
	
	P2.setName("John edwards smith");
	P2.setAge(29);
	P1.setSSN("222-22-2222");
	P2.setDays(14);
	P2.setAddress("123 fake town.");
	
	P3.setName("John jacob");
	P1.setSSN("222-22-2222");
	P3.setAge(29);
	P3.setDays(14);
	P3.setAddress("123 fake city fake st.");

	patList.push_back(P1);
	patList.push_back(P2);
	patList.push_back(P3);

	printList(patList);
	return 0;
}