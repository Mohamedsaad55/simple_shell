#include "shell.h"

/**
 * test
*/

int main(int ac, char **argv)
{
    char *prompt = "(VerySshell) $ ";

    char *lineptr;
    size_t n = 0;
    ssize_t n_char;
    /* declaring void var */
    (void)ac; (void)argv;

    while(1)
    {
	    printf("%s",prompt);
	    getline(&lineptr,&n,stdin);
	    printf("%s/n",lineptr);

	    /*free up allocated memory*/
	    free(lineptr);
    }

    return(0);
}
