#include "main.h"

/**
 * is_buit - command environment
 * @line: wherever
 * @environ: add envi
 * Return: if pointers is success.
 */
int is_buit(char **line, char **environ)
{
	int chdir_val = 0;

	if (_strcmp(line[0], "exit") == 0 && line[1] == NULL)
	{
		free_dp(line);
		return (1);
	}

	if (_strcmp(line[0], "cd") == 0)
	{
		if (!line[1])
		{
			chdir_val = chdir("..");
			if (chdir_val != 0)
			{
				printf("Error changing directory\n");
				return (1);
			}
			return (1);
		}

		chdir_val = chdir(line[1]);

		if (chdir_val != 0)
		{
			printf("Error changing directory to: %s\n", line[1]);
			return (1);
		}
		return (1);
	}

	if ((_strcmp(line[0], "env") == 0) && line[1] == NULL)
		_printenv(environ);

	return (EXIT_SUCCESS);
}


/**
 * _printenv - prints the current environment
 * @environ: environment variable
 */
void _printenv(char **environ)
{
	int x = 0;

	for (; environ[x] ; x++)

		_puts(environ[x]); /*imprime todo el environment*/
}


/**
 *_puts - prints a string
 *@str: A pointer to an int that will be updated
 *
 *Return: void
 */
void _puts(char *str)
{
	int x;

	for (x = 0 ; str[x] != '\0' ; x++)
	{
		_putchar(str[x]);
	}
	_putchar('\n');
}


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 *str_concat - concatenates two strings
 *@s1: Array one
 *@s2: Array two
 *Return: Always an array dinamic
 */

char *str_concat(char *s1, char *s2)
{
	char *arr;
	unsigned int i, j, size;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	size = _strlen(s1) + _strlen(s2) + 2;
	arr = (char *)malloc(size * sizeof(char));

	if (arr == 0)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		arr[i] = s1[i];

	arr[i] = '/';
	i++;

	for (j = 0; s2[j] != '\0'; j++)
	{
		arr[i] = s2[j];
		i++;
	}
	arr[i] = 0;
	return (arr);
}
