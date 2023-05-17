#include "main.h"

/**
 * test
*/

int main(int ac, char **av)
{
		char *prompt = "(VerySshell) $ ";
		char *lptr = NULL, *lptr_cp=NULL;
		size_t n = 0;
		ssize_t n_char;
		const char *delim = " \n";
		int n_tokens =0;
		char *tkn;
		int i;

		/* declaring void var */
		(void)ac; 

		while(1)
		{
			printf("%s",prompt);
			n_char= getline(&lptr,&n,stdin);
			if (n_char ==-1)
			{
				printf("See You Later..../n");
				return (-1);
			}

			/*allocate space for the copy*/
			lptr_cp = malloc(sizeof(char) * n_char);
			if (lptr_cp == NULL)
			{
				perror("tsh : memory alloc error");
				return(-1);
			}
			printf("%s/n",lptr);

		/*free up allocated memory*/
			free(lptr);
		}

	return(0);
}
 
