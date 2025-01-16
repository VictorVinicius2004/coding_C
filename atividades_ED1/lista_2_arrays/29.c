/*Faça um programa que leia uma string A e outra string B. O programa deve informar a seguinte
informação, conforme o caso: "String A está contida em B" ou "String B está contida em A" ou "As
strings são incompatíveis".*/

#include <string.h>
#include <stdio.h>

int main(){
	char A[15], B[15];
	printf("Digite duas strings.\n");
	scanf(" %s %s", A, B);
	int len1=strlen(A), len2=strlen(B), cont=0, AemB=0, BemA=0;
	
	for(int i=0; i<len1; i++){
		for(int j=0; j<len2; j++)
			if(A[i]==B[j]){
				cont++;
				break;
			}
	}
	if(cont==len1)
		AemB=1;
		
	cont=0;
	for(int i=0; i<len2; i++){
		for(int j=0; j<len1; j++)
			if(B[i]==A[j]){
				cont++;
				break;
			}
	}
	if(cont==len2)
		BemA=1;
		
	if(AemB)
		printf("A está contido em B.\n");
	if(BemA)
		printf("B está contido em A.\n");
	if(!AemB && !BemA)
		printf("As strings são incompatíveis.");
	return 0;
}

