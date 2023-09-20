#include "main.h"
/**
 * execErr - function checks for error command not found
 * @cmd: command input
 * @cmd_in: command argument
 * @counts: gives th error line count
 * Return: returns void
 */
int execErr(char *cmd, char *cmd_in, int counts)
{
	int len;
	char *errmsg;
	char *counter = conItoA(counts);

	len = _strlen(cmd_in) + _strlen(counter);
	len += _strlen(cmd) + 16;
	errmsg = malloc(sizeof(char) * (len + 1));

	if (errmsg == NULL)
	{
		free(counter);
		return;
	}

	str_cpy(errmsg, cmd_in);
	str_cat(errmsg, ": ");
	str_cat(errmsg, counter);
	str_cat(errmsg, ": ");
	str_cat(errmsg, cmd);
	str_cat(errmsg, ": not found\n");
	str_cat(errmsg, "\0");

	write(STDOUT_FILENO, errmsg, _strlen(errmsg));
	free(counter);
	free(errmsg);
	return (127);
}
