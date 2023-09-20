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
	int stat, /*status,*/ existing;
	char **execom = argTok(param->cmd_in);
	char cmdPath[1024];

	existing = _iscmd_inPath(execom[0], cmdPath);
	if (existing)
	{
		stat = fork_sh(cmdPath, execom, param->avec[0]);
	}
	else if (str_cmp(execom[0], "exit") == 0)
		exit_sh();
	else if (str_cmp(execom[0], "env") == 0)
		environment();
	else
	{
		execErr(execom[0], param->avec[0], param->res_counts);
		/*exit(127);*/
	}
	stat = -1;
	free_arg(execom);
	return (stat);
}
