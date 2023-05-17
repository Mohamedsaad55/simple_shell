#include "shell.h"
 /**
  * p_launch : Forks and launches the Program
  * arg : arguments 
  * Return 1 on success
 */

int p_launch(char **arg)
{
	pid_t process_id , wait_id;
	int stts ;

	process_id = fork();
	if(process_id == 0)
	{
		if (execve(arg[0],arg,NULL) == -1)
		{
			perror("Failed\n");
			exit(0);

		}
	}
	else if (process_id < 0)
	{
		perror("Failed to use Fork\n");
		exit(0);
	}
	else
	{
		do {
			wait_id = waitpid(process_id, &stts, WUNTRACED );
		} 
		while (!WIFEXITED(stts) && WIFSIGNALED(stts));
	}
	(void)wait_id;
	return (1);
}