#include "main.h"

/**
 * promptexec - Function process and executes the command input
 * @param: pointer to the struct
 * Description: This function would create a fork process for
 * the user input command and execute it
 * Return: return void
 */
int promptexec(bshell *param)
{
	int stat, status, existing;
	char **execom = argTok(param->cmd_in);
	char cmdPath[1024];

	existing = _iscmd_inPath(execom[0], cmdPath);
	if (existing)
	{
		pid_t bokangsh_pid = fork();/*shell child proccess*/

		if (bokangsh_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (bokangsh_pid == 0)
		{
			/*if (str_spn(param->cmd_in, DELIMS) == _strlen(param->cmd_in))*/
			 /* exit(EXIT_FAILURE);*/
			if (execve(cmdPath, execom, NULL) == -1)
			{
				perror(param->avec[0]);
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
	}
	else
		execErr(execom[0]);
	stat = -1;
	free_arg(execom);
	return (stat);
}
