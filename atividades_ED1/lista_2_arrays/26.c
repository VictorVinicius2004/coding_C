/*Faça um programa que verifique se um endereço de e-mail é válido ou não. Para um e-mail ser válido,
deve possuir um único símbolo '@' (mas que não seja o primeiro), pelo menos um símbolo ponto '.' após
o símbolo '@' (mas que não seja o último), e não possuir espaços em branco nem outros caracteres
especiais. Faça várias validações na mesma execução do programa.*/

#include <string.h>
#include <stdio.h>
#include <MINHA_BIBLIOTECA.h>

#define entre_az(c) (c>='a' && c<='z') 
#define entre_AZ(c) (c>='A' && c<='Z') 
#define entre_09(c) (c>='0' && c<='9') 

int main(){
	char email[30];
	printf("Digite o email:\n");
	scanf(" %[^\n]s", email);
	
	int valido=1, len=strlen(email);
	for(int i=0; i<len; i++){
		if((!entre_string(email[i], "-_@.") && !entre_az(email[i]) && !entre_AZ(email[i]) && !entre_09(email[i])) || email[len-1]=='.'){
			valido=0;
			break;
		}
		
		if(email[i]=='@'){
			for(int j=i+1; j<len; j++)
				if(email[j]=='@'){
					valido=0;
					break;
				}
			if(email[i+1]!='.' || !valido){
				valido=0;
				break;
			}
		}
	}
	
	(valido==1)? printf("email válido") : printf("email inválido");
	return 0;
}

