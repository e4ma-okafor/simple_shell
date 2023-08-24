#include "main.h"

/**
 * _path -  path execute commands
 * @env: environment variable
 * Return: token
 **/

char **_path(char **env)
{
	int location;
	char **token;

	for (location = 0; env[location] != NULL ; location++)
	{
		if (env[location][0] == 'P' && env[location][2] == 'T')
		{
			token = &(env[location]);
		}
	}
	return (token);
}


/**
 *_strstr - find a mem
 *@stack: initial segment
 *@needle: prefix
 *Return: nothing
 */

char *_strstr(char *stack, char *needle)
{
	if (*stack == '\0')
	{
		return (0);
	}

	if (stack[0] != needle[0])
	{
		return (NULL);
	}

	if (*needle == '\0')
	{
		return (stack);
	}

	while (*stack != '\0')
	{
		if ((*stack == *needle) && _equal(stack, needle))
			return (stack);
		stack++;
	}

	return (0);
}


/**
 *_equal - find similar characters
 *@src: source char
 *@dest: destination char
 *Return: an integer
 */

int _equal(char *src, char *dest)
{
	int i = 0;

	while (*dest + i != '\0' && *src + i != '\0')
	{
		if (*dest != *src)
			return (0);
		dest++;
		src++;
	}

	return (*src == '\0');
}
