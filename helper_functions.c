#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: the character
 * Return: On success 1.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 *_puts - prints a string
 *@str: pointer to the string
 *Return: void
 */

void _puts(char *str)
{
	int i;

	for (i = 0 ; str[i] != '\0' ; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
