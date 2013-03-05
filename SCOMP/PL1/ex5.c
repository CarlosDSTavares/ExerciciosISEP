#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void) {
  fork();
	printf("1\n");
	fork();
	printf("2\n");
	fork();
	printf("3\n");
	return 0;
}

// a)

/**
 *  o
 *  | 
 *  |-------------------
 *  |  ("1")            | ("1")   
 *  |---------          |---------
 *  |         |         |         |
 *  |("2")    |("2")    |("2")    |("2") 
 *  |----     |----     |----     |----
 *  |    |    |    |    |    |    |    |
 *  |    |    |    |    |    |    |    |
 *("3")("3")("3")("3")("3")("3")("3")("3")  
 */

 // b) Sim, pode acontecer caso um dos processos fique parado antes do printf de 1
 // e outro processo prosiga pelos seguintes print's.
