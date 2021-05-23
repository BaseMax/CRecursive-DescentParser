int parseSum();
int parseProduct();
int parseFactor();
char *x;

int parseSum()
{
	int pro1 = parseProduct();
	while (*x == '+') {
		++x;
		int pro2 = parseProduct();
		pro1 = pro1 + pro2;
	}
	return pro1;
}

int parseProduct()
{
	int fac1 = parseFactor();
	while (*x == '*') {
		++x;
		int fac2 = parseFactor();
		fac1 = fac1 * fac2;
	}
	return fac1;
}

int parseFactor()
{
	if (*x >= '0' && *x <= '9')
		return *x++ - '0';
	else if (*x == '(') {
		++x; // except '('
		int sum = parseSum();
		++x; // except ')'
	`	return sum;
	}
	else
		printf("Excepted digit but found %c\n", *x);
}

int main()
{
	int result;

	x = "2*3+4*5";
	result = parseFactor();

	x = "2*3+4*5";
	result = parseProduct();

	x = "2*(3+4)";
	result = parseSum();

	return 0;
}
