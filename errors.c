#include "main.h"

void execErr(char *cmd)
{
	write(STDERR_FILENO, "Command not found: ", 19);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, "\n", 1);
}
