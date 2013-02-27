#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void) {
	pid_t pid;
    int f;
    
    for (f = 0; f < 3; f++) {
        pid = fork(); // Cria um processo
        
        if (pid > 0) { // Caso seja o pai
            printf("Pai: Eu sou o PAI\n");
        } else { // caso seja o filho
			sleep(1); // processo para 1 segundo
		}
	}
    return 0;
}

// a) O programa Cria 8 processos dentro do ciclo for, fazendo 3 fork's
 
// b) ps - ver processos kill -9 pid para matar um processo
 
// c)
/**
 *  o
 *  | fork()                                1º
 *  |-------------------
 *  |  fork()           | fork()            2º
 *  |---------          |---------
 *  |         |         |         |
 *  |fork()   |fork()   |fork()   |fork()   3º
 *  |----     |----     |----     |----
 *  |    |    |    |    |    |    |    |
 *  |    |    |    |    |    |    |    |
 */
 
 // d) Programa alterado
 
int main1(void) {
	pid_t pid;
	int f;
	
	for (f = 0; f < 3; f++) {
		pid = fork(); /* Cria um PROCESSO */
		if (pid > 0) /* Código do PAI */
			printf("Pai: Eu sou o PAI\n");
		else { /* Código do FILHO */
			sleep(1);
			exit(1);
		}
	}
	return 0;
} /* fim main */

// e) Metodo que verifica se ocorreu erros a criar processo

void verificaErros(int pid){
	if(pid < 0){
    	perror("Erro ao criar processo: ");
    	exit(-1);
    }
}

int main2(void){
	pid_t pid;
	int f;
	
	for (f = 0; f < 3; f++){
		pid = fork(); /* Cria um PROCESSO */
		verificaErros(pid);
		if (pid > 0) /* Código do PAI */
			printf("Pai: Eu sou o PAI\n");
		else /* Código do FILHO */
			sleep(1);
	}
	return 0;
} /* fim main */

// f) 

int main3(void) {
	pid_t pid;
	int f;
	int status;
	
	for (f = 0; f < 3; f++) {
		pid = fork(); /* Cria um PROCESSO */
		if (pid > 0) { /* Código do PAI */
			printf("Pai: Eu sou o PAI\n");
			waitpid(pid, &status,0);
		} else { /* Código do FILHO */
			sleep(1);
		}
	}
	exit(f);
} /* fim main */

// g)

int main4(void)
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


// h)

int main5(void)
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
			if(f == 1){
				waitpid(pid, &status, WNOHANG);
				printf("Order: %d\nPid: %d\n", WEXITSTATUS(status), pid);
			}
		}
		else /* Código do FILHO */
		{
			sleep(1);
			exit(f);
		}
	}
	return 0;
} /* fim main */
