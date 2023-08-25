#include "main.h"

/**
 * _cd - create cd function
 * @argv: argument value
 * @count: argument count
 * Return: env change
 */

int _cd(char **argv, int count)
{
	char hyphen[] = "-", *hsh = "./hsh";
	char *buff = malloc(sizeof(char) * 1024);

	if (argv[1] == NULL)
	{
		if (!_getenv("HOME"))
			printerror(&hsh, count, argv);
		else
		{
			chdir(_getenv("HOME"));
			setenv("OLDPWD", _getenv("PWD"), 1);
			setenv("PWD", getcwd(buff, sizeof(char) * 1024), 1);
		}
	}
	else if (_strcmp(argv[1], hyphen) == 0)
	{
		if (!_getenv("OLDPWD"))
			setenv("OLDPWD", _getenv("PWD"), 1);
		else
		{
			chdir(_getenv("OLDPWD"));
			setenv("OLDPWD", _getenv("PWD"), 1);
			setenv("PWD", getcwd(buff, sizeof(char) * 1024), 1);
		}
		write(1, _getenv("PWD"), _strlen(_getenv("PWD")));
		printf("\n");
	}
	else if (argv[1] != NULL && argv[1] != hyphen)
	{
		if (access(argv[1], F_OK) == -1)
			printerror(&hsh, count, argv);
		else
		{
			setenv("OLDPWD", _getenv("PWD"), 1);
			chdir(argv[1]);
			setenv("PWD", getcwd(buff, sizeof(char) * 1024), 1);
		}
	}
	free(buff);
	return (0);
}


/**
 * _getenv - get an environment variable.
 * @name: variable to look for
 * Return: environnment variable, if not found NULL
 */

char *_getenv(const char *name)
{
	int i = 0, y, count = 0, length;
	char *copy = (char *)name;

	if (name == NULL || !name[i])
		return (NULL);

	length = _strlen(copy);
	while (*(environ + i))
	{
		y = 0;
		while (*(*(environ + i) + y) != '=')
		{
			if (*(*(environ + i) + y) == name[y])
				count++;
			y++;
		}
		if (count == length)
		{
			y++;
			return (*(environ + i) + y);
		}
		i++;
		count = 0;
	}
	return (NULL);
}


/**
 * printerror - prints an error message on stderr
 * @argv: argument value
 * @count: counter of errors
 * @av: name of the command
 */

void printerror(char **argv, int count, char **av)
{
	write(2, *argv, strlen(*argv));
	write(2, ": ", 2);
	write_integer_error(count);
	write(2, ": ", 2);
	write(2, *av, strlen(*av));
	write(2, ": ", 2);
	write(2, "not found\n", 10);
}

/**
 * write_integer_error - prints an integer on stderr
 * @number: integer
 * Return: number of characters printed
 */

int write_integer_error(int number)
{
	int temp, characters_printed = 0;
	unsigned int c1;

	if (number < 0)
	{
		number = -number;
		write(2, "-", 1);
		characters_printed++;
	}
	c1 = number;
	if (c1 / 10)
	{
		characters_printed += write_integer(c1 / 10);
	}
	temp = (c1 % 10) + '0';
	return (characters_printed += write(2, &temp, 1));
}


/**
 * write_integer - print an integer
 * @number: integer
 * Return: characters printed
 */

int write_integer(int number)
{
	int temp, characters_printed = 0;
	unsigned int c1;

	if (number < 0)
	{
		number = -number;
		write(1, "-", 1);
		characters_printed++;
	}
	c1 = number;
	if (c1 / 10)
	{
		characters_printed += write_integer(c1 / 10);
	}
	temp = (c1 % 10) + '0';
	return (characters_printed += write(1, &temp, 1));
}
