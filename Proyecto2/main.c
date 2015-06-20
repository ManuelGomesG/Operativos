
#include "randn.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	srand ( time(NULL) );
	int n=5;
	int l1=10; // Máximo valor de los números random de los procesos.
	int l2=20; // Máximo valor de los números de archivos a leer.
	int *o;
	o=randn(n,l1);
	int i;
	for (i=0; i<n; i++){
		printf("%d\n", o[i]);
	}

	phijos(n,6,l2);
	

	return 0;
}