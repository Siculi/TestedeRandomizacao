#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	
	/*
		Esboço de um jogo de azar.
	*/
	
	int i, j, Num_20, Num_100[5], resp_20, resp_100, cont_20, cont_100, Total, rodadas; 
	float percent_20, percent_100;
	resp_20 = resp_100 = cont_20 = cont_100 = Total = 0;
	percent_20 = percent_100 = 0.0;	
	
	printf("\t>>> Teste a sua SORTE <<<\n\n");
		
	printf("Quantas rodadas quer tentar? ");
	scanf("%i", &rodadas);
	printf("------------------------------------------------\n");
	srand(time(NULL));
	
	do{
	j = 1;
	
	Num_20 = rand() % 20 + 1;
	
	for(i=0;i<5;i++)
	{
		Num_100[i] = rand() % 100 + 1;
		do{if(Num_100[j] == Num_100[i]){Num_100[i] = rand() % 100 + 1;j = 0;}else{j=j+1;}}while(j < i);j = 0;						
	}
		
	printf("\n\tRodada %i de %i.\n\n",Total+1, rodadas);	
	printf("Escolha um numero entre 1 e 20: "); scanf("%i", &resp_20);
	printf("Escolha um numero entre 1 e 100: "); scanf("%i", &resp_100);
	printf("------------------------------------------------");
	
	if(resp_20 == Num_20){cont_20 = cont_20 + 1;}
	
	for(i=0;i<5;i++){if(resp_100 == Num_100[i]){cont_100 = cont_100 + 1;}}
	
	Total = Total + 1; 
	
	}while(Total<rodadas);
	
	percent_20 = (float)cont_20/(float)Total;
	percent_100 = (float)cont_100/(float)Total;
	
	printf("\n\nPara 1 copo de 20. Envenenado em %.2f%% da vezes.", percent_20*100);
	printf("\nPara 5 copos de 100. Envenenado em %.2f%% da vezes.", percent_100*100);
		
	return 0;
}
