#include <stdio.h>
#include <stdlib.h>

// global variable
char *x;

// functions
double parseNumber();
double parseFormulae();
double parseProduct();
double parseFactor();

double parseFormulae()
{
	double left = parseProduct();

	while (*x == '+') {
		++x;
		double right = parseProduct();
		left = left + right;
	}

	while (*x == '-') {
		++x;
		double right = parseProduct();
		left = left - right;
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

	while (*x == '/') {
		++x;
		double right = parseFactor();
		if(right == 0) {
			printf("runtime math error: cannot divide by zero\n");
			return left;
		}
		left = left / right;
	}

	return left;
}

double parseNumber()
{
	double number = 0;
	// return *x++ - '0';

	while(*x >= '0' && *x <= '9') {
		number = number * 10;
		number = number + *x - '0';
		++x;
	}

	if (*x == '.') {
		++x; // except '.'
		double weight = 1;
		while (*x > '0' && *x <= '9') {
			weight = weight/10;
			double scaled = (*x - '0') * weight;
			number = number + scaled;
			++x;
		}
	}

	return number;
}

double parseFactor()
{
	if (*x >= '0' && *x <= '9')
		return parseNumber();
	else if (*x == '(') {
		++x; // except '('
		double sum = parseFormulae();
		++x; // except ')'
		return sum;
	}
	else
		printf("Excepted digit but found %c\n", *x);
}

void test()
{
	double result;

	x = "5";
	result = parseNumber();

	x = "110";
	result = parseNumber();

	x = "3.14";
	result = parseNumber();

	x = "2*3+4*5";
	result = parseFactor();

	x = "2*3+4*5";
	result = parseProduct();

	x = "2*(3+4)";
	result = parseFormulae();
}

int main()
{
	double result;
	x = malloc(sizeof(char) * 200);

	while(1) {
		printf("calc> ");
		scanf("%s", x);
		result = parseFormulae();
		printf("%f\n", result);
	}

	return 0;
}
