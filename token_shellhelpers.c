#include "main.h"

/**
 * tokenize - creates array of tokens based on user string
 * @buffer: pointer to user string
 * Return: the array
 */
char **tokenize(char *buffer)
{
	char *token = NULL;
	int i = 0, count = 0;
	char *delimiter = " \n";
	char **argv = NULL;

	count = _splitstring(buffer);
	if (!count)
		return (NULL);
	argv = malloc((count + 1) * sizeof(char *));
	if (argv == NULL)
		exit(1);
	token = strtok(buffer, delimiter);
	while (token != NULL)
	{
		argv[i] = _strdup(token);
		token = strtok(NULL, delimiter);
		i++;
	}
	argv[i] = NULL;
	return (argv);
}


/**
 * _splitPATH - counts the number of PATH members
 * @str: pointer to string to count
 * Return: number of PATH members
 */
int _splitPATH(char *str)
{
	int i, searchflag = 1, count = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ':' && searchflag == 1)
		{
			count += 1;
			searchflag = 0;
		}
		if (str[i + 1] == ':')
		{
			searchflag = 1;
		}
	}
	return (count);
}


/**
 * _PATHstrcmp - compares PATH with environ to find PATH value
 * @s1: pointer PATH string
 * @s2: pointer to environ string with actual value
 * Return: 0 on success
 */
int _PATHstrcmp(const char *s1, const char *s2)
{
	int j;

	for (j = 0; s2[j] != '='; j++)
	{
		if (s1[j] != s2[j])
			return (-1);
	}
	return (0);
}


/**
 * _concat - concats user input with PATH member string and /
 * @tmp: static array to store concatenated string
 * @argv: pointer to array of user strings
 * @token: pointer to PATH token
 * Return: 0 on success
 */

char *_concat(char *tmp, char **argv, char *token)
{
	int len = 0;

	_memset(tmp, 0, 256);
	len = _strlen(token) + _strlen(argv[0]) + 2;
	_strcat(tmp, token);
	_strcat(tmp, "/");
	_strcat(tmp, argv[0]);
	tmp[len - 1] = '\0';
	return (tmp);
}
