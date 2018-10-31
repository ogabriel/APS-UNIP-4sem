#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int troca = 0;
int comparacoes = 0;

void sort1(int *vetor)
{
	// do sort
}
void sort2(int *vetor)
{
	// do sort
}
void sort3(int *vetor)
{
	// do sort
}
void sortall(int *vetor)
{
  sort1(vetor);
  sort2(vetor);
  sort3(vetor);
}
void preenche(int *vetor)
{
	int i;
	for (i=0; i<TAM; i++)
	{
		vetor[i]=rand()%somevalue;
		printf("%d\t", vetor[i]);
	}
}
void mostra(int *vetor)
{
	printf("\nVetor ordenado:\n");
	int i;
	for(i=0;i<TAM;i++)
	{
		printf("%d\t",vetor[i]);
	}
	printf("\nPressione enter para ver a quantidade de trocas realizadas.");
	getch();
	printf("\nNúmero de trocas: %d trocas\n", troca);
}
