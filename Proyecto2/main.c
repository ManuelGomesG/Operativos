
#include "randn.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	srand ( getpid() );
	int n=5;
	int l1=10; 		// Máximo valor de los números random de los procesos.
	int l2=20; 		// Máximo valor de los números de archivos a leer.
	int pd[2][n];	//Arreglo de pipes.
	int *o; 		// Arreglo de números random (n).
	o=randn(n,l1);
	int i;
	/*for (i=0; i<n; i++){
		printf("%d\n", o[i]);
	}*/
	printf("Antes de crear hijos\n");

	phijos(n,6,l2,o,pd);
	

	return 0;
}