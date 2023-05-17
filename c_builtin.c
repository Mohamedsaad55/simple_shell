#include "shell.h"

/**
 * c_builtin.c : Checks for Builtin commands
 * arg : Arguments Captured from the user 
 * li : line buffer
 * env : Enviroment
 * Return : 1 if exists else : 0
*/

int c_builtin (char **arg, char *li, char **env)
{
	builtin_list list[] = {
		{"exit",exit_shell},
		{"env",env_shell},
		{NULL,NULL}
	};
	int i;

	for(i = 0; list[i].arg !=NULL; i++)
	{
		if(str_compare(list[i].arg, arg[0]) == 0)
		{
			list[i].builtin(arg, li, env);
			return(1);
		}
	}
	return(0);
}