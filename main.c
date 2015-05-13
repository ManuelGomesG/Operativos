#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "persona.h"

main() {
	struct PERSONA p;

	strcpy(p.nombre,"ricardo");
	//p.amigos = NULL;

	Lista l = NULL;

	l = insertar(l,&p);
}