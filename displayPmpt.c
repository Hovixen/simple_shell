#include "main.h"

/**
 * dis_pmpt - displays the prompt of the shell in an infinite loop
 * @avec: points to the argument vector passed
 * Description: this functions displays the prompt, gets user input
 * and also calls the process execution function to execute user input
 * Return: returns void.
 */
void dis_pmpt(char **avec)
{
	char *inst = "bokangsh $: ";
	char *cmd_in = NULL;
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
		handle_in(&cmd_in, &n);
		promptexec(cmd_in, *avec);
	}
	free(cmd_in);
}
