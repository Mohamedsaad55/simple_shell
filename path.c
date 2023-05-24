#include "shell.h"
/**
 *f_path - find path
 *@file_name: file name
 *@tmp: saves the PATH string
 *@er: an error message
 *Return: Success - path/filename, fail : error
 */

char *f_path(char *file_name, char *tmp, char *er)
{
	DIR *dir;
	struct dirent *sd;
	char *f_path, *path, *ret;
	int len = 0;

	while (file_name[len])
		len++;
	path = get_env("PATH");
	tmp = save_path(tmp, path);
	f_path = strtok(tmp, ":");
	while (f_path)
	{
		dir = opendir(f_path);
		if (!dir)
		{
			printf("Error! Couldn't open directory.\n");
			exit(0);
		}
		while ((sd = readdir(dir)))
		{
			ret = r_dir(er, sd, file_name, len, f_path, tmp);
			if (ret != er)
			{
				closedir(dir);
				if (!(access(ret, X_OK)))
					return (ret);
			}
		}
		closedir(dir);
		f_path = strtok(NULL, ":");
	}
	path = NULL;
	free(tmp);
	return (er);
}

/**
 *r_dir - opens and reads directory file names
 *@er: error message
 *@s: struct containing info about a files in a directory
 *@f: name of file being searched for
 *@fp: directory being searched through
 *@t: string containing the PATH variable's value
 *@l: length of filename
 *Return: success - path , fail error
 */
char *r_dir(char *er, struct dirent *s, char *f, int l, char *fp, char *t)
{
	int i = 0;
	char *ret;

	for (i = 0; s->d_name[i] && f[i]; i++)
	{
		if (s->d_name[i] != f[i])
			break;
		if (i == (l - 1) && !(s->d_name[i + 1]))
		{
			ret = strcat(fp, "/");
			ret = strcat(ret, f);
			free(t);
			return (ret);
		}
	}
	return (er);
}
/**
 *save_path - saves a copy of the PATH string
 *@tmp: copy to be made of PATH
 *@path: string containing original PATH value
 *Return: success - tmp first time, path every other time, else error
 */
char *save_path(char *tmp, char *path)
{
	int i = 0;

	if (!tmp)
	{
		tmp = malloc(sizeof(char) * 100);
		while (path[i])
		{
			tmp[i] = path[i];
			i++;
			tmp[i] = '\0';
		}
		i = 0;
		return (tmp);
	}
	else
	{
		while (tmp[i])
		{
			path[i] = tmp[i];
			i++;
			path[i] = '\0';
		}
		i = 0;
		return (path);
	}

	return ("error");

}