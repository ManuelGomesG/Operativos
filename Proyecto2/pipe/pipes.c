#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
	int p[2];
	char t[1000];

	pipe(p);

	if (fork()) {
		close(p[1]);
		read(p[0], t, 1000);
		printf("%s", t);
	} else {
		/* esto es para leer lo del archivo*/
		FILE *fd = fopen("hola","r");

		fseek(fd, 0, SEEK_END);
		long tam = ftell(fd);
		fseek(fd, 0, SEEK_SET);

		char *texto = malloc(tam + 1);
		fread(texto, tam, 1, fd);
		fclose(fd);

		texto[tam] = 0;
		/* hasta aquí*/
		
		close(p[0]);
		write(p[1], texto, strlen(texto)+1);
		free(texto);
	}
}