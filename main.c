#include "shell.h"

/**
 * test
*/

int main(int ac, char **argv)
{
    char *prompt = "(VerySshell) $ ";

    char *lineptr;
    size_t n = 0;
    /* declaring void variables */
    (void)ac; (void)argv;

    printf("%s", prompt);
    getline(&lineptr, &n, stdin);

    free(lineptr);
    return (0);
}