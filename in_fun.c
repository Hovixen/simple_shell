#include "main.h"
/**
 * handle_in - function handles the input given
 * Description: this function when called, handles
 * the input of the user, using the getLine function
 * @cmd_in: pointer to the string input given
 * @n: size(length) of the string input given
 * Return: returns void.
 */
void handle_in(char **cmd_in, size_t *n)
{
	ssize_t inRead = getline(cmd_in, n, stdin);
	if (inRead == -1)
	{
		if (feof(stdin))
		{
			free(*cmd_in);
			*cmd_in = NULL;
			exit(EXIT_SUCCESS);
		}
		exit(EXIT_FAILURE);
	}
	if ((*cmd_in)[inRead - 1] == '\n')
		(*cmd_in)[inRead - 1] = '\0';
}
