#include <iostream>

using namespace std;

class PatientAccount
{
public:
	double totcharges;
	int nodays;
	void calcharges(int s, int m)
	{
		int dailyrate = 100;
		cout << "\n Enter No of Days admitted";
		cin >> nodays;
		int total = s + m + dailyrate;
		cout << "\n Amount Per day=" << total;
		cout << "\n Enter the patient discharge or not(Y or N)";
		char c;
		cin >> c;

		if (c == 'Y')
		{
			int mnthrate;
			mnthrate = total*nodays;
			cout << "\n Total Bill=" << mnthrate;
		}

	}

};


class Surgery
{
public:
	int BreastSurgery()
	{
		int BreastSurgery = 2000;
		cout << BreastSurgery;
		return BreastSurgery;
	}
	int EndocrineSurgery()
	{
		int EndocrineSurgery = 3000;
		return EndocrineSurgery;
	}
	int GeneralSurgery()
	{
		int GeneralSurgery = 4000;
		return GeneralSurgery;
	}
	int HandSurgery()
	{
		int HandSurgery = 5000;
		return HandSurgery;
	}
	int OrthopedicSurgery()
	{
		int OrthopedicSurgery = 2500;
		return OrthopedicSurgery;
	}


};

class Phamacy
{
public:
	int LabTest()
	{
		int LabTest = 500;
		cout << LabTest;
		return LabTest;
	}
	int xray()
	{
		int xray = 300;
		return xray;
	}
	int bloodtest()
	{
		int bloodtest = 450;
		return bloodtest;
	}
	int pulseTest()
	{
		int pulseTest = 400;
		return pulseTest;
	}
	int generalTest()
	{
		int generalTest = 600;
		return generalTest;
	}
};
int main()
{
	cout << "\n =============================================================================\n";
	cout << "\t\t\t PATIENT BILLING\n";
	cout << "\n =============================================================================\n";
	cout << "\n Types of Surgery In Hospital";
	cout << "\n =============================================================================\n";
	cout << "\n 1.BreastSurgery";
	cout << "\n 2.EndocrineSurgery";
	cout << "\n 3.GeneralSurgery";
	cout << "\n 4.HandSurgery";
	cout << "\n 5.OrthopedicSurgery";
	cout << "\n =============================================================================\n";
	cout << "\n Types of Medication In Hospital";
	cout << "\n =============================================================================\n";
	cout << "\n 1.LabTest";
	cout << "\n 2.xray";
	cout << "\n 3.bloodtest";
	cout << "\n 4pulseTest";
	cout << "\n 5.generalTest";
	cout << "\n =============================================================================\n";
	PatientAccount p;
	Surgery s;
	Phamacy p1; int scharges, mcharges;
	int typeSurgery;
	int typem;

	cout << "\n Enter Type of Surgery";
	cout << "\n 1.BreastSurgery";
	cout << "\n 2.EndocrineSurgery";
	cout << "\n 3.GeneralSurgery";
	cout << "\n 4.HandSurgery";
	cout << "\n 5.OrthopedicSurgery";
	cin >> typeSurgery;
	cout << "\n =============================================================================\n";

	switch (typeSurgery)
	{
	case 1:
		scharges = s.BreastSurgery();
		break;
	case 2:
		scharges = s.EndocrineSurgery();
		break;
	case 3:
		scharges = s.GeneralSurgery();
		break;

	case 4:
		scharges = s.HandSurgery();
		break;
	case 5:
		scharges = s.OrthopedicSurgery();
		break;
	default:
		cout << "Enter valid choice";
	}
	cout << "\n Enter Type of Medication";
	cout << "\n =============================================================================\n";
	cout << "\n 1.LabTest";
	cout << "\n 2.xray";
	cout << "\n 3.bloodtest";
	cout << "\n 4.pulseTest";
	cout << "\n 5.generalTest";
	cin >> typem;
	switch (typem)
	{
	case 1:
		mcharges = p1.LabTest();
		break;
	case 2:
		mcharges = p1.xray();
		break;
	case 3:
		mcharges = p1.bloodtest();
		break;

	case 4:
		mcharges = p1.pulseTest();
		break;
	case 5:
		mcharges = p1.generalTest();
		break;
	default:
		cout << "Enter valid choice";
	}


	p.calcharges(scharges, mcharges);



	return 0;
}