#include "main.h"

/**
 * _strdup - duplicates a string
 * @str: pointer to string to be duplicated
 * Return: pointer to the duplicated string
 */
char *_strdup(char *str)
{
	int i;
	char *dest = NULL;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		;
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		dest[i] = str[i];
	}
	dest[i] = '\0';
	return (dest);
}


/**
 * _splitstring - counts number of words in string
 * @str: pointer to string to be counted
 * Return: the result
 */

int _splitstring(char *str)
{
	int i, searchflag = 1, count = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && searchflag == 1)
		{
			count += 1;
			searchflag = 0;
		}
		if (str[i + 1] == ' ')
			searchflag = 1;
	}
	return (count);
}


/**
 * _strcmp - compares two strings
 * @s1: string one
 * @s2: string two
 * Return: the result
 */

int _strcmp(const char *s1, const char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 - *s2);
}


/**
 * _strcat - concatenates two strings
 * @src: source string
 * @dest: destination
 * Return: char type
 */
char *_strcat(char *src, char *dest)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++, i++)
		dest[i] = src[j];
	dest[i] = '\0';
	return (dest);
}


/**
 * _strlen - returns the length of a string
 * @s: pointer to the string
 * Return: the length
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}
