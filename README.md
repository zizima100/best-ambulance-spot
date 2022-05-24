# Instruções do projeto
O projeto principal está no arquivo chamado "best-ambulance-spot". Os demais arquivos como projeto-gauss, dijkstra e projeto-alunos são apenas exemplos de outros projetos que foram feitos em C e que podemos usar para nos basear neste.

## Flow do programa:
1. O usuário deve ter certeza de que na mesma pasta em que o projeto está sendo executado existe um arquivo chamado "matriz.txt". Nesse arquivo, a primeira linha deve conter a quantidade de linhas na matriz. Da segunda linha para frente, serão inseridos os elementos da matriz.

## Comandos úteis:
Comando para compilar o projeto:
```gcc -o run <nome-do-arquivo.c>```

Comando para executar o arquivo gerado:
```./run```

## Possível solução:
Provavelmente precisaremos rodar o algoritmo de Djikstra para cada elemento da matriz, descobrir o que tem a menor somatória das distâncias e apontar aquele nódulo/vetor como o melhor para posicionar a ambulância.

## Link de onde tirei o algoritmo de Dijkstra
[Algoritmo de Dijkstra](https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/)

# IMPORTANTE
Se você for rodar este programa no code-blocks ou no windows, você vai precisar trocar os ```system("clear")``` por ```system("cls")```.