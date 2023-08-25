#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
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

int main(int argc __attribute__((unused)), char **av, char **env);
char **free_dp(char **line);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
void _exit_function(void);
void prompt_shell(void);
char *get_line(int isatty_val);
char **_strtok(char *line_messages);
void _execev(char **line, char *argv, int num, int isatty_val, char **envi);
int is_buit(char **line, char **environ);
char *_strstr(char *haystack, char *needle);
int _equal(char *dest, char *src);
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);
char **get_path(char **env);
int count_chr(char *str, char *delimits);
int check_path(char **env, char **argvs);
void _printenv(char **environ);
int _putchar(char c);
void _puts(char *str);
char **_path(char **environ);
int _cd(char **argv, int count);
char *_getenv(const char *name);
void printerror(char **argv, int count, char **av);
int write_integer_error(int number);
int write_integer(int number);

#endif
