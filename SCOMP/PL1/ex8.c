#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define NUMBER 10000
#define PROCEC 5

void M(char *string){
  printf(string);
}

int main(void){
	pid_t pid;
	int i = 0;
	while(i < 2){
		pid = fork();
		if(pid > 0){
			M("A\n");
		}else{
			M("B\n");
			pid = fork();
			if(pid > 0){
				M("A\n");
				exit(0);
			}
		}
		i++;
	}

	exit(0);
}
