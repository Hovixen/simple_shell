#include "main.h"

/**
 * promptexec - Function process and executes the command input
 * @cmd: command parameter passed
 * Description: This function would create a fork process for
 * the user input command and execute it
 * Return: return void
 */
void promptexec(const char *cmd)
{
	int stat;
	const char *const execom[] = {cmd, NULL};
	pid_t bokangsh_pid = fork();/*shell child proccess*/

	if (bokangsh_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (bokangsh_pid == 0)
	{
		if (execve(cmd, (char *const *)execom, NULL) == -1)
		{
			perror("bokangsh");
			exit(EXIT_FAILURE);
		}
	}
	else
		waitpid(bokangsh_pid, &stat, 0);
}
