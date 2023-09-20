#include "main.h"
/**
 * init_bshell - Function initializes the struct
 * @avec: argument vector from the main function
 * Return: returns the struct
 */
bshell init_bshell(char **avec)
{
	bshell memb;

	memb.cmd_in = NULL;
	memb.avec = avec;
	memb.out_status = 0;
	memb.cmds = NULL;
	memb.res_counts = 1;
	return (memb);
}
