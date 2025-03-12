#include <stdlib.h>
#include <stdio.h>
#include <time.h>

enum {MAO=5, PCWIN, USRWIN, EMPATE};

void interface(int money_user, int moneyPC){
	system("clear");
	printf("====================== BLACKJACK VEGAS [21] ======================\n");
	printf("REGRAS: Dealer distribui Cartas: [Ás,2,3, ... ,J,Q,K]\n");
	printf("As Cartas Reais: [J] [Q] e [K] valem 10 Pontos\n");
	printf("Um [Ás] COM presença de Carta Real vale 11 Pontos\n");
	printf("Um [Ás] SEM presença de Carta Real vale 01 Ponto\n");
	printf("O PC sempre revelará a mesma quantidade de cartas do USER\n");
	printf("Vence quem somar a maior qtde de pontos, igual ou abaixo de 21\n\n");
	printf("User:  $ %d \nPC:    $ %d\n\n", money_user, moneyPC);
	printf("Quanto deseja apostar?\n");
}

void getcarta(int user[], int *cont){
	user[*cont]=rand()%13+1;
	*cont+=1;
}

int aposta(int *moneyuser, int *moneypc){
	int valor;
	printf("valor da aposta:\n");
	do{
		scanf(" %d", &valor);
	}while(valor>*moneyuser || valor>*moneypc);

	*moneyuser-=valor;
	*moneypc-=valor;
	return valor*2;
}

void mao(int usr[]){
	for(int i=0; i<MAO; i++){
		switch(usr[i]){
			case 0:
				printf("[ ] ");
				break;
			case 1:
				printf("[A] ");
				break;
			case 11:
				printf("[J] ");
				break;
			case 12:
				printf("[Q] ");
				break;
			case 13:
				printf("[K] ");
				break;
			default:
				printf("[%d] ", usr[i]);
		}
	}
	printf("\n");
}

void mostrarCartas(int pc[], int user[]){
	printf("USER:\n");
	mao(user);
	printf("PC:\n");
	mao(pc);
}

char escolha(int user[], int *cont){
	char choice;
	printf("[+] pegar carta \n[.] finalizar\n");
	do{
		scanf(" %c", &choice);
	}while(choice!='+' && choice!='.');
	
	return choice;
}

int pontua_AS(int user[]){
	for(int i=0; i<MAO; i++)
		if(user[i]>10)
			return 10;

	return 1;
}

int verifica_pontuacao(int user[]){
	int pontos=0;
	for(int i=0; i<MAO; i++){
		if(user[i]!=0)
			pontos += (user[i]>=2 && user[i]<=10)? user[i] :
			(user[i]>10)? 10 : pontua_AS(user);
	}

	return pontos;
}

int verifica_vencedor(int user[],int pc[]){
	int pontospc = verifica_pontuacao(pc);
	int pontosusr = verifica_pontuacao(user);

	printf("USER VS PC \n%d VS %d\n", pontosusr, pontospc);
	if(pontospc == pontosusr)
		return EMPATE;
	if(pontosusr>21 && pontospc>21){
		if(pontospc>pontosusr)
			return USRWIN;
		return PCWIN;
	}
	if(pontospc>21)
		return USRWIN;
	if(pontosusr>21)
		return PCWIN;
	if(pontosusr>pontospc)
		return USRWIN;
	return PCWIN;
}

void premia_vencedor(int *money_user, int *moneyPC, int resultado, int premio){
	switch(resultado){
		case EMPATE:
			printf("Empate\n");
			*money_user+=premio/2;
			*moneyPC+=premio/2;
			break;
		case PCWIN:
			printf("Vencedor: PC\n");
			*moneyPC+=premio;
			break;
		case USRWIN:
			printf("Vencedor: USER\n");
			*money_user+=premio;
	}
}

void resultado_final(int money_user, int moneyPC){
	printf("USER: $ %d \nPC: $ %d\n", money_user, moneyPC);

	if(moneyPC==0)
		printf("Você quebrou a banca\n");
	else if(money_user==0)
		printf("Sem sorte?\n");
	else if(money_user>100)
		printf("Saiu no lucro\n");
	else
		printf("Saiu no prejuízo");
}

void reseta_maos(int user[], int pc[], int *contuser, int *contpc){
	for(int i=0; i<MAO; i++){
		user[i]=0;
		pc[i]=0;
	}
	*contuser=0;
	*contpc=0;
}

int main(){
	srand(time(NULL));
	int user[5]={0}, pc[5]={0}, contuser=0, contpc=0;
	int money_user=100, moneyPC=100, premio;
	
	do{
		//inicializando as mões
		for(int i=0; i<2; i++)
			getcarta(user, &contuser);
		getcarta(pc, &contpc);

		interface(money_user, moneyPC);

		//valor da posta
		premio=aposta(&money_user, &moneyPC);

		//jogo rodando
		do{
			mostrarCartas(pc, user);
			//escolha entra pegar mais carta ou parar
			int choice = escolha(user, &contuser);
			system("clear");
			if(choice=='+')
				getcarta(user, &contuser);	
			else
				break;

			if(verifica_pontuacao(user)>21 || verifica_pontuacao(pc)>21)
				break;
		}while(1);
		
		//incrementa cartas a mao do PC até ficar com a mesma quantidade do USER
		while(contpc<contuser)
			getcarta(pc, &contpc);
		
		mostrarCartas(pc, user);
		premia_vencedor(&money_user, &moneyPC, verifica_vencedor(user, pc), premio);
		premio=0;
		
		if(!(money_user>0 && moneyPC>0))
			break;

		int saida=0;
		printf("Deseja sair? 1-sim, outra coisa-não\n");
		scanf(" %d", &saida);
		if(saida==1)
			break;

		reseta_maos(user, pc, &contuser, &contpc);
	}while(1);

	resultado_final(money_user, moneyPC);
	return 0;
}
