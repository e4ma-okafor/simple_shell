#include "main.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: pointer to argument value
 * @envr: anywhere
 * Return: 0
 */

int main(int argc __attribute__((unused)), char **argv, char **envr)
{
	char *str = NULL;
	char **line = NULL;
	int _val_prompt = 0;
	int val_attr = 0;

	while (1)
	{
		val_attr = isatty(STDIN_FILENO);
		str = get_line(val_attr);

	if (_strcmp(str, "exit\n") == 0)
	{
		free(str);
		exit(0);
	}

		if (str != NULL)
		{
			_val_prompt++;
			line = _strtok(str);
			_execev(line, argv[0], _val_prompt, val_attr, envr);
			free(str);
			free(line);
		}
		val_attr = 0;
	}
	return (0);
}
