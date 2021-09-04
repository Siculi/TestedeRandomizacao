#include<stdio.h> 
#include<stdlib.h>
#include<time.h>

int main(){
	
	/*
		Este algoritmo foi criando na tentativa de observar o quão aleatorio a função "srand" pode ser.
		
		Teoricamente, quanto maior a quantidade de rodadas, mais proximo o percetual de ambos deve se tornar de 5%
		
		Ambos os casos se aproximas de 5%, mas por alguma razão na maioria da vezes; 
			o primeiro caso sempre tende a percentuais ligeiramente abaixo de cinco. 
			e o segundo caso sempre tende a percentuais ligeiramente acima de cinco.
			
		Talvez contrariando a teoria escolhendo 5 copos temos uma chance rigeiramente maior que 5% 
		Talvez a função "srand" não gere numeros tão aleatorios quanto se espera.
		Ou talvez seja apenas um vies do observador.
	*/
	
	int i, j, Num_20, Num_100[5], resp_20, resp_100, cont_20, cont_100, Total, rodadas; 
	float percent_20, percent_100;
	resp_20 = resp_100 = cont_20 = cont_100 = Total = 0;
	percent_20 = percent_100 = 0.0;	
	
	srand(time(NULL));
	
	printf("Probabilidade de escolher um copo envenenado.\n\n");
	printf("\t- No primeiro caso; a cada rodada 1 copo de 20 estara envenenado.\n");
	printf("\t- No segundo caso; a cada rodada 5 copos de 100 estara envenenado.\n");
	printf("\t- Matematicamente as chances devem ser iguais (5%%) para ambos casos.\n\n");
			
	printf("Quantas rodadas: ");
	scanf("%i", &rodadas); printf("\n");
	
	do{
		
		j = 1; 
		
		Num_20 = rand() % 20 + 1;
		
		for(i=0;i<5;i++)
		{
			Num_100[i] = rand() % 100 + 1;
			// o algoritmo "Do-While" abaixo garante que não havera repetição nos 5 copos sorteados de 100
			do{
				if(Num_100[j] == Num_100[i])
				{
					Num_100[i] = rand() % 100 + 1;
					j = 0;
				}else
					{
						j=j+1;
					}
			}while(j < i);j = 0;						
		}
		
		resp_20 = rand() % 20 + 1; 
		resp_100 = rand() % 20 + 1;
	
		if(resp_20 == Num_20)
			{
				cont_20 = cont_20 + 1;
			}
	
		for(i=0;i<5;i++)
		{
			if(resp_100 == Num_100[i])
			{
				cont_100 = cont_100 + 1;
			}
		}
	
		Total = Total + 1;
	
	}while(Total<rodadas);
	
	percent_20 = (float)cont_20/(float)Total;
	percent_100 = (float)cont_100/(float)Total;
	
	printf("Envenenados em 1 de  20: %i de %i\n", cont_20, rodadas);
	printf("Envenenados em 5 de 100: %i de %i\n", cont_100, rodadas);
	
	printf("\nEm 1 de  20. Envenenado em %.4f%% da vezes.", percent_20*100);
	printf("\nEm 5 de 100. Envenenado em %.4f%% da vezes.", percent_100*100);
				
	return 0;
}
