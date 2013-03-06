#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define PROCEC 6
#define NUMBER 20

int cria_gemeos(pid_t lista[PROCEC]){
  int i = 0;
	for(i = 0; i < PROCEC; i++){
		lista[i] = fork();
		if(lista[i] == 0){
			return i;
		}
	}
	
	return 0;
}

void printnr(int s, int f){
	int i = 0;
	for(i = s; i < f; i++){
		printf("%d\n", i);
	}
}

int main(void){
	pid_t pid[PROCEC];
	int pret;
	
	pret = cria_gemeos(pid);
	if(pret != 0){
		printnr((pret-1)*NUMBER + 1, (pret-1)*NUMBER+NUMBER + 1);
	}
	
	exit(0);
}
