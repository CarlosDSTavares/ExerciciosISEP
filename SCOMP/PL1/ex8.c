#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void M(char *string);
void verify(pid_t pid);

int main(void){
	pid_t pid;
	int i;
	
	for(i=0;i<2;i++){
		pid = fork(); // priemiro fork
		verify(pid); // verifica se o processo foi bem criado
		if(pid > 0){ // se for pai mostra A
			M("A\n");
		}else{
			M("B\n"); // se for filho mostra b
			pid = fork(); // se for filho cria outro fork
			verify(pid); // verifica se o processo foi bem criado
			if(pid > 0){ // se deste segundo fork for o pai emprime A e termina
				M("A\n");
				exit(0);
			}
		}
	}

	return 0;
}

void M(char *string){
  printf(string);
}

void verify(pid_t pid){
	if(pid < 0) perror("ERROR: Erro ao criar processo!\n");
}
