/* prdemo06.c */
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
  pid_t pid;
	int f;
	
	for (f = 0; f < 3; f++)
	{
		pid = fork(); /* Cria um PROCESSO */
		if (pid > 0) /* Código do PAI */
		{
			printf("Pai: Eu sou o PAI\n");
		}
		else /* Código do FILHO */
		{
			sleep(1);
		}
	}
	return 0;
} /* fim main */
