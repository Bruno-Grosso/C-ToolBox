# Jenkins One-At-A-Time Hash

**Quando usar:** Sempre que precisar criar uma Tabela Hash em C para evitar a lentidão $O(N^2)$ em problemas de busca e contagem.

**O que faz:**
Recebe um bloco de memória (um array, uma string ou uma struct) e tritura os bits para gerar um ID (gaveta) único, evitando colisões.

**Como acionar (A interface):**
`unsigned long gaveta = oaat((char *)meu_dado, sizeof(meu_dado), 17);`
*(Nota: O número 17 gera 131.072 gavetas. Ajustar conforme o problema).*

---

# Tabela Hash: Hashing Universal com Encadeamento (*Chaining*)

**Quando usar:** Quando você precisa de um dicionário de dados ou sistema de cache extremamente rápido e seguro, e não quer se preocupar com a tabela travando caso fique muito cheia. É a estrutura ideal para indexar IDs de usuários, rotas de rede ou tabelas de símbolos em compiladores.

**O que faz:** Cria um array principal na memória onde cada posição (gaveta) guarda um ponteiro para uma Lista Encadeada. O sistema utiliza a arquitetura de **Hashing Universal**, que sorteia parâmetros matemáticos randômicos ($a$ e $b$) e utiliza a aritmética de números primos ($p$) para embaralhar as chaves inseridas. Isso blinda o sistema contra ataques de negação de serviço (HashDoS) e garante que os dados se espalhem perfeitamente. Em caso de colisão (duas chaves caindo na mesma gaveta), elas são simplesmente empilhadas em uma lista ligada.

**A Velocidade (Prática vs Matemática):** Graças ao Hashing Universal, a probabilidade de colisão é minimizada, garantindo um tempo de inserção e busca esperado rigoroso de **$\mathcal{O}(1)$**. A estabilidade dessa performance depende do *Fator de Carga* ($\alpha = \frac{N}{M}$). Contanto que $\alpha$ seja mantido baixo (usando redimensionamento dinâmico), a busca na lista encadeada é instantânea.

**Encadeamento vs. Endereçamento Livre (*Open Addressing*):** Nesta implementação, optou-se pelo Tratamento de Colisão por Encadeamento (usando `structs` e ponteiros). Uma alternativa de design seria o **Endereçamento Livre** (ex: *Sondagem Dupla* ou *Linear*), que armazena os dados diretamente no array principal, eliminando os ponteiros para economizar memória RAM e maximizar o cache do processador. O custo do Endereçamento Livre é uma intolerância muito maior a fatores de carga altos, travando o sistema se a memória lotar, enquanto o Encadeamento desta implementação suporta sobrecargas graciosamente.

**Como acionar (A interface):**

```c
// Inicializa uma tabela com 11 gavetas e um primo maior que as chaves esperadas
TabelaHash* dicionario = inicializar_tabela(11, 104729);

inserir(dicionario, 402);
inserir(dicionario, 951);

Node* resultado = buscar(dicionario, 402); // Retorna instantaneamente o ponteiro do nó
