#include "main.h"

/**
 * dis_pmpt - displays the prompt of the shell in an infinite loop
 * Description: this functions displays the prompt, gets user input
 * and also calls the process execution function to execute user input
 * Return: returns void.
 */
void dis_pmpt(void)
{
	char *inst = "bokangsh $: ";
	char *cmd_in = NULL;
	ssize_t inRead;
	size_t n = 0; /*length of the input given*/
	int prompt = 1;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, inst, strlen(inst));
		else if (cmd_in == NULL || strlen(cmd_in) == 0)
		{
			free(cmd_in);
			cmd_in = NULL;
		}
		else
		{
			if (!prompt)
				write(STDOUT_FILENO, inst, strlen(inst));
			prompt = 0;
		}
		inRead = getline(&cmd_in, &n, stdin);
		if (inRead == -1)
		{
			if (feof(stdin))
			{
				/*write(STDOUT_FILENO, "\n", 1);*/
				free(cmd_in);
				exit(EXIT_SUCCESS);
			}
			/*perror("getline");*/
			exit(EXIT_FAILURE);
		}

		if (cmd_in[inRead - 1] == '\n')
			cmd_in[inRead - 1] = '\0';

		promptexec(cmd_in);
	}
	free(cmd_in);
}
