#include "main.h"
/**
 * _iscmd_inPath - Function checks if input command is in path
 * @cmd: input command
 * @cmdPath: buffer to hold tokenized path
 * Return: retuns 1 if command is in path or 0 if not
 */
int _iscmd_inPath(char *cmd, char *cmdPath)
{
	char *bpath = get_env("PATH"); /*pointer to store the path*/
	char *bpath_cpy;/*points to memory allocated to store path*/
	char *bpathTok;/*pointer to the tokenized command input*/
	char *slash = strr_chr(cmd, '/');

	if (bpath == NULL || cmdPath == NULL)
	{
		perror("Invalid input");
		exit(EXIT_FAILURE);
	}
	if (slash)
		cmd = (slash + 1);
	bpath_cpy = malloc(_strlen(bpath) + _strlen(cmd) + 2);
	if (bpath_cpy == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	strcpy(bpath_cpy, bpath);
	bpathTok = strtok(bpath_cpy, ":");
	while (bpathTok)
	{
		str_cpy(cmdPath, bpathTok);
		strcat(cmdPath, "/");
		strcat(cmdPath, cmd);

		if (exe_stat(cmdPath))
			return (1);
		if (is_path(cmdPath))
			return (1);
		bpathTok = strtok(NULL, ":");
	}
	free(bpath_cpy);
	return (0);
}
/**
 * exe_stat - function checks stat if path is executable
 * @Pathbuff: pointer to the constructed path to be checked
 * Return: return 1 when executable or 0 if not executable
 */
int exe_stat(const char *Pathbuff)
{
	struct stat fileStat;

	if (stat(Pathbuff, &fileStat) == 0)
	{
		if (S_ISREG(fileStat.st_mode) && (fileStat.st_mode & S_IXUSR))
			return (1);
	}
	return (0);
}
/**
 * exit_sh - function exits the shell with the command "exit"
 * Return: returns void
 */
void exit_sh(void)
{
	exit(2);
}
/**
 * environment - function prints to standard output the environments
 * Description: this function is the implementation of the env function
 * that prints all the environments in a system
 * Return: returns void
 */
void environment(void)
{
	char **_env = environ;

	while (*_env)
	{
		if (write(STDOUT_FILENO, *_env, strlen(*_env)) == -1)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
		if (write(STDOUT_FILENO, "\n", 1) == -1)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
		_env++;
	}

}
/**
 * is_path - function checks if path exist in environment
 * @Pathbuff: constructed environment path to be checked
 * Return: returns 1 success or 0 failed
 */
int is_path(const char *Pathbuff)
{
	return ((access(Pathbuff, F_OK) == 0));
}
