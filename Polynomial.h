#pragma once
#include <ostream>

struct Term
{
	int expo;
	float coef;
};

class Polynomial {
public:
	Polynomial();
	float coeffOf(int e);
	int leadExpo();
	Polynomial Add(Polynomial p);
	Polynomial Mult(Polynomial p);
	float eval(float f);
	char compare(int a, int b);
	void newTerm(float c, int e);
	friend std::ostream& operator<<(std::ostream&, const Polynomial&);
	void addOneTerm(float c, int e);

private:
	static Term termArray[];
	static int free;
	int start, finish;
};
