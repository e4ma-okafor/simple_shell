#include "main.h"

/**
 * _execev - executes the program
 * @line:  strtok token
 * @argv: argument variables
 * @num:  variablei internal
 * @isattr_val: is the tty
 * @env: enviroment variable
 * Return: void
 */
void _execev(char **line, char *argv, int num, int isattr_val, char **env)
{
	pid_t pid;
	int _exec = 0;

	if (line[0] == NULL)
	{
		return;
	}

	if (is_buit(line, env) == 1)
	{
		return;
	}

	pid = fork();
	if (pid < 0)
	{
		printf("Error during fork\n");
		free_dp(line);
		exit(EXIT_FAILURE);
	}
	else if (pid != 0)
	{
		wait(NULL);
		return;
	}
	else
	{
		if (check_path(env, line) == 0)
			_exec = execve(line[0], line, NULL);
		if (_exec < 0)
		{
			if (isattr_val == 1)
			{
				printf("%s: No such file or directory\n", argv);
				free(line);
				exit(EXIT_SUCCESS);
			}
			printf("%s: %d: %s: not found\n", argv, num, line[0]);
			free(line);
			exit(EXIT_FAILURE);
		}
		free_dp(line);
		exit(EXIT_SUCCESS);
	}
}
