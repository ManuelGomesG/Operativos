#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "hijos.h"


void phijos(int n, int m,int l2, int **pd){
	int status, i,hola;
 	pid_t childpid;

	for (i = 0; i < n; ++i) {
		if ((childpid = fork()) < 0) {
			perror("fork:");
			exit(1);
		}
		pipe(pd[i]);
		// Código que ejecutarán los hijos
		if (childpid == 0) {
			char *buffer; //buffer donde se guarda lo que se va a mandar hacia al padre.
			close(pd[0][i]);
			srand ( getpid() );
			int *archs;
			printf("Soy el hijo con pid %ld y mis archivos son:", getpid());
			archs=randn(m, l2);
			
			//Imprime el arreglo de archivos que abre cada hijo.
			for (i=0; i<n; i++){
				printf("%d , ", archs[i]);
			}
			

			printf("\n");
			exit(0);
		}
		if !(childpid == 0) {
			close(pd[1][i]);
	}
	for (i = 0; i < n; ++i){
 			wait(&status);
 			printf("El padre termina\n");
 			hola=read(pd[0][i],)
 		}
 	}