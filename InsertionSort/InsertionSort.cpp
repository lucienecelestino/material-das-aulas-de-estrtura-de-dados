/*
	Name: InsertionSort.cpp
	Author: Luciene Celestino
	Date: 01/10/25 11:11
	Description: Implementação do método de 
				ordenação Insertion Sort
*/
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int troca, comparacao;

//Sessao de prototipação
void InsertionSort(int *, int); //um para vetor e outro para tamanho

main()
{
	//int vetor[] = {17,23,8,96,43,13,2,25,-5,29};
	int vetor[500000];
	int tamanhovetor, i;
	troca = comparacao = 0;
	
	tamanhovetor = sizeof(vetor)/sizeof(int); //tamanho do vetor
	srand(time(NULL));  //planta a semente aleatória de acordo com o tempo
	for(i =0; i<tamanhovetor; i++)
		vetor[i] = rand()%100000;
	

	puts("VETOR ORIGINAL: ");
	for(i =0; i<tamanhovetor; i++){
		printf(" %d |", vetor[i]);
	}
	InsertionSort(vetor, tamanhovetor);
		
	puts("\n\nVETOR ORDENADO PELO INSERT SORT: ");
	for(i =0; i<tamanhovetor; i++){
		printf(" %d |", vetor[i]);
	}
	printf("\n\nQuantidade de trocas: %d", troca);
	printf("\n\nQuantidade de comparacoes: %d", comparacao);


}//fim do programa

//função para o algoritmo do InsertSort
void InsertionSort(int *vetor, int tamanhovetor)
{
	//faremos o calculo de quanto tempo o sistema demora para ordenar
	clock_t inicio, fim;
    double tempo_decorrido;
	
	//captura o tempo inicial
	inicio = clock();
	
	int i,j, chave;
	// esse primeiro laçõ é para começar a partir do segundo elemento, e ir até o final, indo da esquerda para a direita
	for(i=1; i < tamanhovetor; i++)
	{
	//aqui estamos guardando a chave
		chave = vetor[i];
		
		//isso aqui faz a comparação da direita para a esquerda, e compara os elementos
		j = i-1;
		comparacao++;
		while(j >= 0 && chave < vetor[j])
		{
			comparacao++;
			//vai fazer a copia do elemento que são menores para o proximo indice
			vetor[j+1] = vetor[j];
			troca++;
			j--;		
		}
		//troca++;// quando coloca o elemento da chave no devido lugar
		vetor[j+1] = chave;
	}
	fim = clock();
	tempo_decorrido = ((double)fim - inicio) / CLOCKS_PER_SEC;
	printf("n\n\===> Tempo decorrido: %f", tempo_decorrido);
}//fim da função
