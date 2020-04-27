#ifndef PATIENT_H
#define PATIENT_H
#include<string>
#include"Surgery.h";
#include"Pharm.h"
using namespace std;

class PatientAccount : public Surgery, public Pharmacy
{
private:
	string name, SSN, address;
	vector<string> surgeries;
	vector<string> medicine;
	int days, age;
	double totalCharges, DAILY_RATE;
public:

	//constructors
	PatientAccount()
	{
		name = "JohnDoe";
		SSN = "123-45-1234";
		address = "123 fake street";
		days = 0;
		totalCharges = 0.0;
		surgeries;
	}


	//setters
	void setDays(int);
	void setAge(int);
	void setCharges(double);
	void setRate(double);
	void setSSN(string);
	void setAddress(string);
	void setName(string);
	void setSurgeries()
	{
		surgeries;
		return;
	}
	

	//getters
	int getAge()const;
	int getDays()const;
	double getCharges()const;
	string getName()const;
	string getSSN()const;
	string getAddress()const;
	//other
	void addSurgery(string s)
	{
		surgeries.push_back(s);
	}
	void addMeds(string s)
	{
		medicine.push_back(s);
	}
	double calcCharges()
	{
		totalCharges = 0.0;
		double cost;
		for (int i = 0; i<surgeries.size(); i++)
		{
			cost = Surgery::getSurgery(surgeries.at(i));
			totalCharges += cost;
		}
		totalCharges += (days*DAILY_RATE);
		//for(int i=0; i<medication.size(); i++)
		return totalCharges;
	}
	void printBill()
	{
		double bill = 0;
		cout << "Surgeries: " << endl;
		for (int i = 0; i < surgeries.size(); i++)
		{
			cout << surgeries.at(i) << " for $" << Surgery::getSurgery(surgeries.at(i)) << endl;
			bill += getSurgery(surgeries.at(i));

		}
		cout << endl;
		cout << "Medicine:" << endl;
		for (int i = 0; i < medicine.size(); i++)
		{
			cout << medicine.at(i) << " for $" << Pharmacy::getMeds(medicine.at(i)) << endl;
			bill += getMeds(medicine.at(i));
		}

		cout << endl << "Days in hospital: " << days << endl;
		cout << "Daily rate:      $" << DAILY_RATE << endl;
		cout << "Day fee charge:  $" << (days*DAILY_RATE) << endl;
		bill += (days*DAILY_RATE);
		cout << "Total bill:      $" << bill << endl << endl;
	}




};

#endif

