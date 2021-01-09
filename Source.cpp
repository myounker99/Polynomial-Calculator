#include <iostream>
#include "Polynomial.h"

using namespace std;

void addP();
void multP();
void evalP();
void findC();
void largestE();

int main()
{
	int request = 1;

	while (request > 0 && request <= 5)
	{
		cout << "What do you wish to do: " << endl;
		cout << "1) Add 2 polynomials." << endl;
		cout << "2) Multiply 2 polynomials." << endl;
		cout << "3) Evaluate a polynomial at a given value." << endl;
		cout << "4) Find the coefficient of a give exponent for a given polynomial." << endl;
		cout << "5) Find the largest exponent in a given polynomial." << endl;
		cout << "6) exit." << endl;
		cin >> request;
		switch (request)
		{
		case 1:
			addP();
			break;
		case 2:
			multP();
			break;
		case 3:
			evalP();
			break;
		case 4:
			findC();
			break;
		case 5:
			largestE();
			break;
		}
	}

	return 0;
}

void addP()
{
	cout << endl << endl << "Please input the first polynomial in the form of: (non-zero coefficient, exponent) pairs, in descending order of exponents: (one pair at a time, and enter -100 -100 to finish)" << endl;
	Polynomial A; int e = -1; float c = -1;
	while (e != -100 && c != -100)
	{
		cin >> c >> e;
		if (c == -100 && e == -100)
			break;
		A.addOneTerm(c, e);
	}
	
	cout << endl << endl << "Please input the second polynomial in the form of: (non-zero coefficient, exponent) pairs, in descending order of exponents: (one pair at a time, and enter -100 -100 to finish)" << endl;
	e = -1; c = -1;
	Polynomial B;
	while (e != -100 && c != -100)
	{
		cin >> c >> e;
		if (c == -100 && e == -100)
			break;
		B.addOneTerm(c, e);
	}
	Polynomial C = A.Add(B);

	cout << endl << "Result: " << C << endl << endl;

}

void multP()
{
	cout << endl << endl << "Please input the first polynomial in the form of: (non-zero coefficient, exponent) pairs, in descending order of exponents: (one pair at a time, and enter -100 -100 to finish)" << endl;
	Polynomial A; int e = -1; float c = -1;
	while (e != -100 && c != -100)
	{
		cin >> c >> e;
		if (c == -100 && e == -100)
			break;
		A.addOneTerm(c, e);
	}

	cout << endl << endl << "Please input the second polynomial in the form of: (non-zero coefficient, exponent) pairs, in descending order of exponents: (one pair at a time, and enter -100 -100 to finish): " << endl;
	e = -1; c = -1;
	Polynomial B;
	while (e != -100 && c != -100)
	{
		cin >> c >> e;
		if (c == -100 && e == -100)
			break;
		B.addOneTerm(c, e);
	}

	Polynomial C = A.Mult(B);

	cout << endl << "Result: " << C << endl << endl;
}

void evalP()
{
	cout << endl << endl << "Please input the polynomial in the form of: (non-zero coefficient, exponent) pairs, in descending order of exponents: (one pair at a time, and enter -100 -100 to finish): " << endl;
	Polynomial A; int e = -1; float c = -1; float x = 0;
	while (e != -100 && c != -100)
	{
		cin >> c >> e;
		if (c == -100 && e == -100)
			break;
		A.addOneTerm(c, e);
	}
	cout << endl << endl << "Enter the number to evaluate with: " << endl;
	cin >> x;
	cout << endl << "The poly (" << A << ") evaluated at " << x << " is : " << A.eval(x) << endl << endl;
}

void findC()
{
	cout << endl << endl << "Please input the polynomial in the form of: (non-zero coefficient, exponent) pairs, in descending order of exponents: (one pair at a time, and enter -100 -100 to finish): " << endl;
	Polynomial A; int e = -1; float c = -1; int x = 0;
	while (e != -100 && c != -100)
	{
		cin >> c >> e;
		if (c == -100 && e == -100)
			break;
		A.addOneTerm(c, e);
	}
	cout << endl << endl << "Find coefficient with exponent: " << endl;
	cin >> x;
	cout << endl << "Result: " << A.coeffOf(x) << endl << endl;
}

void largestE()
{
	cout << endl << endl << "Please input the polynomial in the form of: (non-zero coefficient, exponent) pairs, in descending order of exponents: (one pair at a time, and enter -100 -100 to finish): " << endl;
	Polynomial A; int e = -1; float c = -1; int x = 0;
	while (e != -100 && c != -100)
	{
		cin >> c >> e;
		if (c == -100 && e == -100)
			break;
		A.addOneTerm(c, e);
	}
	cout << endl << "Result: " << A.leadExpo() << endl << endl;
}
