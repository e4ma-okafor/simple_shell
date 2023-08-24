#include "main.h"

/**
 * prompt_shell - function to print the prompt
 * @void: wherever
 * Return: none
 */
void prompt_shell(void)
{
	write(STDOUT, "\033[1;31m$ ", 32);
	write(STDOUT, "\033[0m", 4);
}


/**
 * _strtok - Split to token of strok
 * @line_messages: recieved to user
 * Return: the chit(s)
 */
char **_strtok(char *line_messages)
{
	char *delimiters = " ,!¡¿?'\"\n\t";
	char *chit = NULL, **array = NULL;
	int i = 0;

	if (line_messages == NULL)
	{
		return (NULL);
	}

	array = malloc(_strlen(line_messages) + 1024);

	chit = strtok(line_messages, delimiters);
	array[i] = chit;

	while (chit)
	{
		i++;
		chit = strtok(NULL, delimiters);
		array[i] = chit;
	}
	i++;
	array[i] = NULL;
	return (array);
}


/**
 * _path -  path execute commands
 * @environ: Environ variable
 * Return: token
 **/
char **_path(char **environ)
{
	int location = 0;
	char **token;

	for (; environ[location] != NULL ; location++)
	{
		if (environ[location][0] == 'P' && environ[location][2] == 'T')
		{
			token = &(environ[location]);
		}
	}
	return (token);
}


/**
 * free_dp - free all file
 * @line: double pointer to free
 *
 * Return: ptr null
 */

char **free_dp(char **line)
{
	int x;

	for (x = 0; line[x]; x++)
	{
		free(line[x]);
		line[x] = NULL;
	}
	free(line);
	line = NULL;
	return (NULL);
}


/**
 * _exit_function - function to print
 * @void: the exit
 * Return: none
 */
void _exit_function(void)
{
	kill(getpid(), SIGTERM);
}
