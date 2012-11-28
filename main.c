#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define tailleBuffer 100


int compterMots(char * chaine){
	int i=1;
	int compteur = 0;
	//nous 
	while(chaine[i] != '\0'){
		if((chaine[i] == ' ' && chaine[i-1] != ' ') 
			||( chaine[i+1] != ' ' && chaine[i] == ' ')
			||(chaine[i] == ' ' && chaine[i+1] != ' ')){
			
				compteur++;
		}
		i++;
	}
	return compteur + 1;
}

char **separerLaChaine(char *chaine){
	char **monTableauDeChaine = NULL;
	char c;
	char buffer[tailleBuffer];
	int i=0;
	int compteur = compterMots(chaine);
	
	printf("il y a %d mots\n",compteur);

	monTableauDeChaine = malloc(compteur*(sizeof(char*)));

	monTableauDeChaine[0]= &chaine[0];


	while(chaine[i] != '\0'){
		while(chaine[i] != ' '){
			monTableauDeChaine[i]= &chaine[i+1];
			chaine[i]= ' ';
		}
	}
	return monTableauDeChaine;
}

int main(int argc, char **argv)
{
	int continuer=1;


	while (continuer){
		char buffer[tailleBuffer];
		char **chaineSeparee=NULL;

		fgets(buffer,tailleBuffer,stdin);

		printf("ma chaine est : %s\n",buffer);
		
		chaineSeparee= separerLaChaine(buffer);
		
		printf("%s\n",*chaineSeparee[0]);
		
		
		//printf("%s\n",);

	}

	return 0;
}
