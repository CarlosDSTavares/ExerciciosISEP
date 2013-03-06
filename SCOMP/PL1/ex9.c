#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define NUMBER 10000
#define PROCEC 5

int find(int num[], int s, int f, int n){
  int validator = 0;
	int i;
	for(i = s; i < f; i++){
		if(num[i] == n){
			printf("Posição: %d\n", i);
			if(validator == 0){
				validator = 1;
			}
		}
	}
	
	return validator;
}

int main(void)
{
	pid_t pid[PROCEC] = {-1,-1,-1,-1,-1};
	int statusa[PROCEC];
	int num = 1;
	int proc_num = 1;
	int number[NUMBER];
	int status;
	int origin = getpid();
	int i;
	for(i = 0; i < NUMBER; i++){
		number[i] = i+1;
	}
	printf("Introduza um nr: ");
	scanf("%d",&num);
	
	i = 0;
	pid[0] = fork();
	if(pid[0] > 0){
		for(i = 1; i < PROCEC; i++){
			pid[i] = fork();
				proc_num++;
			if(pid[i] == 0){
				break;
			}
		}
	}
	if(getpid() == origin){ 
		for(i = 0; i < PROCEC; i++){
			waitpid(pid[i], &status, 0);
			statusa[i] = WEXITSTATUS(status);
		}
		for(i = 0; i < PROCEC; i++){
			if(statusa[i] != 0){
				printf("Processo Nr: %d Encontrou.\n", statusa[i]);
			}
		}
		exit(1);
	}
	if(find(number, (proc_num-1)*NUMBER/PROCEC, (proc_num-1)*NUMBER/PROCEC + NUMBER/PROCEC, num) != 0){
		exit(proc_num);
	}
	exit(0);
}


