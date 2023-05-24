#include "shell.h"

/**
 * sub_str - locates sub string
 * @x: input one
 * @x2: input two
 * Return: sub string
 */

char *sub_str(char *x, char *x2)
{
	for (; *x != '\0'; x++)
	{
		char *one = x;
		char *two = x2;

		while (*one == *two && *two != '\0')
		{
			one++;
			two++;
		}

		if (*two == '\0')
			return (x);
	}

	return (NULL);
	
}