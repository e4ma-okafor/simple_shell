#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

int main(int argc __attribute__((unused)), char **argv, char **envr);
void shell_prompt(void);
void exit_shell(void);
char *get_commandline(int isattr_val);

#endif
