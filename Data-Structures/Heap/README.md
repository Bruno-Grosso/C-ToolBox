# Heaps: Fila de Prioridade (Max/Min)

**Quando usar:** Sempre que precisar processar itens com base em sua importância ou urgência, e não na ordem de chegada (como em algoritmos de roteamento de rede, caminho mínimo de Dijkstra, ou agendamento de processos no sistema operacional). É a escolha definitiva para manter acesso imediato ao elemento mais prioritário do sistema sem precisar ordenar toda a base de dados.

**O que faz:** Cria uma estrutura hierárquica (uma Árvore Binária Completa) armazenada de forma linear em um array dinâmico principal. A estrutura pode ser configurada como um **Max-Heap** (onde o maior valor fica na raiz) ou um **Min-Heap** (onde o menor valor fica na raiz). Toda a navegação entre nós "pais" e "filhos" é feita puramente através de matemática de índices, sem usar ponteiros.

**A Velocidade (Prática vs Matemática):** O consumo de memória é um enxuto **O(N)**. A extração do elemento de maior prioridade e a inserção de novos elementos possuem tempo matemático rigoroso de **O(log N)**. Na execução real no *hardware*, é infinitamente superior a uma Árvore Binária com ponteiros, pois o array contíguo maximiza o uso do cache L1/L2 do processador e elimina a necessidade de *mallocs* excessivos na memória RAM.

**Como acionar (A interface):**

```c
Heap* fila = criar_heap(15);
inserir(fila, 30);
inserir(fila, 50);

int prioridade = extrair(fila); // Retorna o Mínimo ou Máximo, dependendo da configuração
