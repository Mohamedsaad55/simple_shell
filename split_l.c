#include "shell.h"

/**
 * s_line : split the line into arguments
 * l : the line 
 * Return : Arr of arguments 
*/

char **s_line(char *l)
{
	size_t buf_s = TOKEN_BUFF_S ;
	char **tkns = malloc(sizeof(char *) * buf_s);
	char **tkn ;
	int position =0;

	if (tkns == NULL)
	{
		perror("memory alloc error \n");
		exit(0);
	}

	tkn = strtok(l , TOKEN_DELI);

	while (tkn != NULL)
	{
		tkns[position] = tkn ;
		tkn = strtok(NULL, TOKEN_DELI);
		position++;
	}
	tkns[position] = NULL ;

	return (tkns);

}