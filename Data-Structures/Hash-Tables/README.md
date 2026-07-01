# Jenkins One-At-A-Time Hash

**Quando usar:** Sempre que precisar criar uma Tabela Hash em C para evitar a lentidão $O(N^2)$ em problemas de busca e contagem.

**O que faz:**
Recebe um bloco de memória (um array, uma string ou uma struct) e tritura os bits para gerar um ID (gaveta) único, evitando colisões.

**Como acionar (A interface):**
`unsigned long gaveta = oaat((char *)meu_dado, sizeof(meu_dado), 17);`
*(Nota: O número 17 gera 131.072 gavetas. Ajustar conforme o problema).*

---

## Encadeamento (*Chaining*)
**Arquivo:** `hash_chaining.c`

* **Como funciona:** Cada gaveta do array principal guarda um ponteiro para uma Lista Encadeada. Se houver colisão, os novos elementos são pendurados nessa lista.
* **Vantagem:** É uma estrutura elástica e resiliente. Sobrevive a picos de tráfego e não trava o sistema mesmo se a tabela ficar sobrecarregada (Fator de Carga alto).
* **Desvantagem:** O uso de `structs` e chamadas constantes de `malloc` para criar os nós fragmenta a memória RAM, reduzindo a eficiência do cache do processador.

---

## Endereçamento Aberto (*Open Addressing*)
**Arquivo:** `hash_open_addressing.c`

* **Como funciona:** Elimina totalmente as Listas Encadeadas e ponteiros. Os dados são salvos diretamente nas gavetas do array principal. Em caso de colisão, o algoritmo usa matemática (*Sondagem Dupla*) para calcular um pulo fixo e procurar a próxima gaveta vazia.
* **Vantagem:** Máxima velocidade bruta em hardware (*Cache-friendly*), pois o processador varre um bloco maciço e contíguo de memória RAM sem precisar caçar ponteiros soltos.
* **Desvantagem:** Exige controle rigoroso da lotação. Se a tabela atingir capacidade máxima, o sistema entra em loop infinito e trava, exigindo a implementação paralela de uma função de *Redimensionamento Dinâmico* (Re-hashing).
