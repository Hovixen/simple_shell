#include "main.h"
/**
 * handle_in - function handles the input given
 * Description: this function when called, handles
 * the input of the user, using the getLine function
 * @param: pointer to the struct where the string input given
 * @n: size(length) of the string input given
 * Return: returns void.
 */
void handle_in(bshell *param, size_t *n)
{
	ssize_t inRead = getline(&(param->cmd_in), n, stdin);

	char *trim_cmd = param->cmd_in;
//	char *end = "exit";

	if (inRead == -1)
	{
		if (feof(stdin))
		{
			free(param->cmd_in);
			param->cmd_in = NULL;
			exit(EXIT_SUCCESS);
		}
		exit(EXIT_FAILURE);
	}
	while ((*trim_cmd != '\0') && (*trim_cmd == ' ' || *trim_cmd == '\t'))
		trim_cmd++;
	if ((*trim_cmd == '\0'))
	{
		free(param->cmd_in);
		param->cmd_in = NULL;
		return;
	}
	if ((param->cmd_in)[inRead - 1] == '\n')
		(param->cmd_in)[inRead - 1] = '\0';
	if (*trim_cmd != '\0')
		promptexec(param);
	free(param->cmd_in);
	param->cmd_in = NULL;
}
/**
 * bprint - Function prints string to the standard output
 * @input: The string to be printed
 * Return: returns void
 */
void bprint(const char *input)
{
	write(STDOUT_FILENO, input, _strlen(input));
}
/**
 * pmptdis - Function displays the name of the shell
 * Return: returns void.
 */
void pmptdis(void)
{
	char *input = "bokangsh $: ";

	bprint(input);
}

/**
 * **argTok - function takes command parses and tokenize it
 * @cmd: string command agruments to be tokenized
 * Return: returns void
 */
char **argTok(char *cmd)
{
	int argnum = 0;/*counts the arguments*/
	char *tok_process = strtok(cmd, DELIMS);
	/*array to hold tokenized argument*/
	char **cmdarr = (char **)malloc(sizeof(char *) * (MAX_CMD_ARG + 1));

	if (cmdarr == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	while (tok_process != NULL && argnum < MAX_CMD_ARG)
	{
		cmdarr[argnum] = str_dup(tok_process);
		if (cmdarr[argnum] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		tok_process = strtok(NULL, DELIMS);
		argnum++;
	}
	cmdarr[argnum] = NULL;
	return (cmdarr);
}
/**
 * free_arg - function frees the memory assigned to execom array
 * from the tokenized process
 * @execom: pointer to the array of string
 * Return: returns void
 */
void free_arg(char **execom)
{
	int i;

	for (i = 0; execom[i] != NULL; i++)
		free(execom[i]);
	free(execom);
}
