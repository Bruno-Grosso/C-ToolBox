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
## Algoritmo de Dijkstra (Caminho Mais Curto)

**Quando usar:** A ferramenta definitiva para logística, rotas de GPS, roteamento de pacotes em redes de servidores e inteligência artificial para movimentação em mapas. Sempre que as arestas do seu grafo tiverem "pesos" ou "custos" (tempo, pedágio, distância, latência) e você precisar descobrir matematicamente a rota global mais barata da origem ao destino. **Atenção:** Só funciona se não houver custos negativos no mapa.

**O que faz:** Opera como um "radar guloso". Partindo da origem, ele avalia constantemente todas as cidades conhecidas e salta para a mais barata. A partir dela, ele atualiza as rotas para os vizinhos imediatos (um processo chamado de *Relaxamento*). O algoritmo nunca "pula de galho em galho" às cegas; ele varre o mapa com visão global, garantindo que não caia em armadilhas locais (becos sem saída ou rotas que começam baratas mas terminam caras).

**A Velocidade (Prática vs Matemática):** Na nossa implementação base utilizando arrays estáticos para buscar o menor valor, a complexidade é **O(V²)**, o que é excelente para grafos densos e mapas de pequeno a médio porte. (Para roteamento em escala global, a indústria substitui o array de busca por uma *Min-Heap / Fila de Prioridade*, derrubando o custo para **O((V + E) log V)**).

**Como acionar (A interface):**

```c
// Calcula e imprime a rota mais barata e a distância final do vértice 0 ao 4
dijkstra(my_map, 0, 4);
```
---
## Algoritmo de Prim (Árvore Geradora Mínima - MST)

**Quando usar:** A ferramenta definitiva para redes de infraestrutura, cabeamento de fibra ótica, malhas logísticas e design de circuitos integrados. Sempre que você tiver um grafo não-direcionado com arestas ponderadas (custos, distâncias ou preços) e precisar descobrir o conjunto exato de conexões capaz de **interligar todos os vértices do mapa gastando o mínimo absoluto de recursos**, sem criar ciclos fechados.

**O que faz:** O algoritmo parte de um vértice inicial e vai "conquistando" o grafo de forma gulosa. A cada passo, ele analisa todas as pontes (arestas) que ligam o território já dominado aos vértices vizinhos ainda não visitados e seleciona a estritamente mais barata (uma aplicação direta da *Propriedade do Corte*). Para manter essa escolha eficiente, ele utiliza um motor de Fila de Prioridade (**Min-Heap**) aliado a um array de rastreamento de índices (um "GPS" interno), garantindo que os nós sejam atualizados instantaneamente.

**A Velocidade (Prática vs Matemática):** Graças à nossa implementação avançada com Min-Heap e indexação direta, o algoritmo atinge uma complexidade ótima de **$O(m \log n)$** (onde $m$ é o número de arestas e $n$ é o número de vértices), eliminando os gargalos de busca linear $O(V^2)$ e permitindo processar redes massivas em milissegundos, mesmo lidando com pesos negativos no mapa.

**Como acionar (A interface):**

```c
// Carrega o arquivo do grafo e calcula a Árvore Geradora Mínima a partir do vértice 0
prim_mst(graph, 0);
```

