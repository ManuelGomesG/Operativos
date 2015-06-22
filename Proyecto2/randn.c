#include "randn.h"
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>



int* randn(int n, int l){
    int *r=malloc(n * sizeof *r);

    int i;
    for ( i=0; i<n; i++){
        r[i]=rand() % l;
        r[i]++;
        }
    return r;
}


int contarArchivos(int path){
	int i;
	int cont = 0;
	int result;
    struct stat statBuf;
    mode_t mode;

	for (i=0; i<20; i++){

		result=stat(i, &statBuf);
		     if (result==-1) {
		       printf("Error");
		       exit;
		    }
		    mode=statBuf.st_mode;

		    if (S_ISREG(mode)){
		    	cont++;
		    }
	}
	return cont;
}