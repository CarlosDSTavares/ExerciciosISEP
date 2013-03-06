#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define PROCEC 2

char cria_gemeos(pid_t lista[PROCEC]){
  int i = 0;
	for(i = 0; i < PROCEC; i++){
		lista[i] = fork();
		if(lista[i] == 0){
			break;
		}
	}
	
	if(lista[0] == 0){
		return 'a';
	}else if(lista[1] == 0){
		return 'b';
	}
	return 'p';
}

int main(void){
	pid_t pid[PROCEC];
	char cha;
	
	cha = cria_gemeos(pid);
	
	printf("%c\n", cha);
	if(cha == 'p'){
		printf("PID PAI: %d\nPID FILHO 1: %d\nPID FILHO 2: %d\n", getpid(), pid[0], pid[1]);
	}
	
	
	exit(0);
}


