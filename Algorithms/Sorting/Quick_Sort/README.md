# Quick Sort (In-Place com Mediana de Três)

**Quando usar:** Sempre que precisar da ordenação mais rápida possível diretamente no processador para arrays gigantes e **não tiver memória extra** disponível (sistemas com pouca RAM).

**O que faz:** Elege um "Pivô" (utilizando a mediana de 3 para evitar a lentidão de O(N²) em arrays já ordenados) e faz uma varredura cruzada a mover os menores para a esquerda e os maiores para a direita, usando apenas trocas de endereço na memória (`swap`).

**A Velocidade (Prática vs Matemática):** Excecionalmente rápido no cronómetro. Embora teoricamente partilhe o tempo médio de **O(N log N)** com o Merge Sort, o Quick Sort domina na prática. Como os seus ponteiros caminham linearmente pela memória, o processador consegue prever os movimentos e carregar os dados para a memória ultrarrápida (**Cache L1**). Tem um processamento contínuo sem perdas de tempo com alocações dinâmicas.

**Como acionar (A interface):** 
```c
quickSort(meu_array, 0, tamanho_do_array - 1);
```
----------------------------------------------------------------------------------------------------------------------------

## RSelect (Randomized Selection)

**Quando usar:** Sempre que precisar de encontrar o $i$-ésimo menor elemento (estatística de ordem) num array não ordenado — como, por exemplo, encontrar a mediana exata de uma lista de atributos de jogadores — de forma extremamente rápida e sem o custo computacional de ordenar o array inteiro primeiro.

**O que faz:** Utiliza a lógica de partição por Divisão e Conquista herdada do QuickSort. O algoritmo escolhe um pivô aleatoriamente, posiciona-o no seu local correto na memória e, avaliando o índice final do pivô, determina se o elemento procurado está à esquerda ou à direita. A grande vantagem é que ele descarta completamente a metade que não interessa, fazendo a recursão em apenas **um** dos lados.

**A Velocidade (Prática vs Matemática):** Tempo médio espetacular de **O(N)** (linear), superando a ordenação completa seguida de indexação, que custaria O(N log N). No pior caso teórico absoluto (se escolher consecutivamente os piores pivôs possíveis), degrada para O(N²), mas a escolha aleatória do pivô blinda o algoritmo contra isso na prática, tornando o pior caso matematicamente negligenciável. O consumo de espaço é **O(1)** (in-place), operando diretamente no array original.

**Como acionar (A interface):**
```c
// Procura o 5º menor elemento (estatística de ordem 5)
int elemento = rSelect(meu_array, 0, tamanho_do_array - 1, 5);
