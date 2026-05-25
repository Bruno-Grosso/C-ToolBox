## Grafos: Lista de Adjacências

**Quando usar:** Sempre que precisar modelar redes (rotas viárias, conexões de computadores, dependências lógicas) onde o número de conexões reais é muito menor que o limite máximo possível (os chamados *grafos esparsos*). É a escolha definitiva para manter a eficiência e não estourar a memória RAM.

**O que faz:** Cria um array dinâmico principal onde cada índice representa um Vértice (ID). Dentro de cada índice, o grafo gerencia um ponteiro para uma Lista Ligada que armazena apenas os vizinhos diretos (as arestas) daquele vértice.

**A Velocidade (Prática vs Matemática):** O consumo de memória é um enxuto **O(V + E)** (Vértices + Arestas). A inserção de uma nova conexão tem o tempo matemático rigoroso e blindado de **O(1)**, pois o nó é empurrado diretamente para a cabeça da lista ligada. Na execução real no *hardware*, é infinitamente superior a uma Matriz de Adjacência para varreduras (como num BFS ou DFS), pois o processador itera apenas sobre as conexões que realmente existem, sem perder ciclos de *clock* lendo espaços vazios na memória.

**Como acionar (A interface):**
```c
Graph* my_map = createGraph(5); 
addEdge(my_map, 0, 3);
