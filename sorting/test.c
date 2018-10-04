#include "sorting.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h> //Talvez deletar
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void programa()
{
	char recomecar;
  bool sair = false;
  while (sair == false)
  {
		printf("\n*** Programa de algoritmos de ordenação ***\n");
		printf("Insira o tamanho do vetor a ser gerado: ");
		int tamanho;
    scanf("%d", &tamanho);
  	int vetor[tamanho];
  	printf("Vetor com %d números. Pressione enter para gerar os valores.\n", tamanho);
  	system("pause");
  	preenche(vetor);
    printf("Vetor gerado, esse vetor será usado em todo e qualquer algoritmo de ordenação");
		bool loop = true;
		while (loop == true)
		{
			int opcao;
			printf("\nOpções: ");
			printf("\n1 - Ordenar o método com todos os algoritmos;  2 - Escolher um algoritmo individualmente \n");
    	scanf("%d", &opcao);
      switch (opcao)
        {
          case 1:
          sortall(vetor);
          loop = false;
          break;

          case 2:
          bool voltar = true;
          do {
						int opcao_interna;
						printf("\n Opções de sort: ");
		        printf("\n1 - XSort;  2 - YSort;  3 - ZSort;  4 - Voltar \n");
            scanf("%d", &opcao_interna);
              switch (opcao_interna)
              {
                case 1:
								tempo = gettime;
			          sort1(vetor);
			          printf("%dns", gettime - tempo); //tempo = gettime - tempo;
                loop = false;
                break;

                case 2:
								tempo = gettime;
			          sort2(vetor);
			          printf("%dns", gettime - tempo);
                loop = false;
                break;

                case 3:
								tempo = gettime;
			          sort3(vetor);
			          printf("%dns", gettime - tempo);
                loop = false;
                break;

                case 4:
                break;

                default:
                printf("Escolha inválida.");
								voltar = false;
								break;
              }
          	} while (back == false);
						break;

            default:
            printf("Escolha inválida.\n");
						break;
          }
    }
    bool loop_externo = true;
    while (loop_externo == true)
    {
    	printf("Deseja recomeçar gerando um novo vetor? Y/N\n");
    	scanf("%c", &recomecar);
    	switch (recomecar)
    	{
      	case 'Y': case 'y':
      	break;

      	case 'N': case 'n':
      	quit = true;
      	break;

      	default:
      	printf("Invalid choice.");
      	outer_loop = true;
      	break;
    	}
		}
  }
  printf("\nPrograma encerrado.");
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
  programa();

	return 0;
}
