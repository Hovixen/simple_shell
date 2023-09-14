#include "main.h"
/**
 * _iscmd_inPath - Function checks if input command is in path
 * @cmd: input command
 * @cmdPath: buffer to hold tokenized path
 * Return: retuns 1 if command is in path or 0 if not
 */
int _iscmd_inPath(char *cmd, char *cmdPath)
{
	char *bpath = getenv("PATH"); /*pointer to store the path*/
	char *bpath_cpy;/*points to memory allocated to store path*/
	char *bpathTok;/*pointer to the tokenized command input*/
	struct stat fileStat;

	if (bpath == NULL || cmdPath == NULL)
	{
		perror("Invalid input");
		exit(EXIT_FAILURE);
	}
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

		if (stat(cmdPath, &fileStat) == 0)
		{
			if (S_ISREG(fileStat.st_mode) && (fileStat.st_mode & S_IXUSR))
			{
				free(bpath_cpy);
				return (1);
			}
			else
			{
			free(bpath_cpy);
				return (0);
			}
		} bpathTok = strtok(NULL, ":");
	}
	free(bpath_cpy);
	return (0);
}
