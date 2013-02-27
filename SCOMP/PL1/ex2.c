#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void verificaErros(pid_t pid); // pre-declaraçao

int main(void) {
	pid_t pid, pid2;
	int status;
	
	pid = fork(); //cria o primeiro processo
	verificaErros(pid); //verifica erros
	
	if(pid > 0){ // se for o pai
		pid2 = fork(); // criar segundo processo
		verificaErros(pid2); // verifica erros
		if(pid2 > 0){ // se for o segundo pai
			printf("Eu sou o pai\npid = %d\n",getpid());
			
			waitpid(pid, &status, 0); // recebe status
			
			/* ESCREVE STATUS */
			(WEXITSTATUS(status) != -1) ? printf("Filho 1 terminou com %d\n", WEXITSTATUS(status)) : perror("Filho 1 terminou mal\n");
			waitpid(pid2, &status, 0); // recebe status
			/* ESCREVE STATUS */
			(WEXITSTATUS(status) != -1) ? printf("Filho 2 terminou com %d\n", WEXITSTATUS(status)) : perror("Filho 2 terminou mal\n");
			
		}else{ // se for o segundo filho
			printf("Eu sou o 2 Filho\npid = %d\n",getpid());
			exit(2);
		}
	}else{ // se for o filho
		printf("Eu sou o 1 Filho\npid = %d\n",getpid());
		sleep(5);
		
		exit(1);
	}
	
	exit(0);
}

/* Verifica se os processos foram bem criados */
void verificaErros(pid_t pid){
	if(pid < 0){
    	perror("Erro ao criar processo: ");
    	exit(-1);
    }
}
