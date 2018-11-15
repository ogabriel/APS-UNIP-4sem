#include "./header_files/sorts.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

void unip_header();
void first_menu();

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");
	unip_header();
	first_menu();

	return 0;
}

void unip_header(){
	printf("\n _   _  _   _  _  ____\n| | | || \\ | ||	||    |\n| |_| ||  \\| || ||  __|\n|_____||_|\\__||_||_|");
	printf("\nCIÊNCIA DA COMPUTAÇÃO\nAPS 2018 - 4ºSEMESTRE\n ");
}

void first_menu()
{
	char recomecar;
	bool sair = false;
	while (sair == false)
	{
		printf("\n*** Programa de algoritmos de ordenação ***\n");
		printf("Insira o tamanho do vetor a ser gerado: ");
		int tamanho = 0;
		scanf("%d", &tamanho);
		int vetor[tamanho];
		printf("Vetor com %d números. Pressione enter para gerar os valores.\n", tamanho);
		system("pause>null");
		preenche(vetor, tamanho);
		printf("\nVetor gerado, esse vetor será usado em todo e qualquer algoritmo de ordenação até o fim desta execução.");
		bool loop = true;
		while (loop == true)
		{
			int opcao;
			printf("\nOpções: ");
			printf("\n1 - Ordenar o método com todos os algoritmos\n2 - Escolher um algoritmo individualmente \n");
			scanf("%d", &opcao);
			switch (opcao)
			{
				case 1:
					sortall(vetor, tamanho);
					loop = false;
					break;

				case 2:
				{
					bool voltar = true;
					do
					{
						int opcao_interna;
						printf("\n Opções de sort: ");
						printf("\n1 - Bubblesort \n2 - Mergesort \n3 - Quicksort \n4 - Voltar \n");
						scanf("%d", &opcao_interna);
						switch (opcao_interna)
						{
						case 1:
							bubble_result(vetor, tamanho);
							loop = false;
							break;

						case 2:
							merge_result(vetor, tamanho);
							loop = false;
							break;

						case 3:
							quick_result(vetor, tamanho);
							loop = false;
							break;

						case 4:
							break;

						default:
							printf("Escolha inválida.\n");
							voltar = false;
							break;
						}
					} while (voltar == false);
					break;
				}
				default:
					printf("Escolha inválida.\n");
					break;
				}
			}
			bool loop_externo = true;
			while (loop_externo == true)
			{
				printf("Deseja recomeçar gerando um novo vetor? S/N\n");
				scanf("%s", &recomecar);
				switch (recomecar)
				{
					case 'S':
					case 's':
						system("cls");
						loop_externo = false;
						break;

					case 'N':
					case 'n':
						sair = true;
						break;

					default:
						printf("Escolha inválida.\n");
						loop_externo = true;
						break;
				}
			}
		}
	printf("\n***Programa encerrado***.");
	void unip_header();
}
