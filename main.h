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

extern char **environ;

int main(void);

/* Shell functions */
int prompt(void);
char *_read(void);
char *_fullpathbuffer(char **argv, char *PATH, char *copy);
int checkbuiltins(char **argv, char *buffer, int exitstatus);
int _forkprocess(char **argv, char *buffer, char *fullpathbuffer);

/* String manipulation */
char *_strdup(char *str);
int _splitstring(char *str);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *src, char *dest);
int _strlen(char *s);

/*Tokenize & PATH Functions*/
char **tokenize(char *buffer);
int _splitPATH(char *str);
int _PATHstrcmp(const char *s1, const char *s2);
char *_concat(char *tmp, char **argv, char *token);

/*Other Helper Funcs*/
char *_getenv(const char *name);
int _env(void);
void _puts(char *str);
int _putchar(char c);
char *_memset(char *s, char b, unsigned int n);

#endif
