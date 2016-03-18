/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>


void number_to_str(float number, char *str,int afterdecimal){
	int i = 0, a, rev = 0, n, count = 0;
	while (i < afterdecimal)
	{
		number = number * 10;
		i++;
		count++;
	}
	n = number;
	i = 0;
	if (n < 0)
	{
		n = n*-1;
		str[i] = '-';
		i++;
	}
	while (n > 0)
	{
		a = n % 10;
		rev = rev * 10 + a;
		n = n / 10;
	}
	while (rev > 0)
	{
		a = rev % 10;
		str[i] = a + 48;
		i++;
		rev = rev / 10;
	}
	while (afterdecimal > 0)
	{
		str[i] = str[i - 1];
		i--;
		afterdecimal--;
	}
	if (count > 0)
	{
		str[i] = '.';
		*(str + i + count + 1) = '\0';
	}
	else
		*(str + i) = '\0';
	puts(str);

}
