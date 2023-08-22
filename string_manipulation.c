#include "main.h"

/**
 * _strcmp - strings comparison
 * @s1: first string
 * @s2: second string
 * Return: an array
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}


/**
 * _strlen - computes the lenght of a string
 * @str: input string
 * Return: the lenght of the string
 */

int _strlen(char *str)
{
	int len = 0, index = 0;

	while (str[index] != '\0')
	{
		len++;
		index++;
	}
	return (len);
}


/**
 *_strdup - duplicates a string
 *@str: pointer to the string
 *Return: an array
 */

char *_strdup(char *str)
{
	char *dup;
	unsigned int i, size;

	if (str == 0)
	{
		return (NULL);
	}

	size = _strlen(str) + 1;

	dup = (char *)malloc(size * sizeof(char));

	if (dup == 0)
	{
		return (NULL);
	}

	for (i = 0; *(str + i) != '\0'; i++)
	{
		*(dup + i) = *(str + i);
	}

	*(dup + i) = '\0';

	return (dup);
}


/**
 * _strtok - string tokenizer
 * @line_messages: recieved to user
 * Return: the pointer arr
 */

char **_strtok(char *line_messages)
{
	char *delimiters = " ,!¡¿?'\"\n\t";
	char *tok = NULL, **arr = NULL;
	int i = 0;

	if (line_messages == NULL)
	{
		return (NULL);
	}

	arr = malloc(_strlen(line_messages) + 1024);

	tok = strtok(line_messages, delimiters);
	arr[i] = tok;

	while (tok)
	{
		i++;
		tok = strtok(NULL, delimiters);
		arr[i] = tok;
	}
	i++;
	arr[i] = NULL;
	return (arr);
}


/**
 *str_concat - concatenates two strings
 *@s1: string one
 *@s2: string two
 *Return: the result(array pointer)
 */

char *str_concat(char *s1, char *s2)
{
	char *array;
	unsigned int i, j, size;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	size = _strlen(s1) + _strlen(s2) + 2;
	array = (char *)malloc(size * sizeof(char));

	if (array == 0)
	{
		return (NULL);
	}

	for (i = 0; s1[i] != '\0'; i++)
	{
		array[i] = s1[i];
	}

	array[i] = '/';
	i++;

	for (j = 0; s2[j] != '\0'; j++)
	{
		array[i] = s2[j];
		i++;
	}
	array[i] = 0;
	return (array);
}
