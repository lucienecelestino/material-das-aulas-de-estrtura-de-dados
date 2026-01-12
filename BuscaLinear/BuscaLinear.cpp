/*
	Name: BuscaLinear.cpp
	Copyright: 
	Author: Luciene Celestino
	Date: 19/11/25 9:28
	Description: Implmentação do algoritmo da Busca Sequencial ou linear
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Sessao de prototipação
void bubbleSort(int *, int);//referencia para o vetor e tambem o tamanhovetor

main()
{
	int vetor[] = {17,23,8,96,43,13,2,25,-5,29};
	int i, tamanhovetor, achou;//variavel bolean
	int elemento, comparacao;
	elemento = 0;
	achou = 0; //Assume o valor booleano falso
	
	tamanhovetor = sizeof(vetor)/sizeof(int); //tamanho do vetor
	
	puts("Conteudo do vetor: ");
	for(i=0; i<tamanhovetor; i++)
		printf("%d|", vetor[i]);
		
	printf("\n\nElemento a localizar: ");
	scanf("%d", &elemento);
	
	//LÓGICA PARA LOCALZAR UM ELEMENTO DENTRO DO VETOR
	i=0;
	while(i<tamanhovetor)
	{
		comparacao++;
		if(elemento == vetor[i])
		{
			achou = 1;
			break;
		}			
	i++;
	}
	
	if(achou == 1)
		printf("\nElemento encontrado no indice %d: ", i);
	else
		printf("\nElemento não encontrado!! ");
		
	printf("Quantidade de comparações: %d", comparacao);
}//fim do main
