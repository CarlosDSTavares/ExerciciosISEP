#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void verificaErros(int pid);

int main (void) {
	pid_t pid_1;
	pid_t pid_2 ;
	int status;
	
	pid_1 = fork(); // cria o primeiro processo filho
	verificaErros(pid_1);
	
	pid_2 = fork(); // cria mais 1 processo
	verificaErros(pid_2);
    
    if(pid_1 > 0 && pid_2 > 0){ // pai do processo 1 e 2
    	printf("%d : Eu sou o pai!\n", pid_1);
    	
    	waitpid(pid_1, &status, 0); // termina o processo filho e guarda o status do mesmo
    	
    	// if in-line
    	(status != -1) ? printf("O valor de saida do peimeiro processo é %d\n", status) : printf("ERRO: Valor de saida = -1\n");
		
		wait(&status); // apanha o processo que falta terminar
		
		// if in-line
    	(status != -1) ? printf("O valor de saida do segundo processo é %d\n", status) : printf("ERRO: Valor de saida = -1\n");
		
    }
    
    if(pid_2 == 0 && pid_1 == 0){ // filho do primeiro processo criado pelo pai
    	printf("%d : Sou neto do pai principal.\n", pid_1);
    	exit (2);
    }
    
    if(pid_1 == 0 && pid_2 > 0){ // filho do primeiro processo criado pelo pai
    	printf("%d : Sou filho do pai principal.\n", pid_2);
    	sleep(5);
    	exit (1);
    }
    
	return 0;
}

/* Verifica se os processos foram bem criados */
void verificaErros(int pid){
	if(pid < 0){
    	perror("Erro ao criar processo: ");
    	exit(-1);
    }
}