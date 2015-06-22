#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "hijos.h"


void phijos(int n, int m,int l2, int **pd){
	int status, i;
 	pid_t childpid;

	for (i = 0; i < n; ++i) {
		if ((childpid = fork()) < 0) { 
			perror("fork:");
			exit(1);
		}	// Error haciendo fork.
		pipe(pd[i]);
		// Código que ejecutarán los hijos
		if (childpid == 0) {
			char *buffer; 		// Buffer donde se guarda lo que se va a mandar hacia al padre.
			close(pd[0][i]); 	// Cierra la lectura del hijo.
			srand ( getpid() );	// Seed para el random.

			/*if (m>contarArchivos(o[i])){
				printf("Contar archivos: %d\n",contarArchivos(o[i]));
				m=contarArchivos(o[i]); 	//Se leerá la cantidad de archivos(No necesariamente se leerán todos los archivos, se pueden repetir). 
				l2=contarArchivos(o[i]);	// El límite maximo para el random.
			}	// Caso en el que hay menos archivos de los que piden leer.*/

			int *archs;
			printf("Soy el hijo con pid %ld y mis archivos son:", getpid());
			archs=randn(m, l2); // Random de los archivos.
			
			//Imprime el arreglo de archivos que abre cada hijo.
			for (i=0; i<n; i++){
				printf("%d , ", archs[i]);
			}
			

			printf("\n");
			exit(m);
		}
		if (!childpid == 0) {
			close(pd[1][i]);
	}
	for (i = 0; i < n; ++i){
 			wait(&status);
 			printf("El padre termina\n");
 			//hola=read(pd[0][i],)
 		}
 	}
 }