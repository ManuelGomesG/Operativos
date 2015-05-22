#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "header_p1.h"

int main(int argc, char *argv[]) {
	system("clear");
	Lista l = leer_entrada(argv[1]);
	int nprocesos = atoi(argv[2]);
	int npersonas = tam(l);

	map_procesos(l,argv[1],nprocesos,npersonas);

	DIR *dir;
	struct dirent *dp;
	Lista_t tuplas = NULL;

	dir = opendir("./datos");

	while ((dp=readdir(dir)) != NULL) {
	    if ((strcmp(dp->d_name, ".") != 0) && (strcmp(dp->d_name, "..") != 0)) {
			tuplas = merge(tuplas, leer_tuplas("./datos/",dp->d_name));
		}
	}

	closedir(dir);

	FILE *fp = fopen("./salida", "w");
	imprimir_t(tuplas, fp);
	fclose(fp);
	system("rm datos/*.txt");
	destruir_t(tuplas);

	destruir(l);

	return 0;
}