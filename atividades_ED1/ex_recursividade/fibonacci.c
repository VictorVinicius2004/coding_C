#include <stdio.h>

void fibonacci(int elemento, int num1, int num2){
	if(!elemento)
		return;
	int atual = ((num1==0) & (num2==0))? 1 : num1+num2;
	printf("[%d]\n",atual);
	fibonacci(elemento-1,num2,atual);
}

int main(){
	fibonacci(45,0,0);
	return 0;
}

