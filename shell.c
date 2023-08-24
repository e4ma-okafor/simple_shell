#include "main.h"

/**
 * prompt - writes the command prompt
 * Return: 0 on sucess
 */

int prompt(void)
{
	char *prompt = "$ ";
	ssize_t writecount = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		writecount = write(STDOUT_FILENO, prompt, 2);
		if (writecount == -1)
			exit(0);
	}
	return (0);
}


/**
 * _read - reads the input and stores it in a buffer
 * Return: a pointer to the buffer
 */

char *_read(void)
{
	ssize_t readcount = 0;
	size_t n = 0;
	char *buffer = NULL;
	int x = 0;

	readcount = getline(&buffer, &n, stdin);
	if (readcount == -1)
	{
		free(buffer);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (buffer[readcount - 1] == '\n' || buffer[readcount - 1] == '\t')
		buffer[readcount - 1] = '\0';
	for (x = 0; buffer[x]; x++)
	{
		if (buffer[x] == '#' && buffer[x - 1] == ' ')
		{
			buffer[x] = '\0';
			break;
		}
	}
	return (buffer);
}


/**
 * _fullpathbuffer - finds the path buffer
 * @argv: pointer to array of user strings
 * @PATH: pointer to PATH string
 * @copy: pointer to copy of PATH string
 * Return: a pointer to string
 */

char *_fullpathbuffer(char **argv, char *PATH, char *copy)
{
	char *token = NULL, *fullpathbuffer = NULL, *concatstr = NULL;
	static char tmp[256];
	int PATHcount = 0, fullpathflag = 0, z = 0, toklen = 0;
	struct stat h;

	copy = NULL;
	copy = _strdup(PATH);
	PATHcount = _splitPATH(copy);
	token = strtok(copy, ": =");
	while (token != NULL)
	{
		concatstr = _concat(tmp, argv, token);
		if (stat(concatstr, &h) == 0)
		{
			fullpathbuffer = concatstr;
			fullpathflag = 1;
			break;
		}
		if (z < PATHcount - 2)
		{
			toklen = _strlen(token);
			if (token[toklen + 1] == ':')
			{
				if (stat(argv[0], &h) == 0)
				{
					fullpathbuffer = argv[0];
					fullpathflag = 1;
					break;
				}
			}
		}
		z++;
		token = strtok(NULL, ":");
	}
	if (fullpathflag == 0)
		fullpathbuffer = argv[0];
	free(copy);
	return (fullpathbuffer);
}


/**
 * checkbuiltins - checks for builtins
 * @argv: pointer to array of user of strings
 * @buffer: pointer to user string
 * @exitstatus: exit status of execve
 * Return: 1 if user string is equal to env or 0 otherwise
 */

int checkbuiltins(char **argv, char *buffer, int exitstatus)
{
	int i;

	if (_strcmp(argv[0], "env") == 0)
	{
		_env();
		for (i = 0; argv[i]; i++)
			free(argv[i]);
		free(argv);
		free(buffer);
		return (1);
	}
	else if (_strcmp(argv[0], "exit") == 0)
	{
		for (i = 0; argv[i]; i++)
			free(argv[i]);
		free(argv);
		free(buffer);
		exit(exitstatus);
	}
	else
		return (0);
}


/**
 * _forkprocess - create process to execute
 * @argv: pointer to array of user of strings
 * @buffer: pointer to user string
 * @fullpathbuffer: pointer to user input
 * Return: 0 on success
 */

int _forkprocess(char **argv, char *buffer, char *fullpathbuffer)
{
	int i, stat, result, exitstatus = 0;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (pid == 0)
	{
		result =  execve(fullpathbuffer, argv, environ);
		if (result == -1)
		{
			perror(argv[0]);
			for (i = 0; argv[i]; i++)
				free(argv[i]);
			free(argv);
			free(buffer);
			exit(127);
		}
	}
	wait(&stat);
	if (WIFEXITED(stat))
	{
		exitstatus = WEXITSTATUS(stat);
	}
	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
	free(buffer);
	return (exitstatus);
}
