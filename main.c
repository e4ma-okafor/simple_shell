#include "main.h"

/**
 * main - Entry point
 * Return: 0 on success
 */

int main(void)
{
	char *fullpathbuffer = NULL, *copy = NULL, *buffer = NULL;
	char *PATH = NULL;
	char **argv = NULL;
	int exitstatus = 0;

	signal(SIGINT, SIG_IGN);
	PATH = _getenv("PATH");
	if (PATH == NULL)
		return (-1);
	while (1)
	{
		argv = NULL;
		prompt();
		buffer = _read();
		if (*buffer != '\0')
		{
			argv = tokenize(buffer);
			if (argv == NULL)
			{
				free(buffer);
				continue;
			}
			fullpathbuffer = _fullpathbuffer(argv, PATH, copy);
			if (checkbuiltins(argv, buffer, exitstatus) != 0)
				continue;
			exitstatus = _forkprocess(argv, buffer, fullpathbuffer);
		}
		else
			free(buffer);
	}
	return (0);
}
