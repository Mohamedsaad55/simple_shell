#include "shell.h"

/**
 * prompt - prints $ for prompt
 * Return: void
 */

void promptt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(1, "$ ", 2);
	}

}