#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
//#include "proyecto1.h"

main() {
	FILE* fp;
	char buffer[30];
	char* p;

	fp = fopen("../hola.txt","r");
	fscanf(fp,"%s",buffer);
	printf("%s\n", p);
}