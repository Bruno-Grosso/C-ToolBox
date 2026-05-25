# Jenkins One-At-A-Time Hash

**Quando usar:** Sempre que precisar criar uma Tabela Hash em C para evitar a lentidão $O(N^2)$ em problemas de busca e contagem.

**O que faz:**
Recebe um bloco de memória (um array, uma string ou uma struct) e tritura os bits para gerar um ID (gaveta) único, evitando colisões.

**Como acionar (A interface):**
`unsigned long gaveta = oaat((char *)meu_dado, sizeof(meu_dado), 17);`
*(Nota: O número 17 gera 131.072 gavetas. Ajustar conforme o problema).*
