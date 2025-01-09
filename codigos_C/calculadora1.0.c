#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <MINHA_BIBLIOTECA.h>

int main(){
	char expressao[100], operador;
	printf("Digite uma expressão numérica(este código não considera ordem de prioridade como multiplicação ou parênteses)\n");
	printf("Operadores: + soma, - subtração, / divisão, * multiplicação\n");
	printf("Digite sua expressão:\n");
	scanf(" %s", expressao);
	int p_util, fim=0, inicio;
	float result=0;
	
	p_util=strlen(expressao);
	for(int i=0; i<p_util; i++){
		if(expressao[i]>='0' && expressao[i]<='9'){
			result*=10;
			result+=(expressao[i]-'0');
		}
		else{
			inicio=i+1;
			break;
			
		}
	}

	printf("\n");
	do{
		float num=0;
		
		for (int i = 0; i < p_util; i++)
			if(entre_string(expressao[i], "+-/*")){
				operador=expressao[i];
				expressao[i]='!';
				break;
			}
			
		for(int i=inicio; i<p_util+1; i++){
			if(expressao[i]>='0' && expressao[i]<='9'){
				num*=10;
				num+=expressao[i]-'0';
				expressao[i]='@';
			}
			else{	
				inicio=i+1;
				if(expressao[i]==0)
					fim=1;
				break;
				
			}
		}
		
		printf("%.2f%c%.2f=", result, operador, num);
		switch(operador){
			case '+': result+=num; break;
			case '-': result-=num; break;
			case '*': result*=num; break;
			case '/': result/=num; break;
		}
		printf("%.2f\n", result);
	}while(!fim);
	
	printf("\nResultado: %.2f", result);
	return 0;
}
