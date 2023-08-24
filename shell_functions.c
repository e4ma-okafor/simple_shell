#include "main.h"

/**
 * _getenv - gets the environment
 * @name: pointer to PATH string
 * Return: pointer to PATH or NULL if not found
 */

char *_getenv(const char *name)
{
	int i, path;

	for (i = 0; environ[i]; i++)
	{
		path = _PATHstrcmp(name, environ[i]);
		if (path == 0)
		{
			return (environ[i]);
		}
	}
	return (NULL);
}


/**
 * _env - prints the environment
 * Return: 0 on success
 */

int _env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		_puts(environ[i]);
	return (0);
}


/**
 * _puts - prints a string
 * @str: string to print
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	_putchar('\n');
}


/**
 * _putchar - prints a character
 * @c: character to print
 * Return: the character
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _memset - fills memory with a constant byte
 * @s: character array to fill
 * @b: constant byte to fill with
 * @n: number of bytes to fill
 * Return: the pointer to the char
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
