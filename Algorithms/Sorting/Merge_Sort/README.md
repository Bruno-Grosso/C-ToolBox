# Merge Sort

**Quando usar:** Sempre que precisar de uma ordenação com velocidade **100% garantida** em O(N log N) em qualquer cenário e precisar de **Estabilidade** (manter a ordem original de elementos repetidos com a mesma chave), desde que tenha memória RAM abundante.

**O que faz:** Divide o array recursivamente pela metade até chegar a blocos de 1 elemento, e depois vem a "coser" (fundir) essas metades de volta na memória, já por ordem.

**A Velocidade (Prática vs Matemática):** Tem um limite matemático rigoroso e blindado de **O(N log N)** no melhor, médio e pior caso. O algoritmo nunca entra em colapso. Contudo, na execução real no *hardware*, costuma ser ligeiramente mais lento do que o Quick Sort. Isto ocorre porque o ato de pedir blocos de memória ao sistema operativo (`malloc`) e ler dados de áreas muito separadas da RAM gera atrasos físicos (os chamados *Cache Misses* no processador).

**Como acionar (A interface):** ```c
mergeSort(meu_array, 0, tamanho_do_array - 1);
