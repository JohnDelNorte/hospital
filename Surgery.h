#ifndef SURGERY_H
#define SURGERY_H
#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Surgery
{
private:

	vector<string> names = { "femur","wrist","heart","brain","eye" };
	vector<double> prices = { 16.99,17.99,18.99,19.99,20.99 };
public:
	Surgery()
	{

	}
	//setters
	void setSurgery(string t, double p)
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
	double getSurgery(string t)
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
	void printSurgeryList()
	{
		int counter = 1;
		cout << "surgical procedures: " << endl;
		for (int i = 0; i<prices.size(); i++)
		{
			cout <<counter<<"."<<" "<< names.at(i) << ": $" << prices.at(i) << endl;
			counter++;
		}
	}

};
#endif
