#ifndef PHARMACY_H
#define PHARMACY_H
#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Pharmacy
{

public:
	Pharmacy()
	{

	}

	void setMeds(string t, double p) //setters
	{
		int index = 0;
		for (string b : names)
		{
			if (t == b)
			{
				prices.at(index) = p;
				return;
			}
			index++;
		}

		// if not found
		names.push_back(t);
		prices.push_back(p);

	}
	//getters
	double getMeds(string t)
	{
		int index = 0;
		double cost = 0;
		for (string b : names)
		{
			if (t == b)
			{
				cost = prices.at(index);
			}
			index++;
		}


		return cost;
	}
	//print
	void printMeds()
	{
		int counter = 1;
		cout << "Medicine provided" << endl;
		for (int i = 0; i<prices.size(); i++)
		{
			cout << counter << "." << " " << names.at(i) << ": $" << prices.at(i) << endl;
			counter++;
		}
	}


private:

	vector<string> names = { "Insulin","Zanax","Morphine","Acetaminophen","Penicillin" };
	vector<double> prices = { 16.99,17.99,18.99,19.99,20.99 };
};
#endif
