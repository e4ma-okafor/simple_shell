#include "main.h"

/**
 * shell_prompt - prints the prompt
 * @void: the environment
 * Return: void
 */

void shell_prompt(void)
{
	write(STDOUT, "\033[1;31mSh_shell/user@root$ ", 32);
	write(STDOUT, "\033[0m", 4);
}


/**
 * exit_shell - exits the shell
 * @void: the exit
 * Return: void
 */

void exit_shell(void)
{
	kill(getpid(), SIGTERM);
}


/**
 * get_commandline - prints the shell prompt and wait for a command
 * @isattr_val: function argument
 * Return: the command (line)
 **/
char *get_commandline(int isattr_val)
{
	ssize_t read = 0;
	size_t buffer_len = 0;
	char *line = NULL;

	if (isattr_val == 1)
	{
		write(STDOUT, "\033[1;31mSh_shell/user@root$ ", 32);
		write(STDOUT, "\033[0m", 4);
	}

	read = getline(&line, &buffer_len, stdin);

	if (read == EOF)
	{
		if (isattr_val == 1)
		{
			printf("\n");
		}
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (line);
}


/**
 * free_file - free all files
 * @line: double pointer argument
 * Return: null
 */

char **free_file(char **line)
{
	int i;

	for (i = 0; line[i]; i++)
	{
		free(line[i]);
		line[i] = NULL;
	}
	free(line);
	line = NULL;
	return (NULL);
}
