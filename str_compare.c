#include "shell.h"

/**
 *_str_compare - Compares two strings
 *@str1: string 1
 *@str2: string 2
 *Return: Difference between str1 & str2
 */
int _str_compare(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] == str2[i])
		{
			i++;
			continue;
		}
		else
		{
			return (str1[i] - str2[i]);
		}
	}
	return (0);
}
