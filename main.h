#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>


#define MAX_CMD_ARG 128
#define MAX_BUFF 1024
#define DELIMS "  \t\n"

/*global variable*/

/**
 * struct bShell - structure takes all the neccessary information
 * of the shell
 */
typedef struct bokangsh
{
	char *cmd_in;/* User command input*/
	char **avec; /*main argument vector*/
	char *path; 
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
char *str_cat(char *dest, char *src);

/*env & path*/
int _iscmd_inPath(char *cmd, char *cmdPath);

/*errors*/
void execErr(char *cmd);
#endif
