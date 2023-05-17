#include "shell.h"

/**
 * main - handles the arguments passed 
 * ac: Arguments count
 * av: Arr of arguments
 * env: Enviroment 
 * Return: 0;
 */

int main(int ac, char **av, char **env){
	if(!ac)
		(void)ac;
	if(!av)
		(void)av;
	if(!env)
		(void)env;
	shell(ac, av,env);
	return (0);
}