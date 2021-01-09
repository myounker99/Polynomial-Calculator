#include "Polynomial.h"
#include <iostream>
#include <cmath>

using namespace std;

Term Polynomial::termArray[100];
int Polynomial::free = 0;

Polynomial::Polynomial()
{
	start = free;
	finish = free;
}

float Polynomial::coeffOf(int e)
{
	for (int i = start; i <= finish; i++)
	{
		if (termArray[i].expo == e)
		{
			return termArray[i].coef;
		}
	}
	return 0;
}

int Polynomial::leadExpo()
{
	return termArray[start].expo;
}

Polynomial Polynomial::Add(Polynomial P)
{
	Polynomial C;
	int a = this->start; int b = P.start; C.start = free; float c;
	while((a <= this->finish)&&(b <= P.finish))
		switch (compare(termArray[a].expo, termArray[b].expo)) 
		{
			case '=':
				c = termArray[a].coef + termArray[b].coef;
				if (c != 0)
				{
					newTerm(c, termArray[a].expo);
					a++, b++;
				}
				break;
			case '<':
				newTerm(termArray[b].coef, termArray[b].expo);
				b++;
				break;
			case '>':
				newTerm(termArray[a].coef, termArray[a].expo);
				a++;
				break;
		}
	for (; a <= this->finish; a++)
	{
		newTerm(termArray[a].coef, termArray[a].expo);
	}
	for (; b <= P.finish; b++)
	{
		newTerm(termArray[b].coef, termArray[b].expo);
	}
	C.finish = free - 1;
	return C;
}

Polynomial Polynomial::Mult(Polynomial p)
{
	Polynomial C;
	C.start = free;
	for (int i = this->start; i <= this->finish; i++)
	{
		for (int j = p.start; j <= p.finish; j++)
		{
			newTerm(termArray[i].coef * termArray[j].coef, termArray[i].expo + termArray[j].expo);
		}
	}
	C.finish = free - 1;
	return C;
}

float Polynomial::eval(float f)
{
	float solution = 0;
	for (int i = start; i <= finish; i++)
	{
		solution += (pow(f, termArray[i].expo)) * termArray[i].coef;
	}
	return solution;
}

void Polynomial::newTerm(float c, int e)
{
	if (free >= 100)
	{
		cout << "Too many terms in polynomials.";
		return;
	}
	termArray[free].expo = e;
	termArray[free].coef = c;
	free++;
}

void Polynomial::addOneTerm(float c, int e)
{
	if (free >= 100)
	{
		cout << "Too many terms in polynomials.";
		return;
	}
	termArray[free].expo = e;
	termArray[free].coef = c;
	finish = free;
	free++;
	//the difference is this one moves the finish cursor
}


char Polynomial::compare(int a, int b)
{
	if (a == b)
		return '=';
	else if (a > b)
		return '>';
	else
		return '<';
}

ostream& operator<<(ostream& os, const Polynomial& p)
{
	for (int i = p.start; i <= p.finish; i++)
	{
		os << "+(" << p.termArray[i].coef << ")x^(" << p.termArray[i].expo << ")";
	}
	return os;
}