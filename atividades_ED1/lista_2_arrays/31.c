/*O código de barras é essencial na automatização do processo de vendas. Esse código possui um formato
conhecido por EAN-13, contendo 13 dígitos numéricos, sendo que os 3 primeiros identificam o País de
origem (Brasil == 789), os 9 dígitos seguintes identificam a empresa fabricante e o produto em si, e o
último - 13o dígito - é um validador, chamado de “Dígito Verificador - DV” que é calculado com base na
sequência anterior, e que serve para dar confiabilidade ao processo de leitura do código de barras.
O cálculo do DV no EAN-13 é o seguinte: Considerando do 1o ao 12o dígito, somar todas as posições
pares e multiplicar a soma pelo valor 3. Ao resultado do passo anterior, somar todas as posições ímpares
da sequência. O DV deverá ser o valor que tornará toda a soma alcançada em um múltiplo de 10.
Faça um programa que valide vários Códigos de Barras lidos pelo usuário.*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	char codigo[14];
	do{
		int valido=1;
		
		printf("Digite o código de barras.\n");
		scanf(" %s", codigo);
		
		for(int i=0; i<13; i++)
			if(codigo[i]<'0' || codigo[i]>'9'){
				valido=0;
				break;
			}
			
		if(strlen(codigo)!=13)
			valido=0;
			
		if(valido)
			break;
		else
			system("clear");
	}while(1);
	
	//validando o código
	int pares=0, impares=0;
	for(int i=0; i<12; i++){
		//somando os pares
		if((codigo[i]-'0')%2==0)
			pares+=codigo[i]-'0';
		//somando os impares
		else
			impares+=codigo[i]-'0';
	}
	int total=impares+(pares*3)+codigo[12];
	
	if(total%10==0)
		printf("Código de barras válido");
	else
		printf("Código de barras inválido");
	return 0;
}

