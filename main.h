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

#define PATH_DELIMIT "=:"
#define DELIMIT " \t\r\n\a\""
#define BUFF_MAX 10
#define MAXLIST 100
#define STDOUT STDOUT_FILENO
#define CLEAR_SCREEN write(STDOUT, "\033[H\033[J", 6)
#define NEW_LINE write(STDOUT, "\n", 1)
#define TOK_BUFSIZE 64
extern char **environ;

int main(int argc __attribute__((unused)), char **argv, char **envr);
void shell_prompt(void);
void exit_shell(void);
char *get_line(int isattr_val);
char **free_dp(char **line);
char **_strtok(char *line_messages);
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
char *_strdup(char *str);
void _execev(char **line, char *argv, int num, int isattr_val, char **env);
void _puts(char *str);
int _putchar(char c);
int is_buit(char **line, char **env);
void _printenv(char **envi);
int check_path(char **env, char **argv);
char *str_concat(char *s1, char *s2);
int count_chr(char *str, char *delimits);
char **get_path(char **envi);
char **_path(char **env);
char *_strstr(char *stack, char *needle);
int _equal(char *src, char *dest);

#endif
