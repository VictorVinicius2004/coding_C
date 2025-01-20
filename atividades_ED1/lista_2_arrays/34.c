/*Faça um programa que calcule quantos segundos já se passaram no dia de hoje.*/

#include <stdio.h>

int main(){
	int mult=3600, num=0, total=0;
	
	for(int i=0; i<8; i++){
		
		if(__TIME__[i]>='0' && __TIME__[i]<='9'){
			num*=10;
			num+=__TIME__[i]-'0';
		}
		else{
			total+=mult*num;
			mult/=60;
			num=0;
		}
	}
	
	printf("%d é o total de segundos que se passaram hoje.", total);
	return 0;
}

