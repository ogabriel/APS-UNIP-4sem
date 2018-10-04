#include "sorting.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h> //Talvez deletar
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void decisao(int *vetor)
{
	int opcao;
	bool sair = false;
	while (sair == false)
	{
		printf("\nOpções: ");
		printf("\n1 - Ordenar o método com todos os algoritmos;  2 - Escolher um algoritmo específico;  3 - Sair \n");
		scanf("%d", &opcao);
		switch (opcao)
		{
   		case 1:
   		//método que usa os três sorts, retorna o tempo de ordenção e compara o tempo de cada um.
      sortall(vetor);
   		break;

   		case 2:
   		//entra em um novo switch case, que escolhe entre os três algoritmos de sort
      int opcao_interna, tempo;
      bool voltar = false;
      while (escolha_interna == false)
      {
        printf("\n Opções de sort: ");
        printf("\n1 - XSort;  2 - YSort;  3 - ZSort;  4 - Voltar \n");
        scanf("%d", &opcao_interna);
        switch (opcao_interna)
        {
          case 1:
          tempo = gettime;
          sort1(vetor);
          tempo = gettime - tempo;
          escolha_interna = true;
          break;

          case 2:
          tempo = gettime;
          sort2(vetor);
          tempo = gettime - tempo;
          escolha_interna = true;
          break;

          case 3:
          tempo = gettime;
          sort3(vetor);
          tempo = gettime - tempo;
          escolha_interna = true;
          break;

          case 4:
          //sai do switch interno fazer nada
          escolha_interna = true;
          break;

          default:
          printf("Escolha inválida!\n");
      		escolha_interna = false;
        }
      }
			escolha = true;
   		break;

   		case 3:
   		//encerra a aplicação
			escolha = true;
    	break;

    	default:
    		printf("Escolha inválida!\n");
    		escolha = false;
		}
	}
	system("pause");
}


int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
  bool executar_programa = true;
  do {
    printf("Insira o tamanho do vetor a ser gerado: ");
    scanf("%d", &tamanho);
  	int vetor[tamanho];
  	printf("Vetor com %d números. Pressione enter para gerar os valores.\n", tamanho);
  	system("pause");
  	preenche(vetor);
    printf("Vetor gerado, esse vetor será usado em todos e qualquer algoritmo de ordenação");
  	decisao(vetor);
  	mostra(vetor); //Apagar depois talvez
  	system("pause");
    int opcao_programa;
    printf("\n1 - Recomeçar o processo gerando um novo vetor; 2 - Sair?")
    scanf("%d", &opcao_programa);
    switch (opcao_programa)
    {
      case 1:
      executar_programa = true;
      break;

      case 2:
      executar_programa = false;
      break;

      default:
      printf("Escolha inválida!\n");
      executar_programa = false;
    }
  } while(executar_programa == true);

	return 0;
}
