#include "main.h"
/**
 * fork_sh - function creates the child process of the shell
 * @cmd: command path parameter passed for execution
 * @args: comman argument passed for execution
 * @cmd_in: argument vector
 * Return: returns the stat value of the process.
 */

int fork_sh(char *cmd, char **args, char *cmd_in)
{
	int status, stat;
	pid_t bokangsh_pid = fork();/*shell child proccess*/

	if (bokangsh_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (bokangsh_pid == 0)
	{
		if (str_spn(cmd, DELIMS) == _strlen(cmd))
		{
			free(cmd);
			exit(EXIT_FAILURE);
		}
		if (execve(cmd, args, environ) == -1)
		{
			perror(cmd_in);
			free(args);
			free(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(bokangsh_pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(status))
			stat = WEXITSTATUS(status);
	}
	return (stat);
}
