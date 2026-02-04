/* Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n); */

int	is_power_of_2(unsigned int n)
{
	if (n <= 0) 
		return 0;
	if (n == 1)
		return 1;	
	while (n != 1) {
		if (n % 2 != 0)
			return 0;
		n = n / 2;
	}
	return 1;
}

/*
int main()
{
	unsigned int n = 1024;
	if ((is_power_of_2(n)) == 1)
		printf("power");
	else printf("not power");
} */
