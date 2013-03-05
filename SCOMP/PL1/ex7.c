#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

void escreve(char *name, int number, int de, int ate);

int main(void) {
  int processos = 6; // numero de processos
	int tamanho = 120; // numero final
	
	// Calcula o numero de numeros por processo
	int partes = tamanho / processos;
	
	int i; // contador para o for
	pid_t pid[processos]; // OS pid's todos
	
	// limpar o licho do vector
	for(i=0;i<processos;i++){
		pid[i] = -2;
	}
	
	pid[0] = fork(); // promeiro processo que cria 1 filho
	for(i=0;i<processos;i++){
		if(pid[i] == 0){ // caso seja filho
			escreve("Processo ", (i+1), i*partes,(i+1)*partes); // escreve os numeros respectivos
			
			pid[i+1] = fork(); // cria um novo processo
			if(pid[i+1] > 0) // se for o o pai
				exit(1); // sai e deixa o filho continuar
		}else break; // caso seja pai, sai do for
	}
	
	// O pai espera por todos os processos e mostra o status 
	for(i=0;i<processos;i++){
		int status;
		waitpid(pid[i], &status, 0);
		printf("Status Processo %d: %d\n", (i+1), WEXITSTATUS(status));
	}
	
	return 0;
}

/* METODO QUE ESCREVE NUMEROS DE UM VALOR ATE OUTRO */
void escreve(char *name, int number, int de, int ate){

	while( de <= ate){
		printf("%s %d: %d\n", name, number, de);
		de++;
	}
	
}

/**
 *  o
 *  |
 *  |------
 *  |      |
 *  |      |------
 *  |      |      |
 *  |      |      |------
 *  |      |      |      |
 *  |      |      |      |------
 *  |      |      |      |      |
 *  |      |      |      |      |------
 *  |      |      |      |      |      |
 *  |      |      |      |      |      |
 * 
 */
