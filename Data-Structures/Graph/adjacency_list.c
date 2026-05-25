#include <stdio.h>
#include <stdlib.h>

/* =========================================================
 * ESTRUTURAS DE DADOS
 * ========================================================= */

// Estrutura da conexão (O nó da lista ligada)
typedef struct NoAresta {
    int destino;
    struct NoAresta* proximo;
} NoAresta;

// Estrutura do Grafo (O Painel de Controle)
typedef struct Grafo {
    int numVertices;
    NoAresta** listas; // Array dinâmico de ponteiros para as listas
} Grafo;

/* =========================================================
 * FUNÇÕES DE CRIAÇÃO E INSERÇÃO
 * ========================================================= */

// Inicializa o grafo na RAM em O(V)
Grafo* criarGrafo(int numVertices) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->numVertices = numVertices;
    
    // O calloc garante que todos os ponteiros iniciem como NULL
    grafo->listas = (NoAresta**)calloc(numVertices, sizeof(NoAresta*));
    
    return grafo;
}

// Adiciona uma aresta direcional (origem -> destino) em O(1)
void adicionarAresta(Grafo* grafo, int origem, int destino) {
    NoAresta* novaAresta = (NoAresta*)malloc(sizeof(NoAresta));
    novaAresta->destino = destino;
    
    // Insere o novo nó no INÍCIO da lista para garantir O(1)
    novaAresta->proximo = grafo->listas[origem];
    grafo->listas[origem] = novaAresta;
}

/* =========================================================
 * TESTE DE EXECUÇÃO
 * ========================================================= */
int main() {
    // 1. Define o tamanho do mapa (ex: 5 vértices, IDs de 0 a 4)
    int numVertices = 5;
    Grafo* meuMapa = criarGrafo(numVertices);

    // 2. Adiciona as conexões (Origem -> Destino)
    adicionarAresta(meuMapa, 0, 1);
    adicionarAresta(meuMapa, 0, 4);
    
    // O Vértice 1 vai apontar para o 2 e depois para o 3
    adicionarAresta(meuMapa, 1, 2);
    adicionarAresta(meuMapa, 1, 3); 
    
    adicionarAresta(meuMapa, 3, 4);

    // 3. Validação visual na memória
    printf("Grafo inicializado com %d vertices.\n", meuMapa->numVertices);
    
    // Vamos checar quem está no topo da lista do Vértice 1.
    // Como a inserção é O(1) (sempre empurra para o início), 
    // o ÚLTIMO a ser adicionado (3) deve ser o PRIMEIRO da fila.
    if (meuMapa->listas[1] != NULL) {
        printf("A primeira conexao do Vertice 1 aponta para o Vertice: %d\n", meuMapa->listas[1]->destino);
    }

    return 0;
}
