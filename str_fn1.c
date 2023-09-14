#include "main.h"
/**
 * *str_cat - Function concatenates two strings together
 * @dest: destination of the string(pointer)
 * @src: source of the the string(pointer)
 * Return: returns the concatenated strings (dest)
 */
char *str_cat(char *dest, char *src)
{
	int d, s;

	for (d = 0; dest[d]; d++)
		;
	for (s = 0; src[s]; s++)
	{
		dest[d] = src[s];
		d++;
	}
	dest[d] = '\0';
	return (dest);
}
