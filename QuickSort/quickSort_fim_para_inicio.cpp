/*
	Name: QuickSort.cpp
	Author: Luciene Celestno
	Date: 05/11/25 11:08
	Description: Implementação do método de ordenação 
				QuickSort
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Sessao de prototipação
int partition(int *, int, int);// vetor, inicio,fim
void quickSort(int *, int, int); // vvetor, iniicio, tamanho -1
void swap(int *, int *);// swap é a troca
//variaveis globais
//int troca, comparacao, aux;

main()
{
	
	int vetor[] = {17,23,8,96,43,13,2,25,-5,29};
	int tamanhovetor, i;
	tamanhovetor = sizeof(vetor)/sizeof(int); //tamanho do vetor

	puts("VETOR ORIGINAL: ");
	for(i =0; i<tamanhovetor; i++){
		printf(" %d |", vetor[i]);
	}
	
	puts("\nPENSANDO (ORDENANDO)");
//	inicio = clock();
	quickSort(vetor, 0, tamanhovetor-1); //invoke da funçaõ
//	fim = clock();
	
//	tempo_decorrido = ((double)fim - inicio) / CLOCKS_PER_SEC;
//	printf("n\n\===> Tempo decorrido: %f", tempo_decorrido);

		//Mostrando o vetor ordenado pelo mergesort
	puts("\n\nVETOR ORDENADO PELO quickSort: ");
		for(i =0; i<tamanhovetor; i++){
		printf(" %d |", vetor[i]);
			
	}
	
	
}//fim do programa

//Funçaõ que realiza as particções do conjunto de dados(vetor)
int partition(int vetor[], int inicio, int fim)
{
	int pivot = vetor[fim];
	int i = (inicio-1);//indice do menor elemento
	
	for (int j = inicio; j <= fim-1; j++)
	{
		if(vetor[j] <= pivot)
		{
			i++;
			swap(&vetor[i],&vetor[j]);// passando apenas um elemento do vetor usa-se "&"
		}
	}
	swap(&vetor[i+1], &vetor[fim]);//trocando o elemento do fim pelo pivo
	return (i+1);
}

// Função que realiza o swap (troca de posições)
void swap(int *a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
	
}

void quickSort(int vetor[], int inicio, int fim)
{
	if(inicio < fim)
	{
		int pivot = partition(vetor, inicio,fim);// vai retornar o indice do pivo
		quickSort(vetor, inicio, pivot-1); // para a partiçaõ do lado esquerdo
		quickSort(vetor, pivot+1, fim); // para a partiçaõ do lado direito
	}
}  
