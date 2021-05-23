#include <stdio.h>
#include <stdlib.h>

double parseSum();
double parseProduct();
double parseFactor();
char *x;

double parseSum()
{
	double left = parseProduct();
	while (*x == '+') {
		++x;
		double right = parseProduct();
		left = left + right;
	}
	return left;
}

double parseProduct()
{
	double left = parseFactor();
	while (*x == '*') {
		++x;
		double right = parseFactor();
		left = left * right;
	}
	return left;
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

	printf("%f\n", result);

	return 0;
}
