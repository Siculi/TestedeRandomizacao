#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	
	/*
		Algoritmo de não repetição de valores aleatorios isolado.
	*/
	
	
	int i, j, Num_20, Num_100[5]; j = 1; srand(time(NULL));
	
	for(i=0;i<5;i++)
	{
		Num_100[i] = rand() % 5 + 1;
		/*
			Nota: Se valores menores que 5 forem usados esse problama é não computavel. 
			Uma vez que apenas 4 numeros não preenchem 5 vagas.
		*/ 
		printf("Primeira tentativa: %i - ", Num_100[i]);
				
		do{
			if(Num_100[j] == Num_100[i])
			{
				Num_100[i] = rand() % 5 + 1; printf("%i, ", Num_100[i]);
				j = 0;
			}else{j=j+1;}			
		}while(j < i);
		
		printf("\n");
		j = 0;						
	}

	printf("\n5 de 5: ", Num_20); //Não pode haver numeros repetidos aqui.
	for(i=0;i<5;i++)
	{
		printf("%i, ", Num_100[i]);		
	}
	
	return 0;
}
