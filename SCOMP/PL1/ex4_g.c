/* prdemo06.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
  pid_t pid;
	int f;
	int status;
	
	for (f = 0; f < 3; f++)
	{
		pid = fork(); /* Cria um PROCESSO */
		if (pid > 0) /* Código do PAI */
		{
			printf("Pai: Eu sou o PAI\n");
			waitpid(pid, &status,0);
			printf("Order: %d\nPid: %d\n", WEXITSTATUS(status), pid);
		}
		else /* Código do FILHO */
		{
			sleep(1);
			exit(f);
		}
	}
	return 0;
} /* fim main */
