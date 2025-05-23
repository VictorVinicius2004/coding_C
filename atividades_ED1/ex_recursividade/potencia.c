#include <stdio.h>

int potencia(int base, int expoente){
	return (expoente==0)? 1 : base * potencia(base,expoente-1);
}

int main(){
	printf("%d\n", potencia(2,5));
	return 0;
}
