#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h> // Talvez não precise
#include <string.h> // Talvez não precise

int linhas, colunas;
float **matriz;

void liberarMemoriaMatriz()
{
  for (int i = 0; i < linhas; i++)
  {
    free(matriz[i]);
  }
  free(matriz);
}

void fecharPrograma()
{
  fflush(stdin);
  printf("\nPressione ENTER para encerrar o programa. . .");
  getchar();
  liberarMemoriaMatriz();
  exit(0);
}

void lerMatrizPorArquivo()
{
  FILE *arquivo = fopen("matriz.txt", "r");
  int n;

  if (arquivo == NULL)
  {
    printf("Houve um erro ao ler a matriz no arquivo.");
  }
  else
  {
    printf("\nA matriz contida no arquivo é: \n");
    fscanf(arquivo, "%d", &n);

    linhas = n;
    colunas = n + 1;
    matriz = (float **)malloc(linhas * sizeof(float *)); // Cria o vetor que guarda vetores.

    for (int i = 0; i < linhas; i++)
    {
      matriz[i] = (float *)malloc(colunas * sizeof(float)); // Cria outro vetor dentro do primeiro.
      for (int j = 0; j < colunas; j++)
      {
        fscanf(arquivo, "%f", &matriz[i][j]);
      }
    }
    fclose(arquivo);
  }
}

void imprimirMatriz()
{
  for (int linha = 0; linha < linhas; linha++)
  {
    printf("\n\t");
    for (int coluna = 0; coluna < colunas; coluna++)
    {
      printf(" %.2f ", matriz[linha][coluna]);
    }
    printf("\n");
  }
}

int main()
{
  setlocale(LC_ALL, "portuguese");
  system("clear");

  lerMatrizPorArquivo();
  imprimirMatriz();
  printf("\nPressione ENTER para calcular a melhor posição para a ambulância. . .");
  getchar();

  fecharPrograma();
}

