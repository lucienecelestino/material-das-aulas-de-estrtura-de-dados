/*
	Name: ListaLigada.cpp
	Author: Luciene Celestino
	Date: 20/08/25 09:52
	Description: Programa para demonstrar a implementação
				 da estru2tura de dados Lista Encadeada
*/

#include <stdio.h>
#include<stdlib.h>

//definição da estrutura de um Nó
//struct == instrução
// um unico elemento da minha lista
typedef struct No
{
//	char nome[20];
//	int idade;
	int num;
	No *proximo; //a variavel proximo é do tipo No
};


//Variavel GLOBAL
int tamanho;

//Sessão de Prototipação	
int vazia(No *);
No *alocaMemoria();
void insereFim(No *);
void insereInicio(No *);
void exibirLista(No *);
void iniciarLista (No *);


main()
{
	No *Lista = (No *) malloc(sizeof(No));//vou criar uma listra com diversos Nós
	if(!Lista)
	{
		puts("Sem memoria para criar a lista!!");
		exit(1);
	}
	else
	{
		iniciarLista(Lista);
		insereInicio(Lista);
		insereFim(Lista);
		exibirLista(Lista);
		insereInicio(Lista);
		exibirLista(Lista);	
	}
}
//Função para Começar uma LISTA
void iniciarLista (No *Lista)
{
	Lista->proximo = NULL;
	tamanho = 0;
}



//Função 	que testa se a lista está vazia
int vazia(No *Lista)
{
	if(Lista->proximo == NULL)
		return 1; // verdade, está vazia
	else
		return 0; // falso, não está vazia
}

//Função para alocação de memoria para um Nó
No *alocaMemoria()
{
	No *novo = (No *) malloc(sizeof(No)); // para saber o tamanho do Nó
	if (!novo)
	{
		
		printf("Sem memoria disponivel para criar um novo No!! \n");
		exit(1);
	}
	else{
		printf("\nNovo Elemento: ");
		scanf("%d", &novo->num); // aqui que acontece a leitura de dados
	//	scanf("%d", &novo->idade); // mostrando como funciona, aqui em novo coloca a idade
		return novo;
	}
	
}

//Insere um Nó no fim da lista
void insereFim(No *Lista)
{
	No *novo = alocaMemoria();
	novo->proximo = NULL; //como esta inserindo no fim, vai receber null como proximo
	
	if(vazia(Lista))
		Lista->proximo = novo;

	else
	{
		No *temporario = Lista->proximo;
		while (temporario->proximo != NULL)
			temporario = temporario->proximo;
			
		temporario->proximo = novo;
		
	}
	tamanho++;
	puts("Elemento inserido com Sucesso!!");
}

//Insere um Nó no INICIO da lista
void insereInicio(No *Lista)
{
	No *novo = alocaMemoria();
	No *head = Lista->proximo; //insere no primeiro
	
	Lista->proximo  = novo;
	novo->proximo = head;
	
	tamanho++;
}

//Função para EXBIR TODO O CONTEUDO DA LISTA
void exibirLista(No *Lista)
{
	system("cls"); // limpa a tela
	if(vazia(Lista) == 1) // ou seja se o retorno for 1 (vazio)
	{
		puts("Lista Vazia!!!\n\n");
		return;
	}
	else
	{
		No *temporario;
		temporario = Lista->proximo;
		printf("Lista: ");
			while(temporario != NULL)
			{
				printf("%d---->", temporario->num);
				temporario = temporario->proximo;
			}
	}
}

