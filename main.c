#include <stdio.h>
#include <stdlib.h>

double parseSum();
double parseProduct();
double parseFactor();
char *x;

double parseSum()
{
	double pro1 = parseProduct();
	while (*x == '+') {
		++x;
		double pro2 = parseProduct();
		pro1 = pro1 + pro2;
	}
	return pro1;
}

double parseProduct()
{
	double fac1 = parseFactor();
	while (*x == '*') {
		++x;
		double fac2 = parseFactor();
		fac1 = fac1 * fac2;
	}
	return fac1;
}

double parseFactor()
{
	if (*x >= '0' && *x <= '9')
		return *x++ - '0';
	else if (*x == '(') {
		++x; // except '('
		double sum = parseSum();
		++x; // except ')'
		return sum;
	}
	else
		printf("Excepted digit but found %c\n", *x);
}

double main()
{
	double result;

	x = "2*3+4*5";
	result = parseFactor();

	x = "2*3+4*5";
	result = parseProduct();

	x = "2*(3+4)";
	result = parseSum();

	return 0;
}
