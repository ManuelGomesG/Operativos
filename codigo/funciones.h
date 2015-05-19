struct PERSONA {
	char *nombre;
	struct PERSONA *sig;
};

typedef struct PERSONA Persona;
typedef Persona *lista;

/*funciones de lista.c*/


/*funciones para el main (funciones.c)*/
int contar_lineas(char*);
void leer_entrada(char*);