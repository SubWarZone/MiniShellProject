#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define tailleBuffer 100


int compterMots(char * chaine){
	int i=1;
	int compteur = 0;
	//nous 
	while(chaine[i] != '\0'){
		if(chaine[i] == ' '){
			
				compteur++;
		}
		i++;
	}
	return compteur+1; // il y a $compteur espace donc il y a 7 mots
}

char **separerLaChaine(char *chaine){
	
	int nb_mots = compterMots(chaine);
	char **monTableauDeChaine=NULL;
	monTableauDeChaine= malloc(nb_mots*(sizeof(char*)));
	char c;
	char buffer[tailleBuffer];
	int i=1;
	printf("il y a %d mots\n",nb_mots);

	

	monTableauDeChaine[0]= &chaine[0];


	while(chaine[i] != '\0'){
		if(chaine[i] == ' '){
			
			monTableauDeChaine[i]= &chaine[i+1];
			chaine[i]= '\0';
		}
		i++;
	}
	return monTableauDeChaine;
}

int main(int argc, char **argv)
{
	
	int continuer=1;


	while (continuer){
		char buffer[tailleBuffer];
		char **chaineSeparee=NULL;
		int i;
		fgets(buffer,tailleBuffer,stdin);

		printf("ma chaine est : %s\n",buffer);
		
		chaineSeparee= separerLaChaine(buffer);
		
		
		for(i=0;i<4;i++){
			printf("%s\n",chaineSeparee[i]);
		}
		
		//printf("%s\n",);

	}

	return 0;

	

}
