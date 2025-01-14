#include <stdio.h>
#include <string.h>

int main(){
	char string[15];
	printf("Digite uma palavra.\n");
	scanf(" %s", string);
	int len=strlen(string);
	
	for(int i=0; i<len; i++){
		if(string[i]>='a' && string[i]<='z')
			string[i]-='a'-1;
		else
			string[i]-='A'-1;
		
		printf("%d ", string[i]);
	}
	return 0;
}
