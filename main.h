#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void dis_pmpt(char **avec);
void promptexec(const char *cmd, const char *avec);
void handle_in(char **cmd_in, size_t *n);


#endif
