/*
	Name: 
	Copyright: 
	Author: 
	Date: 17/09/25 11:28
	Description: Implmentação do método de ordenação
	Bubble Sort - Método da Bolha
*/

#include <stdio.h>
main()
{
	int vetor[] = {17,23,8,96,43,13,2,25,-5,29};
	int tamanhovetor, i, aux, troca,comparacao;
	troca = comparacao = 0;
	
	tamanhovetor = sizeof(vetor)/sizeof(int); //tamanho do vetor
	
	puts("VETOR ORIGINAL: ");
	for(i =0; i<tamanhovetor; i++){
		printf(" %d |", vetor[i]);
	}
	
	//Lógica de ordenação do Bubble sort
	while (tamanhovetor > 0)
	{
		for(i =0; i<tamanhovetor-1; i++)
		{
			comparacao++; // para mostrar quantas vezes foi feita as comparações, ou seja quantas vezes entrou no if
			if(vetor[i] > vetor[i+1])
			{
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
				troca++;
			}
			
		}
			puts("");// mostrando como é feito a cada laço
				for(i =0; i<tamanhovetor; i++){
				printf(" %d |", vetor[i]);
				}
				
		tamanhovetor--;
	}
	
	tamanhovetor = sizeof(vetor)/sizeof(int);
	
	//Mostrando o vetor ordenado pelo bubblesort
	puts("\n\nVETOR ORDENADO PELO BUBBLE SORT: ");
		for(i =0; i<tamanhovetor; i++){
		printf(" %d |", vetor[i]);
			
	}
	printf("\n\nQuantidade de trocas: %d", troca);
	printf("\n\nQuantidade de comparacoes: %d", comparacao);
}

