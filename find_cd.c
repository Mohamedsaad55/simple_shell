#include "shell.h"
/**
 *find_cd - look for current working dir
 *@file_name: file name
 *@er: Error
 *Return: current working dir
 */
char *find_cd(char *file_name, char *er)
{
	DIR *dir;
	struct dirent *sd;
	char *ret;
	int len = 0;
	int i = 0;

	while (file_name[len])
		len++;
	ret = malloc(sizeof(char) * (len + 3));
	dir = opendir(".");
	if (!dir)
	{
		printf("Error! Unable to open directory.\n");
		exit(0);
	}
	while ((sd = readdir(dir)))
	{
		for (i = 0; sd->d_name[i] && file_name[i]; i++)
		{
			if (sd->d_name[i] != file_name[i])
				break;
			if (i == (len - 1) && !(sd->d_name[i + 1]))
			{
				strcpy(ret, "./");
				strcat(ret, file_name);
				closedir(dir);
				if (!(access(ret, X_OK)))
					return (ret);
					write(2, er, 5);
			}
		}
	}
	closedir(dir);
	return (er);

}
