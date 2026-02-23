/*
	Name: MargeSort.cpp
	Author: Luciene Celestno
	Date: 22/10/25 11:08
	Description: Implementação do método de ordenação 
				MargeSort
*/

#include <stdio.h>
#include <stdlib.h>

//Sessao de prototipação
void mergeSort(int *, int, int);//essa é a que quebra, divide o vetor em varios pedaços//vetor, Variaveis: inicio e fim
void merge(int *, int, int, int); // vetor,inicio,meio,fim

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
//	puts("PENSANDO (ORDENANDO)");
	mergeSort(vetor, 0, tamanhovetor-1); //invoke da funçaõ
	
	//Mostrando o vetor ordenado pelo mergesort
	puts("\n\nVETOR ORDENADO PELO MERGE SORT: ");
		for(i =0; i<tamanhovetor; i++){
		printf(" %d |", vetor[i]);
			
	}
}

//Funçao recursiva para quebrar todo o conjunto de dados em diversos vetores de um único elemento
void mergeSort(int *vetor, int inicio, int fim)
{	
	if(inicio < fim)
	{
		int meio = (inicio + fim)/2; //calcula o meio do conjunto do vetor, enquanto não for um unico elemento, não para de dividir
		mergeSort(vetor, inicio, meio); //Divide o lado esquerdo do vetor(conjunto)
		mergeSort(vetor, meio+1, fim); //divide o lado direito do vetor(conjunto)
		
		merge(vetor, inicio, meio, fim);// invoke, agora vai juntar 
	}
	
}

//Função que junta os sub-vetores divididos por MergeSort
void merge(int *vetor, int inicio, int meio, int fim)
{
	int i, j, k; // vai rodar nos laços de repetiçõs
	int tamEsquerdo, tamDireito;//tamanho para os vetores temporarios
	
	tamEsquerdo = meio - inicio + 1; //mostrando quantos elementos tem no vetor de cada lado
	tamDireito = fim - meio; //mostrando quantos elementos tem no vetor de cada lado
	
	//Cria os vetores auxiliares(Temporarios)
	int vetorEsquerdo[tamEsquerdo], vetorDireito[tamDireito];
	
	//Copia os dados para os vetores temporarios (tamDireito, tamEsquerdo)
	for(i=0; i < tamEsquerdo; i++)
	{
		vetorEsquerdo[i] = vetor[inicio+i];
	}
		
	for(j=0; j < tamDireito; j++)
	{
		vetorDireito[j] = vetor[meio + 1 + j];
	}
	//junta os vetores temporarios, de volta para o vetpr original(vetor)
	i = 0; // indice inicial do primeiro subvetor(lado esquerdo)
	j = 0; // indice inicial do segundo subvetor(lado direito)
	k = inicio; //indice inicial do subvetor mesclado //onde acontecerá a junção
	
	while(i < tamEsquerdo && j < tamDireito)
	{
		if(vetorEsquerdo[i] < vetorDireito[j])
		{
			vetor[k] = vetorEsquerdo[i];
			i++;
		}
		else
		{
			vetor[k] = vetorDireito[j];
			j++;
		}
		k++;
	}
	
	//Copia os elementos restantes de vetorEsquerdo se houver
	while (i < tamEsquerdo){
		vetor[k] = vetorEsquerdo[i];
		i++;
		k++;
	}
	
	//Copia os elementos restantes de vetorDireito se houver
	while (j < tamDireito){
		vetor[k] = vetorDireito[j];
		j++;
		k++;
	}
}













