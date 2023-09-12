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
	memb.avec = avec[0];
	return (memb);
}
