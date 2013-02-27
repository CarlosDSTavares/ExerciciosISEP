 /* prdemo06.c */
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid, pid2;
	int status;
	
	pid = fork();
	if(pid < 0){
		perror("Erro na criação de processo");
	}
	
	if(pid > 0){
		pid2 = fork();
		if(pid2 < 0){
			perror("Erro na criação de processo");
		}
		if(pid2 > 0){
			printf("Eu sou o pai\npid = %d\n",getpid());
			
			waitpid(pid, &status, 0);
			if(WEXITSTAUTS(status) != -1){
				printf("Filho 1 terminou com %d\n", WEXITSTATUS(status));
			}else{
				perror("Filho 1 terminou mal\n");
			}
			waitpid(pid2, &status, 0);
			if(WEXITSTAUTS(status) != -1){
				printf("Filho 2 terminou com %d\n", WEXITSTATUS(status));
			}else{
				perror("Filho 2 terminou mal\n");
			}
			
		}else{
			printf("Eu sou o 2º Filho\npid = %d\n",getpid());
			exit(2);
		}
	}else{
		printf("Eu sou o 1º Filho\npid = %d\n",getpid());
		sleep(5);
		
		exit(1);
	}
	
	exit(0);
}
