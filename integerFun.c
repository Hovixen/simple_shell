#include "main.h"
/**
 * numLen - function gets the length of a given number
 * @num: number parameter given
 * Return: returns the number count of the given number
 */
int numLen(int num)
{
	int numcount = 0;

	if (num == 0)
		return (1);
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		numcount++;
		num /= 10;
	}
	return (numcount);
}
/**
 * *conItoA - Function converts integer to ASCII
 * @num: integer parameter
 * Return: returns a pointer to the string
 */
char *conItoA(int num)
{
	unsigned int n;
	int len = numLen(num);
	/*pointer to hold the string*/
	char *buff = malloc(sizeof(char) * (len + 1));

	if (buff == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	buff[len] = '\0';
	if (num == 1)
	{
		buff[0] = '1';
		return (buff);
	}
	if (num < 0)
	{
		n = -num;
		buff[0] = '-';
	}
	else
	{
		n = num;
		buff[0] = '0';
	}
	while (n > 0)
	{
		buff[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (buff);
}
