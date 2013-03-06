#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

void M(char* c){
  printf("%c\n",c);
}

int main(void)
{
pid_t pid[2];
int status;
int i;
for (i=0;i<2;i++){
	printf("i=%d\n",i);
	pid[i]=fork();
	M('A');
	if(pid[i]==0){
		M('B');
		
	}
}
}
