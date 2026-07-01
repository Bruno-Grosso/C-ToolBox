# Jenkins One-At-A-Time Hash

**Quando usar:** Sempre que precisar criar uma Tabela Hash em C para evitar a lentidão $O(N^2)$ em problemas de busca e contagem.

**O que faz:**
Recebe um bloco de memória (um array, uma string ou uma struct) e tritura os bits para gerar um ID (gaveta) único, evitando colisões.

**Como acionar (A interface):**
`unsigned long gaveta = oaat((char *)meu_dado, sizeof(meu_dado), 17);`
*(Nota: O número 17 gera 131.072 gavetas. Ajustar conforme o problema).*

---

# Tabela Hash: Hashing Universal + Encadeamento

**Quando usar:** Em dicionários de dados e sistemas de cache de altíssima velocidade onde a tabela pode sofrer picos de sobrecarga sem o risco de travar o sistema.

**O que faz:** * **Estrutura Física:** Cria um array principal onde cada gaveta guarda um ponteiro para uma Lista Encadeada.
* **Segurança Matemática:** Usa o **Hashing Universal** (sorteando variáveis $a$ e $b$, e usando um número primo $p$) para blindar o sistema contra ataques de colisões propositais (HashDoS).
* **Resolução de Colisões:** Se duas chaves caem na mesma gaveta, elas são conectadas por ponteiros (Encadeamento).

**A Velocidade:**
* **Tempo de Execução:** $\mathcal{O}(1)$ para inserção e busca.
* **Gargalo:** A performance depende de manter o Fator de Carga ($\alpha$) baixo, evitando que as listas encadeadas fiquem longas demais.

**Encadeamento vs Endereçamento Livre:**
* **Encadeamento (Este código):** Usa `structs` e ponteiros. Gasta mais memória RAM com chamadas de `malloc`, mas é super resiliente se a tabela encher.
* **Endereçamento Livre:** Usa apenas um array contíguo. Maximiza o cache L1/L2 do processador, mas trava em loop infinito se atingir 100% de ocupação sem um redimensionamento prévio.

**Como acionar (A interface):**

```c
// Inicializa tabela com 11 gavetas e um primo gigante (104729)
TabelaHash* dicionario = inicializar_tabela(11, 104729);

inserir(dicionario, 402);
inserir(dicionario, 951);

Node* resultado = buscar(dicionario, 402); // Retorna o ponteiro O(1)
