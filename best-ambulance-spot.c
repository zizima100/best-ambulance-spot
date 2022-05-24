#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>
#include <stdbool.h>

int V;
int **matriz;
int *somatorias;

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[])
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a matriz represented using adjacency matrix representation
void dijkstra(int src)
{
	int dist[V]; // The output array. dist[i] will hold the shortest
	// distance from src to i

	bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
	// path tree or shortest distance from src to i is finalized

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in the first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet, there is an edge from
			// u to v, and total weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && matriz[u][v] && dist[u] != INT_MAX
				&& dist[u] + matriz[u][v] < dist[v])
				dist[v] = dist[u] + matriz[u][v];
	}

	// print the constructed distance array
	printSolution(dist);
}

void liberarMemoriaMatriz()
{
  for (int i = 0; i < V; i++)
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

    V = n;
    matriz = (int **)malloc(V * sizeof(int *)); // Cria o vetor que guarda vetores.

    for (int i = 0; i < V; i++)
    {
      matriz[i] = (int *)malloc(V * sizeof(int)); // Cria outro vetor dentro do primeiro.
      for (int j = 0; j < V; j++)
      {
        fscanf(arquivo, "%d", &matriz[i][j]);
      }
    }
    fclose(arquivo);
  }
}

void imprimirMatriz()
{
  for (int linha = 0; linha < V; linha++)
  {
    printf("\n\t");
    for (int coluna = 0; coluna < V; coluna++)
    {
      printf(" %d ", matriz[linha][coluna]);
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
  system("clear");

  for (int vertice = 0; vertice < V; vertice++)
  {
    dijkstra(vertice);
    printf("\n--------\n");
  }

  fecharPrograma();
}

