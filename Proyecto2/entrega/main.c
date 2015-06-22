/*
Taller de Sistemas Operativos I.
Abril-Julio 2015.
Proyecto 2.

Código principal.

Hecho por:
	Ricardo Münch. Carnet: 11-10684.
	Manuel Gomes. Carnet: 11-10375.
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>
#include "funciones.h"

int main(int argc, char *argv[]) {
	DIR *dir; // directorio donde están las carpetas con los archivos a leer.
	int n; // número de procesos hijos a ejecutarse.
	int m; // número de archivos que cada proceso debe leer.
	char *salida; // archivo donde se imprimirá el resultado.
	char *path; // string con el camino de la carpeta a revisar.
	int status; // status de un proceso hijo al finalizar.
	int i; // contador.
	int n_carpeta; // entero para almacenar un número de carpeta aleatorio.
	char carpeta[4]; // string con el nombre de una carpeta aleatoria.
	char t[1048576]; // buffer para recolectar los textos de los hijos (es de 1 mb).
	FILE *archSalida; // file descriptor para el archivo de salida.


	/* CHEQUEO DE LOS FLAGS */
	if (!strcmp(argv[1], "-d")) {
		if ( !(dir = opendir(argv[2])) ) {
			printf("==%d== ERROR: no se pudo abrir la carpeta %s\n", getpid(), argv[2]);
			return -1;
		}

		path = malloc(strlen(argv[2])+2);
		strcpy(path, argv[2]);
		strcat(path, "/");
		n = atoi(argv[3]);
		m = atoi(argv[4]);
		salida = argv[5];
	} else {
		dir = opendir(".");
		path = malloc(3);
		strcpy(path, "./");
		n = atoi(argv[1]);
		m = atoi(argv[2]);
		salida = argv[3];
	}

	/* CHEQUEO DEL NÚMERO DE PROCESOS Y DE ARCHIVOS */
	if (n <= 0 || 10 < n || m <= 0 || 20 < m) {
		printf("ERROR: número de hijos o de archivos inválido.\n");
		free(path);
		return -1;
	}


	textoHijo hijos[n]; // arreglo que contiene los pid y los pipes de cada hijo.
	srand(time(NULL)); // seed del generador de números aleatorios.

	/* CICLO PRINCIPAL */
	for (i = 0; i < n; i++) {
		pipe(hijos[i].pipe); // se inicializa el pipe del hijo actual.
		n_carpeta = rand()%10+1; // se genera el número de carpeta del hijo.
		sprintf(carpeta, "%d", n_carpeta); // se convierte en string.
		strcat(carpeta, "/");

		if ( (hijos[i].pid = fork()) ) {
			close(hijos[i].pipe[1]);
		} else {
			pid_t yo = getpid(); // pid del proceso actual.
			int nArchivos = 0; // cantidad de archivos procesados.
			char *c2; // string para almacenar el path del archivo que se está procesando.
			char *c = concatenar(path, carpeta); // path de la carpeta que le tocó al proceso.
			DIR *directorio; // cirectorio que le tocó al proceso actual.
			struct dirent *entry; // elemento del directorio, se usa para iterar dentro de él.
			char *texto; // texto del archivoque se leyó.

			if ( !(directorio = opendir(c)) ) {
				printf("--%d-- ERROR: no se pudo abrir la carpeta %s\n", yo, c);
				free(c);
				exit(-1);
			}

			close(hijos[i].pipe[0]);

			while ( (entry = readdir(directorio)) ) {
				if (entry->d_type == 8) {
					c2 = concatenar(c, entry->d_name);
					texto = leerArchivo(c2);
					write(hijos[i].pipe[1], texto, strlen(texto));
					write(hijos[i].pipe[1], "\n", 1);
					free(c2);
					free(texto);
					
					++nArchivos;

					if (nArchivos == m) {
						break;
					}
				}
			}

			write(hijos[i].pipe[1], "\0", 2);

			free(c);
			closedir(directorio);
			exit(nArchivos);
		}
	}

	closedir(dir);
	free(path);

	for (i = 0; i < n; i++) {
		wait(&status);
	}

	fclose(fopen(salida, "w"));
	archSalida = fopen(salida, "a");

	for (i = 0; i < n; i++) {
		read(hijos[i].pipe[0], t, 1048576);
		printf("%s", t);
		fprintf(archSalida, "%s", t);
	}

	fclose(archSalida);

	return 0;
}