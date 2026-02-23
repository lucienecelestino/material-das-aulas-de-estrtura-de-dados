/*
	Name: Pilha.cpp
	Author: Luciene Celestino
	Date: 10/09/25 10:53
	Description: Criar um programa que faz a implementação de uma PILHA (LIFO)
*/

//Sessão de Importação
#include <stdio.h>
#include <stdlib.h>

//Sessão de Prototipação
void push (int); //Função que insere um elemento na pilha
int pop(); //Função que retira um elemento na pilha
int isFull(); //Função que testa se a pilha está cheia
int isEmpty(); //Função que testa se a pilha está vazia
void exibirPilha(); //Mostra todo o conteúdo da Pilha
void menu(); //exibe um menu para o usuario;
//variaveis Globais
int topo = -1;
int pilha[5];

main()
{
	

	while(1)//Enquanto for verdadde faça
	{
		menu();
		system("pause");
	}
}//fim do programa

//Menu
void menu()
{

	system("cls");
	int opcao = 0;
	puts("Menu de Opcoes");
	puts("==============");
	puts("1 - Inserir um Elemento na Pilha");
	puts("2 - Retirar um Elemento na Pilha");
	puts("3 - Exibir a Pilha");
	puts("4 - Sair");
	puts("\n==============");
	printf("Escolha a sua opcao: \n");
	scanf("%d" ,&opcao);
	int elemento = 0; //elemento que vai ser digitado, depois de escolher uma opção
	switch(opcao)
	{
		case 1:
		
			printf("Digite o elemento a inserir na pilha: ");
			scanf("%d", &elemento);
			push(elemento);
			break;
		case 2:
			pop();
			break;
		case 3:
			exibirPilha();
			break;
		case 4:
			exit(0);
			
		default:
		puts("Opcao invalida");
	}
	
}

//Função que insere um elemento na pilha
void push (int elemento)
{
	if(isFull() == 1)
	{
		puts("\nStack OverFlow  -  Pilha Cheia");
	}
	else
	{
		topo++; // vai adicionar o elemento e ja subir o topo mais 1
		pilha[topo] = elemento;
		printf("\nElemento %d inserido na pilha \n", elemento);
	}
}

//Função que retira um elemento na pilha
int pop()
{
	if(isEmpty() == 1)
	{
		puts("\n Pilha Vazia!!\n");		
	}	
	else
	{
		int elemento; //mostra que elemento foi retirado
		elemento = pilha[topo];
		topo--;
		printf("\n%d foi retirado da pilha\n", elemento);
		return elemento;
		
		//return pilha[topo--];  esse comando substitui todas as linhas anteriores
	}
}

//Função que testa se a pilha está cheia
int isFull()
{
	if(topo == 4)	
	{
		return 1; // pilha cheia
	}
	else
		return 0;
}

//Função que testa se a pilha está vazia
int isEmpty()
{
	if(topo == -1)
	{
		return 1; // quer dizer que não tem elemento
	}
	else
		return 0; // quer dizer que ainda tem elemento
}

//Mostra todo o conteúdo da Pilha
void exibirPilha()
{
	int i;
	
	if(isEmpty() == 1)
	{
		puts("\n Pilha Vazia!!");
	}
	else
	{
		puts("\n Os elementos da pilha são: ");
		for(i = topo ; i > -1; i--){
			puts("____");
			printf("|%d| \n", pilha[i]);
			puts("____");
		}
	}
}
