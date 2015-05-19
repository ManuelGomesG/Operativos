struct PERSONA {
	char *nombre;
	struct PERSONA *amigos;
	struct PERSONA *sig;
};

typedef struct PERSONA Persona;
typedef Persona *Lista;

/*funciones de lista.c*/
Lista insertar(Lista, char *);
Lista eliminar(Lista, Persona *);
Lista destruir(Lista); 
void consultar(Lista);

/*funciones para el main (funciones.c)*/
int contar_lineas(const char*);
Lista leer_entrada(const char*);