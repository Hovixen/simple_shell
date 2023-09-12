#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_CMD_ARG 128
#define DELIMS "  \t\n"
/**
 * struct bShell - structure takes all the neccessary information
 * of the shell
 */

typedef struct bokangsh
{
	char *cmd_in;
	char *avec;
}bshell;
/*shell core*/
bshell init_bshell(char *avec[]);
void dis_pmpt(bshell *param);
int promptexec(bshell *param);
void handle_in(bshell *param, size_t *n);
char **argTok(char *cmd);
void free_arg(char **execom);

void bprint(const char *input);
void pmptdis(void);

/*custom string functions*/
size_t _strlen(const char *cmd);
char *str_cpy(char *dest, char *src);
char *str_dup(char *cmd);
size_t str_spn(const char *cmd, const char *sets);


#endif
