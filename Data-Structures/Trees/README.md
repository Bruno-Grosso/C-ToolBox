# BST: Árvore Binária de Busca (*Binary Search Tree*)

**Quando usar:** Sempre que precisar de um sistema altamente dinâmico onde os dados precisam ser frequentemente inseridos, removidos, mas ainda assim mantidos perfeitamente ordenados. É a estrutura ideal para buscas em bancos de dados relacionais leves ou para resolver consultas de intervalos (ex: "me dê todos os clientes com idade entre 20 e 30 anos").

**O que faz:** Modela fisicamente na memória RAM uma estrutura de hierarquia baseada em ponteiros. A regra de ouro da arquitetura dita que, para qualquer nó existente, todos os nós no galho da esquerda devem ser estritamente menores, e todos os nós no galho da direita devem ser estritamente maiores. Isso permite a leitura ordenada instantânea usando o método *In-Order Traversal*.

**A Velocidade (Prática vs Matemática):** Em um cenário saudável, onde a árvore cresce de forma espalhada, a inserção, busca e remoção operam em tempo letal de $\mathcal{O}(\log N)$, pois metade das possibilidades são descartadas a cada pulo. 

No entanto, possui uma vulnerabilidade clássica: no pior caso (ex: inserir dados que já estão ordenados, como $1, 2, 3, 4$), a árvore degenera em uma Lista Encadeada comum, despencando a performance para $\mathcal{O}(N)$ e gastando ciclos desnecessários navegando por ponteiros.

**Como acionar (A interface):**

```c
Node* raiz = NULL;
raiz = inserir(raiz, 50);
raiz = inserir(raiz, 30);
raiz = inserir(raiz, 70);

Node* resultado = buscar(raiz, 30); // Retorna instantaneamente o ponteiro para o nó 30

raiz = remover(raiz, 50); // Apaga a raiz e reestrutura os ponteiros sem quebrar a árvore
```
----

# RBT: Árvore Rubro-Negra (*Red-Black Tree*)

**Quando usar:** É o padrão ouro absoluto da engenharia de software quando você precisa de uma Árvore de Busca que sofrerá um fluxo constante, agressivo e imprevisível de inserções e remoções. É a estrutura exata usada por baixo dos panos pelo escalonador de processos do Kernel do Linux (*Completely Fair Scheduler*) e na biblioteca padrão do C++ (`std::map`). 

**O que faz:** É uma evolução direta da BST comum. Ela adiciona um metadado (um bit representando a cor Vermelha ou Preta) em cada nó da `struct` na memória RAM. Através de um conjunto estrito de regras matemáticas e um motor de "Rotação de Ponteiros", a RBT se reestrutura automaticamente (girando galhos inteiros para a direita ou esquerda) para garantir que a árvore nunca fique "torta" (desbalanceada). A regra vital é: o caminho mais longo da raiz até uma folha nunca será mais do que o dobro do caminho mais curto.

**A Velocidade (Prática vs Matemática):** Diferente da BST genérica que pode colapsar em O(N), a RBT é blindada algoritmicamente contra piores casos. Inserção, busca e remoção são engessadas em um rigoroso **O(log N)** em qualquer cenário. O custo dessa garantia é um leve overhead de ciclos de processador devido à checagem de cores e trocas de ponteiros a cada inserção, o que a torna um pouco mais lenta do que a BST apenas em cenários onde os dados já entram aleatoriamente balanceados.

**Como acionar (A interface):**

```c
// Como as rotações podem mudar quem é a raiz, passamos o ponteiro por referência (&)
Node* raiz = NULL;

inserir_rbt(&raiz, 10);
inserir_rbt(&raiz, 20);
inserir_rbt(&raiz, 30); // Aciona uma rotação automática para balancear a árvore!
