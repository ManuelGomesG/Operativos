#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

list create(){
	list ppl;
	ppl = malloc(sizeof(person));
	return ppl;
}

list setUp(FILE *fp){ // Crea la lista de personas y guarda cada persona con su lista de amigos.
	list lista = malloc(sizeof(list)); // Lista grande.
	auxc1 = lista;  // Auxliar para moverse por la lista en el ciclo del else.
	auxc2 = lista->lfriends; //Auxiliar para moverse por las listas de amigos del else.
	list aux1 = lista->lfriends; //Auxiliar para moverse dentro de la lista de amigos.
	list aux2 = lista->rnext; //Auxiliar que apunta la siguiente persona de la lista grande.
	char buffer[200]; // Primer buffer (scout).
	char *buffer2; // Buffer que seguro.
	fscanf(fp,"%s", buffer); // Scan de la primera persona.
	while (fscanf(fp,"%s", &buffer) != EOF){
		if (buffer == "->"){
			aux2 = malloc(sizeof(person)); // Crea una persona.
			strcpy(aux2->name,buffer2); // Le coloca nombre a la persona.
			// aux1 = aux2->lfriends;  * No se si sea necesario
		}
		if (buffer == "-None-"){
			aux2->lfriends=NULL; // La persona no tiene amigos, el apuntador a su lista de amigos es NULL.
		}
		else {
			while 

		}

	}



}

/*





		char buffer[1024];
		while (fscanf(fp,"%s ->", &buffer) != EOF){
			printf("%s\n", buffer);
			strcpy(l->name, buffer);
			l->lfriends = malloc(sizeof(list));
			printf("amigos:\n" );
			do 
			{
				fscanf(fp,"%s",buffer);
				if (strcmp(buffer,"-None-")){
					
					list auxl;
					auxl = l->lfriends;
					strcpy(auxl->name, buffer);
					printf("%s      gybgybgy\n",auxl->name);
					auxl->lnext = malloc(sizeof(person));
					auxl=auxl->lnext;

				}

				printf("culo\n" );
			}while (strcmp(buffer,"\n"));

		}




	char buffer[1000];
	while (fscanf(fp,"%s ->", buffer) != EOF){
		strcpy(l->name , buffer);
		printf("Nombres: \n %s\n", buffer );
		if (fscanf(fp, "%s", buffer) != "-None-"){
			l->lfriends = malloc(sizeof(list));
			printf("amigos: \n %s\n", buffer);
			person *auxl = l->lfriends;
			while (fscanf(fp, "%s", buffer) == "\n"){
					printf("%s\n", buffer);
				strcpy(auxl->name , buffer);
				auxl->lnext = malloc(sizeof(person));
				auxl=auxl->lnext;
 			}
 			free(auxl);
		}
	}

	*/