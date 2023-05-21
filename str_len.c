#include "shell.h"

/**
 * strr_len - a function that returns the length of a string
 * s: char input
 * Return: length of the input string
 */
int strr_len(char *s)
{
	int i = 1, sum = 0;
	char pl = s[0];

	while (pl != '\0')
	{
		sum++;
		pl = s[i++];
	}
	return (sum);
}