/*
Taller de Sistemas Operativos I.
Abril-Julio 2015.
Proyecto 2.

Estructuras de datos y encabezados de funciones a usar en main.c.

Hecho por:
	Ricardo Münch. Carnet: 11-10684.
	Manuel Gomes. Carnet: 11-10375.
*/

struct TEXTOHIJO {
	pid_t pid;
	int pipe[2];
};

typedef struct TEXTOHIJO textoHijo;

char *leerArchivo(char *);
char *concatenar(char *, char *);