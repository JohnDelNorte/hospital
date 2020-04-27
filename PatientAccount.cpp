
#include "PatientAccount.h"
#include"Surgery.h";
#include<string>
using namespace std;

/***********************************
Setters
*************************************/
void PatientAccount::setDays(int daysIn)
{
	days = daysIn;
}
void PatientAccount::setAge(int years)
{
	age = years;
}
void PatientAccount::setCharges(double amount)
{
	totalCharges = amount;
}
void PatientAccount::setSSN(string number)
{
	SSN = number;
}
void  PatientAccount::setAddress(string add)
{
	address = add;
}
void  PatientAccount::setName(string fname)
{
	name = fname;
}
void PatientAccount::setRate(double rate)
{
	DAILY_RATE = rate;
}
/***********************************
Getters
*************************************/
int PatientAccount::getAge()const
{
	return age;
}
int  PatientAccount::getDays()const
{
	return days;
}
double PatientAccount::getCharges()const
{
	return totalCharges;
}
string  PatientAccount::getName()const
{
	return name;
}
string  PatientAccount::getSSN()const
{
	return SSN;
}
string  PatientAccount::getAddress()const
{
	return address;
}



