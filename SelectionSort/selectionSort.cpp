/*
	Name: SectionSort
	Copyright: 
	Author: luciene
	Date: 24/09/25 10:36
	Description: Implementação do método de ordenação SElection Sort (ordenação por seleção)
*/

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

//Sessao de prototipação
void selectionSort(int *, int);//referencia para o vetor e tambem o tamanhovetor
//variaveis globais
int troca, comparacao;

main(){
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
		selectionSort(vetor, tamanhovetor);
		puts("\n\nVETOR ORDENADO PELO SELECTION SORT: ");
		for(i =0; i<tamanhovetor; i++){
		printf(" %d |", vetor[i]);
	}
	printf("\n\nQuantidade de trocas: %d", troca);
	printf("\n\nQuantidade de comparacoes: %d", comparacao);
}

//Função com o Algorimo do Selection Sort
void selectionSort(int *vetor, int tamanhovetor){
	int i, j, menor, aux, chave;
	
	//Laço externo que itera do inicio ao fim do array(vetor)
	for(i=0; i < tamanhovetor-1; i++)
	{
		//Assume que o menor elemento entá na primeira posição
		menor = i;
		//laço interno para buscar o menor elemento no subconjunto
		for(j = i + 1; j<tamanhovetor; j++)
		{
			comparacao++;
			if(vetor[j] < vetor[menor])
				menor = j; //guarda o indice do menor elemento encontrado no subconjunto
		} //loop interno AGE PARA ANALISAR O "SUBCONJUNTO"
		
		// troca o menor elemento encontrado com o elemento
		// da posição inicial( variavel chave)
		
		if(menor != chave)
		{
			aux = vetor[i];
			vetor[i] = vetor[menor];
			vetor[menor] = aux;
			troca++;
		}
		
		
	} //loop externo
	

}
