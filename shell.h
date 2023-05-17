#ifndef _SHELL_H_
#define _SHELL_H_
/**
 * define Headers
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define TOKEN_BUFF_S 64
#define TOKEN_DELI " \t\r\n\a"

typedef struct builtins
{
	char *arg;
	void (*builtin)(char **arg, char *li, char **env);
} builtin_list;


char *gline(void);
char **s_line(char *li);
int c_builtin (char **arg, char *li, char **env);
void exit_s(char **arg, char *li, char **env);
void env_s(char **arg, char *li, char **env); 
int _str_compare(char *str1, char *str2);
int p_launch(char **arg)

#endif
