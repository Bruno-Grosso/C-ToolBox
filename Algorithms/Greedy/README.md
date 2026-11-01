## Algoritmo de Huffman (Compressão de Dados Sem Perdas)[/huffman_code.c]

**Quando usar:** A ferramenta definitiva para compactação de arquivos, streaming de mídia, protocolos de rede de alta performance e algoritmos de arquivamento (como ZIP e GZIP). Sempre que você precisar comprimir uma sequência de dados reduzindo o número total de bits sem perder absolutamente nenhuma informação. É a base matemática para qualquer sistema moderno de transferência eficiente de arquivos.

**O que faz:** O algoritmo opera sob um princípio guloso (*greedy*). Ele escaneia o arquivo original e constrói uma árvore binária de baixo para cima, priorizando os símbolos. Caracteres que aparecem muito ganham códigos binários minúsculos (ex: `01`), enquanto caracteres raros recebem códigos maiores (ex: `10110`). Para montar essa árvore com máxima eficiência geométrica, o algoritmo une constantemente os dois símbolos de menor frequência, criando um novo nó "pai" que soma as ocorrências. Esse processo continua até sobrar apenas a raiz, garantindo matematicamente a compressão ótima. Para extrair os dados depois, basta seguir o fluxo de bits (0 = esquerda, 1 = direita) através da árvore até atingir uma folha.

**A Velocidade (Prática vs Matemática):** Na sua execução plena utilizando uma **Min-Heap (Fila de Prioridade)** para gerenciar a fusão dos nós, a complexidade atinge a excelência de **O(N log N)**, onde N é o número de caracteres únicos do alfabeto. O custo adicional de varrer o arquivo inicial para contar as frequências é estritamente **O(K)** (sendo K o tamanho total do arquivo original). O consumo de memória aloca estritamente o necessário para a construção da árvore binária dinâmica, resultando num motor de compressão ultrarrápido com *overhead* mínimo de RAM.

**Como acionar (A interface):**

```c
// Constrói a árvore de compressão, fundindo os nós de menor frequência
HuffmanNode* root = build_huffman_tree(min_heap);

// Decodifica e imprime o texto original a partir da árvore e do fluxo de bits
decode_huffman(root, "101100101");
