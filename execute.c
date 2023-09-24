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
	int stat = 0/*status,*/;
	char **execom = argTok(param->cmd_in);
	char cmdPath[MAX_BUFF];

	if (execom == NULL)
	{
		free_arg(execom);
		free(param->cmd_in);
		return (0);
	}
	if (str_cmp(execom[0], "exit") == 0)
	{
		free_arg(execom);
		free(param->cmd_in);
		exit_sh();
	}
	else if (str_cmp(execom[0], "env") == 0)
		environment();
	else
	{
//		if (execom[0][0] == '.' && execom[0][1] == '/')
//			stat = fork_sh(execom[0], execom, param->avec[0]);
//		else 
//
		if (_iscmd_inPath(execom[0], cmdPath))
		{
			stat = fork_sh(cmdPath, execom, param->avec[0]);
		}
		else
		{
			stat = fork_sh(execom[0], execom, param->avec[0]);
		}
		if (stat == -1)
		{
			execErr(execom[0], param->avec[0], param->res_counts);
		}
	}
	free_arg(execom);
	return (stat);
}
