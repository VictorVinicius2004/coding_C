/*Faça um programa em C que, utilizando a biblioteca customizada "datetime.h" preenche um array
contendo 10 horários aleatórios: dt_rand_time(). Imprima todos os horários obtidos.
Após isso, obtenha a hora atual do sistema (pela própria biblioteca) e imprima qual dos horários
existentes no array é o mais próximo do horário atual do sistema, tanto do passado quanto do futuro
(Imagine como se fosse um alerta para o último compromisso e próximo compromisso)*/

#include <stdlib.h>
#include <stdio.h>
#include <datetime.h>

#define HORARIOS 10

int diferenca_tempo(Datetime tempo_atual, Datetime tempo){
	int segundos=tempo.sec+tempo.min*60+tempo.hour*3600;
	int segundos_atual=tempo_atual.sec+tempo_atual.min*60+tempo_atual.hour*3600;
	
	return (segundos>segundos_atual)? segundos-segundos_atual : segundos_atual-segundos;
}

int main(){
	srand(time(NULL));
	Datetime horarios[HORARIOS];
	Datetime horaatual=dt_now();
	for(int i=0; i<HORARIOS; i++){
		horarios[i]=dt_rand_time();
		dt_print(horarios[i]);
		printf("\n");
	}
	printf("\nHora atual: ");
	dt_print(horaatual);
	printf("\n\n");
	
	Datetime hora_proxima;
	for(int i=0; i<HORARIOS; i++){
		if(i==0)
			hora_proxima=horarios[i];
		else if(diferenca_tempo(horaatual, hora_proxima)>diferenca_tempo(horaatual, horarios[i]))
			hora_proxima=horarios[i];
	}
	
	printf("Horário mais próximo do atual: ");
	dt_print(hora_proxima);
	return 0;
}

