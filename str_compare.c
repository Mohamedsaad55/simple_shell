#include "shell.h"

/**
 * _str_compare - Compares two strings 
 * @s1: first string 
 * @s2: second string 
 * Return: Difference between str1 & str2
 **/

int _str_compare(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] != '/0' && s2[i] != '/0')
	{
		if (s1[i] == s2[i])
		{
			i++;
			continue;
		}
		else
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}
