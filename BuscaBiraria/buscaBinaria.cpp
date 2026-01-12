/*
	Name: BuscaBinária.cpp
	Copyright: 
	Author: Luciene Celestino
	Date: 19/11/25 9:28
	Description: Implmentação do algoritmo da Busca Binária ou Logaritminca
*/

#include <stdio.h>

//Sessao de prototipação
void bubbleSort(int *, int);//referencia para o vetor e tambem o tamanhovetor

main()
{
	int vetor[] = {-5,2,8,13,17,23,23,23,23,25,29,43,96};
	
	int i, tamanhovetor, achou;//variavel bolean
	int elemento, comparacao;
	elemento = 0;
	achou = 0; //Assume o valor booleano falso
	int inicio, meio, fim;
	inicio = meio = 0;
	int esquerda, direita; 
	esquerda, direita = 0;
	
	tamanhovetor = sizeof(vetor)/sizeof(int); //tamanho do vetor
	fim = tamanhovetor -1;
	
	puts("Conteudo do vetor: ");
	for(i=0; i<tamanhovetor; i++)
		printf("%d|", vetor[i]);
		
	printf("\n\nElemento a localizar: ");
	scanf("%d", &elemento);
	
	while(inicio <= fim)
	{
		
		meio = (inicio + fim)/2;
		
		printf("O valor %d aparece nos indices: %d ", elemento, meio);
		// Varre para a esquerda
		int i = meio - 1;
		while (i >= 0 && vetor[i] == elemento) {
		    printf("%d ", i);
		    i--;
		}
		
		// Varre para a direita
		i = meio + 1;
		while (i < tamanhovetor && vetor[i] == elemento) {
		    printf("%d ", i);
		    i++;
		}
		comparacao++;
		if(vetor[meio] == elemento)
		{
			achou++; //torna verdadeiro

            // Varre para a esquerda
            int esquerda = meio;
            int direita = meio;
            while (vetor[--esquerda] == elemento)
            	printf("\nIndice Esquerda: %d", esquerda);
            printf("\nIndice meio: %d", meio);
            while(vetor[++direita] == elemento)
            	printf("\n Indice Direita: %d", direita);
            
			break;
		}
		else if(elemento < vetor[meio])
			{
				fim = meio -1;
			}
				else
				{
					inicio = meio + 1;
				}
	}
		
	if(achou == 0) //if(achou == 1)
//		printf("\nElemento encontrado no indice %d: ", meio);
	//else
		printf("\nElemento não encontrado!! ");
		
	printf("\n Quantidade de comparacoes: %d", comparacao);
	
}
	
	
