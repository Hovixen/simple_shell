#include "main.h"
/**
 * _strlen - Function checks for the size of characters
 * @cmd: string parameter
 * Return: returns the size of the string
 */
size_t _strlen(const char *cmd)
{
	size_t n;

	if (cmd == NULL)
	{
		/*fprintf(stderr, "Error: Input string is NULL in _strlen\n");*/
		perror("strlen");
		exit(EXIT_FAILURE);
	}
	for (n = 0; cmd[n]; n++)
		;
	return (n);
}
/**
 * *str_cpy - function copies charater from source to destination
 * @dest: pointer destination
 * @src: pointer source
 * Return: returns the destination pointer
 */
char *str_cpy(char *dest, char *src)
{
	int n = 0;

	while (src[n])
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = '\0';
	return (dest);
}
/**
 * *str_dup - function duplicates array to a pointer
 * @cmd: pointer to the array to be duplicated
 * Return: returns pointer of the duplicated array
 */
char *str_dup(char *cmd)
{
	size_t n;
	char *destptr;/*created pointer as destination*/

	if (cmd == NULL)
		return (NULL);
	n = _strlen(cmd);
	destptr = (char *)malloc(n + 1);/*adding a null terminator space*/
	if (destptr == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	str_cpy(destptr, cmd);
	return (destptr);
}
/**
 * *str_spn - Function checks the size of initial substring found in
 * a given set(array)
 * @cmd: substring to be checked
 * @sets: given sets(array)
 * Return: returns the size of the substing found in the given set
 */
size_t str_spn(const char *cmd, const char *sets)
{
	size_t c = 0, s = 0; /*iterate through cmd and sets*/
	int match;

	while (cmd[c])
	{
		match = 0;
		for (; sets[s]; s++)
		{
			if (cmd[c] == sets[s])
			{
				match = 1;
				break;
			}
		}
		if (!match)
			break;
		c++;
	}
	return (c);
}
