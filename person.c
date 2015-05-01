#include "person.h"
#include "stdio.h"


people create(){
	list ppl;
	ppl = malloc(sizeof(person));
	return ppl;
}

people getfriends(FILE *fp, list l){
	char *buffer[1000];
	while (fscanf(fp,"%s ", buffer) == EOF){
		l->name = buffer;
		fscanf(fp, "%s", buffer);
		if (fscanf(fp, "%s", buffer) != "-None-"){
			l->lfriends = malloc(sizeof(list));
			person *auxl = l->lfriends;
			while (fscanf(fp, "%s", buffer) == "\n"){
				free(auxl->name);
				auxl->name = buffer;
				auxl->lnext = malloc(sizeof(person));
				auxl=lnext;
 			}
 			free(auxl);
		}



}