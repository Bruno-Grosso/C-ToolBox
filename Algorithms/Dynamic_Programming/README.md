## [Problema da Mochila 0/1 com Matriz Completa (Abordagem Tabular)](knapsack_backpack.c)

**Quando usar:** A ferramenta fundamental de aprendizado e referência para programação dinâmica, ideal para fins didáticos, auditoria de caminhos e problemas de tamanho moderado onde é necessário rastrear e reconstruir quais itens exatos foram escolhidos para compor a solução ótima.

**O que faz:** O algoritmo opera sob o paradigma de **Programação Dinâmica**, construindo explicitamente uma matriz bidimensional de estados de tamanho $(N + 1) \times (W + 1)$. Para cada item disponível e para cada subcapacidade possível da mochila, a arquitetura avalia matricialmente a decisão de transição: ou se preserva o valor anterior (excluindo o item) ou se soma o valor do item atual ao lucro ótimo da capacidade remanescente. O rastreamento completo em tabela permite não apenas obter o valor máximo, mas também realizar o *backtracking* para listar exatamente quais itens entraram na mochila.

**A Velocidade (Prática vs Matemática):** Na sua execução padrão utilizando alocação dinâmica em Heap, a complexidade temporal se mantém em **O(N \times W)**, onde N é o número de itens e W é a capacidade máxima. A complexidade espacial assume a forma completa **O(N \times W)**, exigindo uma alocação de memória proporcional à tabela bidimensional, o que oferece clareza absoluta de estado em troca de maior consumo de RAM comparado às versões de array único ou rolling arrays.

**Como acionar (A interface):**

```c
// Inicializa a matriz de estados e executa o núcleo tabular da mochila 0/1
int max_value = knapsack_matrix_core(knap, values, weights);
