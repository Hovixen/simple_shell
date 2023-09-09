#include "main.h"

/**
 * promptexec - Function process and executes the command input
 * @cmd: command parameter passed
 * @avec: string pointer to the argument vector
 * Description: This function would create a fork process for
 * the user input command and execute it
 * Return: return void
 */
void promptexec(const char *cmd, const char *avec)
{
	int stat;
	char *execom[] = {(char *)cmd, NULL};
	pid_t bokangsh_pid = fork();/*shell child proccess*/

	if (bokangsh_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (bokangsh_pid == 0)
	{
		if (execve(execom[0], execom, NULL) == -1)
		{
			/*perror((const char *)&avec[0]);*/
			perror(avec);
			exit(EXIT_FAILURE);
		}
	}
	else
		waitpid(bokangsh_pid, &stat, 0);
}
