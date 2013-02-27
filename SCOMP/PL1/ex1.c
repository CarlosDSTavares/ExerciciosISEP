/* prdemo04.c */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void verificaErros(int pid);

int main (void) {
	pid_t p,a;
	
    p = fork();
    verificaErros(p);
    a = fork();
    verificaErros(a);
    
    printf("Sistemas de Computadores\n");
    return 0;
}

/** a)
 *      o
 *      |  fork() linha(8)
 *      |-----------------------------
 *      |		              |
 *      |	fork() linha(9)	      | fork() linha(9)
 *      |---------------   	      |--------------
 *      |		|	      |              |
 *      |		|	      |              |
 *      |		|	      |              |
 *      |		|	      |              |
 *   printf()       printf()       printf()       printf()  -- linha(10)
 */
 
 // b) 4x
 
 // c)
void verificaErros(int pid){
	if(pid < 0){
    	perror("Erro ao criar processo: ");
    	exit(-1);
    }
}
