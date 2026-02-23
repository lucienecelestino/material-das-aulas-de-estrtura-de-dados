/*
	Name: HeapSort.cpp
	Author: Luciene Celestino
	Date: 29/10/25 11:26
	Description: Implementação do método de ordenação 
				HeapSort - ORDENAÇÃO POR ARVORE
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Sessao de prototipação

void heapfy(int *, int, int, int); // vetor,tamanho,primeiro elemento -- Verifica qual o elemento é maior
void heapSort(int *, int); // recebe o vetor e a quantidade de elementos -- testa se os filhos é maior que pai MIN, també pode fazer o MAX
void swap(int *, int *);// swap é a troca
void imprimir(int *);

//variaveis globais
//int troca, comparacao, aux;
int tamanho;
main(){
	
	int vetor[] = {17,23,8,96,43,13,2,25,-5,29};
	int tamanhovetor, i;
	tamanhovetor = sizeof(vetor)/sizeof(int); //tamanho do vetor

	puts("VETOR ORIGINAL: ");
	for(i =0; i<tamanhovetor; i++){
		printf(" %d |", vetor[i]);
		
		//imprimir(vetor);
	}
		
	
//	puts("PENSANDO (ORDENANDO)");
	// = clock();
	heapSort(vetor, tamanhovetor); //invoke da funçaõ
	puts("\n\nVETOR ORDENADO PELO HEAP SORT: ");
		for(i =0; i<tamanhovetor; i++){
		printf(" %d |", vetor[i]);
}
}

void imprimir(int vetor)
{
	for(int i = 0; i<tamanho; i++)
//	printf("%d |", vetor[i]);
	puts("");

}

// Função que realiza o swap (troca de posições)
void swap(int *a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
	
}

// Função que testa se o pai é maior que os filhos (MAX HEAP) ou se o pai é menor que o filho (MIN HEAP) e faz a invocação do "swap" para fazer a troca
void heapfy(int vetor[], int tamanhovetor, int i) // o i é o elemento que está no topo
{
	int maior = i;  //inicializa o maior como raiz ou seja o pai, nesse primeiro momento
	int filhoEsquerda = 2 * i + 1; // indice do filho da Esquerda
	int filhoDireita = 2 * i + 2;  //// indice do filho da Direita
	
	//testar se o filho da esquerda é miaor que o pai
	if(filhoEsquerda < tamanhovetor && vetor[filhoEsquerda] > vetor[maior])
		maior = filhoEsquerda; // se sim, maior vai receber o indice do filho da esquerda
		
	//testar se o filho da direita é maior que o maior até agora, ou seja se o novo "maior" é maior que o pai, que era o antigo "maior"
    if(filhoDireita < tamanhovetor && vetor[filhoDireita] > vetor[maior])
    	maior = filhoDireita;
    	
    if(maior != i) // ou seja se o indice de maior, for diferente do que ele comecou (zero), é por que precisa fazer a troca
	{
		swap(&vetor[i], &vetor[maior]);
		//invoca recursivamente heapfy na sub arvore afetada
		heapfy(vetor, tamanhovetor, maior);
	}
}

//Função pricipal que monta a arvore e submete a função recursiva heapfy, para verificar as regras de Max Heap ou Min Heap
void heapSort(int vetor[], int tamanhovetor)
{
	//1. Constroi o MAX HEAP
	for(int i = tamanhovetor/2 -1; i >= 0; i--)
	{
		heapfy(vetor, tamanhovetor, i); //vai montando a arvore e vai fazendo o heapfy
	}
	//2. Troca a raiz com o último elemento e reduz a arvore (heap)
	for (int i = tamanhovetor-1; i > 0; i--)
	{
		//Move o elemento atual que é o maioe pra o fim doo vetor, para restaurar a propriedade
		swap (&vetor[0], &vetor[i]);
		heapfy(vetor, i, 0);
	}
	
}
