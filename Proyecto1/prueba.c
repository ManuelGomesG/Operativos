#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void main(int argc, char *argv[]) {
     int i, n;
     pid_t hijopid;


     if (argc !=2) {
       fprintf(stderr,"USO: %s num_procesos\n", argv[0]);  
       exit(1);
     }
     n = atoi(argv[1]);
     hijopid = 0;
     for (i = 1; i < n; i++){
	if (hijopid = fork()) 
           break;
       	printf("hola\n");
     if (hijopid == -1) {
        perror("error al ejecutar el fork");
        exit(1);  
     }
     fprintf(stdout,"i:%d proceso - %ld Id del padre - %ld ID del hijo\n",i, (long)getppid(), (long)getpid());
     }
}

