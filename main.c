#include "main.h"

/**
 * main - This is entry point of the shell code
 * @ac: This is the argument count
 * @avec: This is the argument string(vector)
 * Return: returns 0 always success
 */

int main(int ac, char *avec[])
{
	bshell param;
	(void)ac;

	param = init_bshell(avec);

	dis_pmpt(&param);
	free(param.cmd_in);
	return (0);
}
