#include "main.h"

/**
 * dis_pmpt - displays the prompt of the shell in an infinite loop
 * @param: points to the struct with defined members
 * Description: this function calls necessary functions and run them in
 * infinite loop. e.g prompt display function, handling and executing
 * the user input command e.t.c
 * Return: returns void.
 */
void dis_pmpt(bshell *param)
{
	size_t n = 0; /*length of the input given*/
	int prompt = 1;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			pmptdis();
		else if (param->cmd_in == NULL || _strlen(param->cmd_in) == 0)
		{
			free(param->cmd_in);
			param->cmd_in = NULL;
		}
		else
		{
			if (!prompt)
				pmptdis();
			/*prompt = 0;*/
		}
		handle_in(param, &n);
	}
	/*free(param->cmd_in);*/
}
