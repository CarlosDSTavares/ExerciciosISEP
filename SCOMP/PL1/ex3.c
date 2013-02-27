#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main ( void ) {
    pid_t pid;
    int i;
    
    for (i=0; i<4; i++ )
    pid = fork();
    
    printf("SistComp\n");
    
    return 0;
}

// a)

/**
 *  o
 *  | fork()                                                                          1º
 *  |---------------------------------------
 *  | fork()                                | fork()                                  2º
 *  |-------------------                    |-------------------
 *  |                   |                   |                   |
 *  | fork()            | fork()            | fork()            | fork()              3º
 *  |---------          |---------          |---------          |--------- 
 *  |fork()   |fork()   |fork()   | fork()  |fork()   |fork()   |fork()   | fork()    4º
 *  |----     |----     |----     |----     |----     |----     |----     |----
 *  |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
 */
 
 // Sao criados 15 processos (o princial nao é criado, ja existe.)
 
 // b) 16x
 
