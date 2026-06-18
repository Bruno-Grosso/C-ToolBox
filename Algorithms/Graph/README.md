## Busca em Largura (BFS - Breadth-First Search)

**Quando usar:** Sempre que precisar explorar um mapa expandindo a busca em formato de "ondas" concêntricas ou "camadas". É a escolha absoluta e matematicamente garantida para encontrar o **caminho mais curto em grafos não ponderados** (onde não há peso nas arestas, apenas conexões). Excelente para sistemas de recomendação ("amigos em comum") e varreduras de redes de roteadores.

**O que faz:** Partindo de um vértice de origem, o algoritmo visita todos os vizinhos imediatos (nível 1) antes de descer mais fundo no grafo (nível 2). Para manter a disciplina dessa ordem de expansão, a BFS utiliza obrigatoriamente uma **Fila (Queue)** sob o capô, garantindo que o primeiro nó descoberto seja o primeiro a ser explorado (FIFO - First In, First Out).

**A Velocidade (Prática vs Matemática):** Mantém a excelência de **O(V + E)** (Vértices + Arestas) quando operada sobre uma Lista de Adjacência. O consumo de memória RAM sofre um leve acréscimo temporal devido à necessidade de alocar a Fila para gerenciar a ordem de visitação, mas é um custo ínfimo em relação à sua eficiência brutal de busca. Cada nó é colocado na fila no máximo uma vez, garantindo ciclos de processamento estritamente essenciais.

**Como acionar (A interface):**

```c
bfs(my_map, 0); // Executa a varredura em onda a partir do vértice 0

```
-----------------------------------------------
