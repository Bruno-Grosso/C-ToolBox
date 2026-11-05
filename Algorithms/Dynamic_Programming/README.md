## [Problema da Mochila 0/1 com Rolling Arrays (Otimização de Espaço)](knapsack_backpack.c)

**Quando usar:** A ferramenta definitiva para problemas de alocação de recursos, gerenciamento de portfólio de investimentos, corte de material industrial, criptografia e sistemas de corte de estoque. Sempre que você precisa selecionar o subconjunto ideal de itens que maximiza o lucro total sem estourar uma capacidade ou limite estrito de peso. É o núcleo clássico de otimização combinatória em engenharia.

**O que faz:** O algoritmo opera sob o paradigma de **Programação Dinâmica**. Ele avalia incrementalmente cada item disponível, decidindo matematicamente entre incluí-lo ou ignorá-lo para cada subcapacidade possível da mochila. Para resolver o problema em larga escala sem esmagar os limites de memória física (evitando a barreira de gigabytes exigida por uma matriz bidimensional completa), a arquitetura implementa uma técnica de **Rolling Arrays** com indexação por paridade (`current_item % 2`) ou uma varredura iterativa em **marcha à ré** (`w >= current_weight`) usando um único array. Isso comprime drasticamente a complexidade espacial de $O(N \times W)$ para $O(W)$, garantindo que o processamento caiba confortavelmente na memória RAM.

**A Velocidade (Prática vs Matemática):** Na sua execução otimizada com alocação em Heap e manipulação direta de ponteiros, a complexidade temporal atinge **O(N \times W)**, onde N é o número total de itens e W é a capacidade máxima da mochila. O uso de tipos de dados de 64 bits (`long long`) protege o sistema contra estouramento de inteiros (*overflow*) ao acumular lucros massivos, enquanto o redirecionamento de fluxo (*freopen*) assegura uma ingestão de dados limpa e sem *overhead* de E/S.

**Como acionar (A interface):**

```c
// Inicializa a estrutura e aloca os vetores de otimização de espaço na Heap
Datas* datas = create_datas();

// Executa o núcleo de programação dinâmica por rolling arrays e retorna o lucro ótimo
long long value_final = DP_core(datas, 1);
