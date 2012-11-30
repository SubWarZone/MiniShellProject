#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define tailleBuffer 100

int compterMots(char * chaine){
	int i=1;
	int compteur = 0;
	//nous 
	while(chaine[i] != '\0'){
		if(chaine[i] == ' ' && chaine[i-1] != ' '){	
				compteur++;
		}
		i++;
	}
	return compteur + 1; // il y a compteur espace et donc compter+1 mots
}

char **separerLaChaine(char *chaine){
	
}

int main(int argc, char **argv)
{
	int i = 0;
	int continuer=1;
	char delims[] = " ";
	char *result = NULL;
	char **TousMesMots = malloc(15 * sizeof(char*)); // 15 cest nombre de mots

	while (continuer){
		char buffer[tailleBuffer];

		fgets(buffer,tailleBuffer,stdin);

		printf("ma chaine est : %s\n",buffer);
		
		result = strtok(buffer, delims );
		while( result != NULL ) {
			printf( "result is \"%s\"\n", result);
			TousMesMots[i] = malloc((strlen(result)) * sizeof(char));
			TousMesMots[i] = result; //&result[i]
			result = strtok(NULL, delims);
			i++;
		}
		
		printf("le troisieme mot est: %s", TousMesMots[2]);
	}
/*	char **array1 = malloc(nrows * sizeof(char *)); // Allocate row pointers
	for(i = 0; i < nrows; i++)
	  array1[i] = malloc(ncolumns * sizeof(char)); */ 
	return 0;
}
