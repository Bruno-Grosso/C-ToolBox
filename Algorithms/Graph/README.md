## Busca em Largura (BFS - Breadth-First Search)

**Quando usar:** Sempre que precisar explorar um mapa expandindo a busca em formato de "ondas" concêntricas ou "camadas". É a escolha absoluta e matematicamente garantida para encontrar o **caminho mais curto em grafos não ponderados** (onde não há peso nas arestas, apenas conexões). Excelente para sistemas de recomendação ("amigos em comum") e varreduras de redes de roteadores.

**O que faz:** Partindo de um vértice de origem, o algoritmo visita todos os vizinhos imediatos (nível 1) antes de descer mais fundo no grafo (nível 2). Para manter a disciplina dessa ordem de expansão, a BFS utiliza obrigatoriamente uma **Fila (Queue)** sob o capô, garantindo que o primeiro nó descoberto seja o primeiro a ser explorado (FIFO - First In, First Out).

**A Velocidade (Prática vs Matemática):** Mantém a excelência de **O(V + E)** (Vértices + Arestas) quando operada sobre uma Lista de Adjacência. O consumo de memória RAM sofre um leve acréscimo temporal devido à necessidade de alocar a Fila para gerenciar a ordem de visitação, mas é um custo ínfimo em relação à sua eficiência brutal de busca. Cada nó é colocado na fila no máximo uma vez, garantindo ciclos de processamento estritamente essenciais.

**Como acionar (A interface):**

```c
bfs(my_map, 0); // Executa a varredura em onda a partir do vértice 0

```
-----------------------------------------------
## Busca em Profundidade (DFS - Depth-First Search)

**Quando usar:** Ideal para explorar labirintos, detectar ciclos (dependências circulares), realizar ordenação topológica e como motor base para algoritmos avançados (como a descoberta de Componentes Fortemente Conexos no algoritmo de Kosaraju). Se o objetivo é varrer todas as possibilidades até o fim de um caminho antes de tentar uma alternativa, a DFS é a ferramenta correta.

**O que faz:** O algoritmo escolhe um caminho e mergulha agressivamente o mais fundo possível no grafo. Quando atinge um beco sem saída, ele executa o *backtracking* (retrocesso), voltando pelo próprio rastro até encontrar uma encruzilhada com caminhos inexplorados. Diferente da BFS que usa uma Fila (FIFO), a DFS exige uma **Pilha (LIFO - Last In, First Out)**. 

**A Velocidade (Prática vs Matemática):** Mantém a eficiência máxima de **O(V + E)** em Listas de Adjacência. A implementação recursiva é extremamente enxuta, pois delega o controle da Pilha diretamente para a *Call Stack* (Pilha de Chamadas) do processador. O único cuidado de hardware é em grafos colossalmente profundos, onde o excesso de chamadas recursivas poderia causar um *Stack Overflow*.

**Como acionar (A interface):**

```c
// Inicializa o array de visitados e dispara a recursão a partir do vértice 0
dfs(my_map, 0, num_vertex);
```
---------------------------------------------
## Algoritmo de Kosaraju (Componentes Fortemente Conexos)

**Quando usar:** Quando precisar auditar a integridade de um sistema direcional. É a ferramenta definitiva para identificar "bolhas" (grupos de nós onde qualquer um consegue alcançar qualquer outro) e para validar se um fluxo de dependências (como um *pipeline* de dados) possui ciclos circulares fatais. 

**O que faz:** O algoritmo é uma obra-prima de reaproveitamento. Ele executa três passos precisos usando as ferramentas que você já tem:
1. Roda uma DFS no grafo original, empurrando cada vértice para uma Pilha apenas quando ele termina *totalmente* de ser explorado (ordem de finalização).
2. Transpõe o grafo (inverte a direção de absolutamente todas as arestas de "mão única").
3. Roda uma nova DFS no grafo invertido, mas desta vez, a ordem de ignição é ditada pelo topo da Pilha do passo 1. Cada mergulho bem-sucedido dessa nova DFS revela um Componente Fortemente Conexo isolado.

**A Velocidade (Prática vs Matemática):** Custa o equivalente a duas rodadas de DFS, o que matematicamente continua sendo cravado em **O(V + E)**. O gasto de hardware extra vem puramente da necessidade de alocar memória para criar o "Grafo Invertido" temporário, uma troca justa pela garantia estrutural que ele entrega.

**Como acionar (A interface):**

```c
// Analisa o mapa, inverte os vetores e imprime as bolhas de conectividade
kosaraju(my_map, num_vertex);
```
--------------------------------------------
