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
#define DELIMS "  \t\n\a\r"

/*global variable*/
extern char **environ;

/**
 * struct bShell - structure takes all the neccessary information
 * of the shell
 */
typedef struct bokangsh
{
	char *cmd_in;/* User command input*/
	char **avec;/*main argument vector*/
	char **cmds;/*commands*/
	char *path;
	int out_status;/*output status*/
	int res_counts;/*result counts*/
}bshell;

/*shell core*/
bshell init_bshell(char *avec[]);
void dis_pmpt(bshell *param);
int promptexec(bshell *param);
void handle_in(bshell *param, size_t *n);
char **argTok(char *cmd);
void free_arg(char **execom);
int fork_sh(char *cmd, char **args, char *cmd_in);


void bprint(const char *input);
void pmptdis(void);

/*custom string functions*/
int numLen(int num);
size_t _strlen(const char *cmd);
char *str_cpy(char *dest, char *src);
char *str_dup(char *cmd);
size_t str_spn(const char *cmd, const char *sets);
char *str_cat(char *dest, char *src);
char *conItoA(int num);
char *strr_chr(char *cmd, int c);
int str_cmp(char *cmd, char *str);

/*memory allocation*/
ssize_t getLine(char **in_ptr, size_t *n, FILE *stream);
void resize_buff(char **in_ptr, size_t *n, size_t nsize);

/*env & path*/
int _iscmd_inPath(char *cmd, char *cmdPath);
int exe_stat(const char *Pathbuff);
void exit_sh();
void environment();
int is_path(const char *Pathbuff);

/*errors*/
void execErr(char *cmd, char *cmd_in, int counts);
#endif
