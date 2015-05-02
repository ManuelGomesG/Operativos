#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

list create(){
	list ppl;
	ppl = malloc(sizeof(person));
	return ppl;
}

list getfriends(FILE *fp, list l){
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



}

/*
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