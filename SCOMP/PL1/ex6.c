 /* prdemo06.c */
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define LENGTH 100

int main(void)
{
  pid_t pid;
	int num[LENGTH];
	int i;
	int status;
	
	fork();
	if(pid < 0){
		exit(-1);
	}
	if(pid > 0){
		for(i = LENGTH/2; i <  LENGTH; i++){
			num[i] = num[i]*4 + 20;
		}
		wait(&status);
		for(i = LENGTH/2; i <  LENGTH; i++){
			printf("%d\n",num[i]);
		}
	}else{
		for(i = 0; i < LENGTH/2; i++){
			num[i] = num[i]*4 + 20;
		}
		for(i = 0; i < LENGTH/2; i++){
			printf("%d\n",num[i]);
		}
	}
	
	exit(0);
}
