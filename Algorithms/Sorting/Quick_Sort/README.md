# Quick Sort (In-Place com Mediana de Três)

**Quando usar:** Sempre que precisar da ordenação mais rápida possível diretamente no processador para arrays gigantes e **não tiver memória extra** disponível (sistemas com pouca RAM).

**O que faz:** Elege um "Pivô" (utilizando a mediana de 3 para evitar a lentidão de O(N²) em arrays já ordenados) e faz uma varredura cruzada a mover os menores para a esquerda e os maiores para a direita, usando apenas trocas de endereço na memória (`swap`).

**A Velocidade (Prática vs Matemática):** Excecionalmente rápido no cronómetro. Embora teoricamente partilhe o tempo médio de **O(N log N)** com o Merge Sort, o Quick Sort domina na prática. Como os seus ponteiros caminham linearmente pela memória, o processador consegue prever os movimentos e carregar os dados para a memória ultrarrápida (**Cache L1**). Tem um processamento contínuo sem perdas de tempo com alocações dinâmicas.

**Como acionar (A interface):** 
```c
quickSort(meu_array, 0, tamanho_do_array - 1);

----------------------------------------------------------------------------------------------------------------------------
