#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <gconio.h>

int main(){
	char nome1[20], nome2[20], nome3[20], aux[20];
	printf("Digite três nomes\n");
	scanf(" %[^\n]s", nome1);
	scanf(" %[^\n]s", nome2);
	scanf(" %[^\n]s", nome3);
	
	for (int i = 0; i < 20; i++){
		if(nome1[i]>nome2[i]){
			strcpy(aux, nome1);
			strcpy(nome1, nome2);
			strcpy(nome2, aux);
			break;
		}
		if(nome1[i]<nome2[i])
			break;
	}

	for (int i = 0; i < 20; i++){
		if(nome2[i]>nome3[i]){
			strcpy(aux, nome2);
			strcpy(nome2, nome3);
			strcpy(nome3, aux);
			break;
		}
		if(nome2[i]<nome3[i])
			break;
	}

	for (int i = 0; i < 20; i++){
		if(nome1[i]>nome2[i]){
			strcpy(aux, nome1);
			strcpy(nome1, nome2);
			strcpy(nome2, aux);
			break;
		}
		if(nome1[i]<nome2[i])
			break;
	}
	
	printf("\n%s \n%s \n%s\n", nome1, nome2, nome3);
	return 0;
}

