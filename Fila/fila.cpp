/*
	Name: Fila.cpp
	Author: Luciene Celestino
	Date: 03/09/25 09:52
	Description: Programa para demonstrar a implementação
				 da estru2tura de dados Fila do tipo FIFO
*/

#include <stdio.h>
#include <stdlib.h>

int items[5]; //vetor, que será utilizado para fazer uma fila
int inicio = -1, fim= -1; // como estou criando fora do vetor, estou criando com um indice que não existe
int tamanho = 5; //tamanho do vetor

// prototipação da Funções
void enQueue(int); //Insere um elemento na Fila - vai enfilerar
int deQueue(); //Retira um elemento da FIla - desinfelera
int isFull(); //testa se a fila está cheia
int isEmpty(); //testa se a fila está vazia
void exibirFila();

main()
{
	int numero;
	int opcao;
	do{
	
	puts("escolha uma opcao");
	printf("1 - Inserir um elemento na FILA\n");
	printf("2 - Excluir um elemento da FILA\n");
	printf("3 - Exibir a FILA\n");
	printf("4 - Sair\n");
	
	printf("Opcao: ");
	scanf("%d", &opcao);
	
	switch (opcao)
	{
		case 1:
	
			printf("Digite um Numero: ");
			scanf("%d", &numero);
			enQueue(numero);
			break;
			
		case 2:
			deQueue();
			break;
		case 3:
			exibirFila();
			break;

		case 4:
			exit(0);
			
		default:
			puts("Opção invalida - Verifique!!");
			break;
			
	}//fim do swtch;
	}while(opcao);
}//fim do programa
	


//Função para inserir um novo elemento na FILA
void enQueue(int elemento){
	if(isFull() == 1)
		puts("\nA fila esta CHEIA!!!");
	else
	{
	//inserindo um elemento
		if(inicio  == -1)
			inicio = 0; //ou inicio++
	fim = (fim+1)%tamanho;
	items[fim] = elemento;
	printf("\nElemento %d inserido na FIFO", elemento);
	}
}

//Função para retirar um elemento da fila
int deQueue()
{
	int elemento;
	if(isEmpty() == 1)
	{
		puts("\nA Fila esta Vazia!!!");
		return -1;
	}
	else
	{
		elemento = items[inicio]; //vai tirar um elemento do inicio
		if(inicio == fim)
		{
			inicio = -1;
			fim = -1;
		}
		else
		{
			inicio = (inicio+1)%tamanho;
		}
		printf("\n %d foi retirado da Fila",elemento);
		return elemento;
	}
}
//Função que testa se a fila está cheia
int isFull(){
	if((inicio  == (fim + 1)% tamanho) || (inicio  == 0 && fim == tamanho-1))
		return 1;
	else
		return 0;
}
//Função que testa se a fila está VAzia
int isEmpty(){
	if(inicio  == -1)
		return 1; // está vazia
	else
		return 0; //não está vazia
}
//Função que exibe
void exibirFila()
{
	int i;
	if(isEmpty() == 1)
		puts("\n A Fila esta vazia");
		
	else
	{
		puts("\n\n Conteudo da FIla");
		for(i = inicio; i != fim; i = (i+1)%tamanho)
		{
		printf("%d|", items[i]);
        }
        printf("%d", items[i]);
	}
}
