#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "hijos.h"


void phijos(int n, int m,int l2){
	int status, i,nprocesos;
 	pid_t childpid;
	for (i = 0; i < n; ++i) {
		if ((childpid = fork()) < 0) {
		perror("fork:");
		exit(1);
		}
		// Codigo que ejecutaran los hijos
		if (childpid == 0) {
		
		int *archs;
		printf("Soy el hijo con pid %ld y mis archivos son:", getpid());
		archs=randn(m, l2);
		for (i=0; i<n; i++){
			printf("%d , ", archs[i]);
		}
		printf("\n");
		exit(0);
		}
	}
	for (i = 0; i < n; ++i){
 			wait(&status);
 			printf("El padre termina\n");
 		}
 	}