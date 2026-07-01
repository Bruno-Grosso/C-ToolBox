#include <stdlib.h>
#include <time.h>

// Arquitetura: O Nó da Lista Encadeada para resolver colisões
typedef struct Node {
    int chave;
    struct Node* prox;
} Node;

// Arquitetura: A Tabela contendo os parâmetros do Hashing Universal e o Array de Ponteiros
typedef struct TabelaHash {
    Node** gavetas;
    int m; // Tamanho da tabela
    int p; // Número primo gigante
    int a; // Semente multiplicadora
    int b; // Semente somadora
} TabelaHash;

TabelaHash* inicializar_tabela(int m, int p) {
    TabelaHash* tabela = (TabelaHash*)malloc(sizeof(TabelaHash));
    tabela->m = m;
    tabela->p = p;
    tabela->gavetas = (Node**)malloc(m * sizeof(Node*));
    
    // Inicializa todas as gavetas apontando para NULL (Vazias)
    for (int i = 0; i < m; i++) {
        tabela->gavetas[i] = NULL;
    }
    
    // Sorteia as chaves do Hashing Universal uma única vez
    srand(time(NULL));
    tabela->a = 1 + (rand() % (p - 1));
    tabela->b = rand() % p;
    
    return tabela;
}

// O Motor Matemático: Hashing Universal em duas fases
int funcao_hash(TabelaHash* tabela, int chave) {
    // Fase 1: Liquidificador Primo (Usa long long para evitar Overflow)
    long long embaralhamento = ((long long)tabela->a * chave + tabela->b) % tabela->p;
    
    // Fase 2: Encaixe na Memória RAM
    return embaralhamento % tabela->m;
}

// Inserção O(1): Coloca o novo elemento sempre na "cabeça" da lista encadeada
void inserir(TabelaHash* tabela, int chave) {
    int indice = funcao_hash(tabela, chave);
    
    Node* novo_no = (Node*)malloc(sizeof(Node));
    novo_no->chave = chave;
    
    // O novo nó aponta para quem estava no início da gaveta, e a gaveta aponta para ele
    novo_no->prox = tabela->gavetas[indice];
    tabela->gavetas[indice] = novo_no;
}

// Busca O(1 + alpha): Percorre a lista encadeada apenas da gaveta específica
Node* buscar(TabelaHash* tabela, int chave) {
    int indice = funcao_hash(tabela, chave);
    Node* atual = tabela->gavetas[indice];
    
    while (atual != NULL) {
        if (atual->chave == chave) {
            return atual; // Encontrou
        }
        atual = atual->prox;
    }
    
    return NULL; // Não encontrou
}
