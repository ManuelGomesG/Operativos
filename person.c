#include "person.h"
#include <stdio.h>
#include "stdlib.h"


list create(){
	list ppl;
	ppl = malloc(sizeof(person));
	return ppl;
}

list getfriends(FILE *fp, list l){
	char buffer[1000];

	while (fscanf(fp,"%s ", buffer) == EOF){
		printf("puta\n");
		strcpy(l->name , buffer);
		printf("%s\n", buffer );
		fscanf(fp, "%s", buffer);
		if (fscanf(fp, "%s", buffer) != "-None-"){
			l->lfriends = malloc(sizeof(list));
			person *auxl = l->lfriends;
			while (fscanf(fp, "%s", buffer) == "\n"){
				free(auxl->name);
				strcpy(auxl->name , buffer);
				auxl->lnext = malloc(sizeof(person));
				auxl=auxl->lnext;
 			}
 			free(auxl);
		}
	}


}