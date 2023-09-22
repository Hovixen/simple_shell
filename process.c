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
			exit_sh();
		if (execve(cmd, args, environ) == -1)
		{
			perror(cmd_in);
			exit_sh();
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
/**
 * is_space - function checks if a space exists in the command
 * @cmd: command passed
 * Return: return 1 when space is encountered or 0 when no space
 */
int is_space(char *cmd)
{
	while (*cmd)
	{
		if (*cmd == ' ')
			return (1);
		cmd++;
	}
	return (0);
}
/**
 * OR_file - function open and reads file into buff
 * @f_name: file name in the command
 * @f_content: pointer points to the file content
 * Return: returns 0 on success or -1 when failed
 */
int OR_file(char *f_name, char **f_content)
{
	char buff[4026];
	size_t read_len;/*bytes read by the read function*/
	size_t f_size = 0;/*tracks file content that is read*/
	int fd = open(f_name, O_RDONLY);

	if (fd == -1)
	{
		perror("open");
		return (-1);
	}
	*f_content = NULL;

	while ((read_len = read(fd, buff, sizeof(buff))) > 0)
	{
		*f_content = realloc(*f_content, f_size + read_len + 1);
		if (*f_content == NULL)
		{
			close(fd);
			return (-1);
		}
		memcpy(*f_content + f_size, buff, read_len);
		f_size += read_len;
	}
	close(fd);

	if (read_len == -1)
	{
		perror("read");
		return (-1);
	}
	(*f_content)[f_size] = '\0';
	return (0);
}
/**
 * processInput - function processes  the input if a file exits there
 * @param: struct of shell input
 * @cmd: pointer to the command input
 * Return: return 0 when success or -1 when failed
 */
int processInput(bshell *param, char *cmd)
{
	char *cmd_ptr = NULL;
	char *f_content = NULL;
	char *file = strtok(cmd, " ");
	char *command = strtok(NULL, "");
	size_t len_cmd;

	if (OR_file(file, &f_content) == 0)
	{
		if (f_content)
		{
			len_cmd = _strlen(command) + _strlen(f_content) + 2;
			param->cmd_in = (char *)realloc(param->cmd_in, len_cmd);
			if (param->cmd_in == NULL)
			{
				perror("realloc");
				free(f_content);
				return (-1);
			}

			cmd_ptr = param->cmd_in;
			while (*f_content)
				*cmd_ptr++ = *f_content;
			*cmd_ptr = ' ';
			while (*command)
				*cmd_ptr++ = *command++;
			*cmd_ptr = '\0';

			free(f_content);
			return (0);
		}
		else
			fprintf(stderr, "Failed to read file '%s'\n", file);
	}
	else
		fprintf(stderr, "Failed to read file '%s'\n", file);
	return (-1);
}
