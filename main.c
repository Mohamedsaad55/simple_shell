#include "shell.h"

/**
 * test
*/

int main(int ac, char **av)
{
		char *prompt = "(VerySshell) $ ";
		char *lptr;
		size_t n = 0;
		ssize_t n_char;

		/* declaring void var */
		(void)ac; (void)av;

		while(1)
		{
			printf("%s",prompt);
			getline(&lptr,&n,stdin);
			if (n_char==-1)
			{
				printf("See You Later..../n");
				return (-1);
			}
			printf("%s/n",lptr);

		/*free up allocated memory*/
			free(lptr);
		}

	return(0);
}
 
