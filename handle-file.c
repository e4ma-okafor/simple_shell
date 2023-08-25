#include "main.h"

/**
 * _echo - function to print on the CLI
 * @av: list of arguments
 * Return: 0
 */
int _echo(char **av)
{
	int pid;

	if (av[2])
		write(2, "Too many arguments\n", 20);
	else
	{
		if (_strcmp("$$", av[1]) == 0)
		{
			pid = getpid();
			printf("%i\n", pid);
		}
		else
			printf("%s\n", av[1]);
	}
	return (0);
}


#define BUF_SIZE 256

/**
 * _getLine - getline function
 * @file: file
 * Return: line read
 */

char *_getLine(const int file)
{
	static char readding[BUF_SIZE];
	static int index = BUF_SIZE;
	int getting = 0;
	int count = 0;
	char *get = NULL;

	if (getting == 0 && index >= (BUF_SIZE - 1))
	{
		index = 0;
		getting = read(file, readding, BUF_SIZE + 1);
		readding[getting] = '\0';
	}

	if (index <= BUF_SIZE && readding[index] != '\0')
	{
		get = malloc((sizeof(*get) * BUF_SIZE));
		while (readding[index] != '\n' && readding[index] != '\0')
			get[count++] = readding[index++];
		get[count] = '\0';
		if (readding[index] != '\0')
			index = index + 1;
	}
	return (get);
}
