

## RSelect (Randomized Selection)

**Quando usar:** Sempre que precisar de encontrar o $i$-ésimo menor elemento (estatística de ordem) num array não ordenado — como, por exemplo, encontrar a mediana exata de uma lista de atributos de jogadores — de forma extremamente rápida e sem o custo computacional de ordenar o array inteiro primeiro.

**O que faz:** Utiliza a lógica de partição por Divisão e Conquista herdada do QuickSort. O algoritmo escolhe um pivô aleatoriamente, posiciona-o no seu local correto na memória e, avaliando o índice final do pivô, determina se o elemento procurado está à esquerda ou à direita. A grande vantagem é que ele descarta completamente a metade que não interessa, fazendo a recursão em apenas **um** dos lados.

**A Velocidade (Prática vs Matemática):** Tempo médio espetacular de **O(N)** (linear), superando a ordenação completa seguida de indexação, que custaria O(N log N). No pior caso teórico absoluto (se escolher consecutivamente os piores pivôs possíveis), degrada para O(N²), mas a escolha aleatória do pivô blinda o algoritmo contra isso na prática, tornando o pior caso matematicamente negligenciável. O consumo de espaço é **O(1)** (in-place), operando diretamente no array original.

**Como acionar (A interface):**
```c
// Procura o 5º menor elemento (estatística de ordem 5)
int elemento = rSelect(meu_array, 0, tamanho_do_array - 1, 5);
