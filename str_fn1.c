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

char *strr_chr(char *cmd, int c)
{
	char *last_occur = NULL;

	while (*cmd)
	{
		if (*cmd == c)
			last_occur = cmd;
		cmd++;
	}
	return (last_occur);

}
/**
 * str_cmp - function compares two strings
 * @cmd: first string
 * @str: second string
 * Return: return 0 or the string difference
 */
int str_cmp(char *cmd, char *str)
{
	while (*cmd && *str)
	{
		if (*cmd != *str)
			return (1);
		cmd++;
		str++;
	}
	if (*cmd || *str)/*if one string is longer than the other one*/
		return (0);
	return (0);
}
