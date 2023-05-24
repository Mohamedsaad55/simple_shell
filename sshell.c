#include "shell.h"
/**
 * sshell - Infinite loop that runs simple shell
 * @ac: Arg count
 * @av: args passed to shell at beginning of prog
 * @env: Environment
 * Return: Void
 */
void sshell(int ac, char **av, char **env)
{
	char *li;
	char **arg;
	int status = 1;
	char *tmp = NULL;
	char *er;
	char *filename;
	int flow;

	er = "Error";
	do {
		promptt();
		li = gline();
		arg = s_line(li);
		flow = b(arg[0], arg);
		if (flow == 2)
		{
			filename = arg[0];
			arg[0] = f_path(arg[0], tmp, er);
			if (arg[0] == er)
			{
				arg[0] = find_cd(filename, er);
				if (arg[0] == filename)
					write(1, er, 5);
			}
		}
		if (arg[0] != er)
			status = exe_prog(arg, li, env, flow);
		free(li);
		free(arg);
	} while (status);
	if (!ac)
		(void)ac;
	if (!av)
		(void)av;
	if (!env)
		(void)env;
}