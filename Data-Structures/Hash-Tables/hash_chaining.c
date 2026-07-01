#include <stdlib.h>

// Arquitetura: Nó da Lista Encadeada
typedef struct Node {
    int chave;
    struct Node* prox;
} Node;

// Arquitetura: Tabela Principal
typedef struct TabelaHash {
    Node** gavetas;
    int m; 
    int p; 
    int a; 
    int b; 
} TabelaHash;

// Motor Matemático (Hashing Universal)
int funcao_hash(TabelaHash* tabela, int chave) {
    long long embaralhamento = ((long long)tabela->a * chave + tabela->b) % tabela->p;
    return embaralhamento % tabela->m;
}

// Inserção O(1): Empurra sempre para a cabeça da lista
void inserir(TabelaHash* tabela, int chave) {
    int indice = funcao_hash(tabela, chave);
    
    Node* novo_no = (Node*)malloc(sizeof(Node));
    novo_no->chave = chave;
    novo_no->prox = tabela->gavetas[indice];
    
    tabela->gavetas[indice] = novo_no;
}

// Busca O(1 + alpha): Varre apenas a lista da gaveta específica
Node* buscar(TabelaHash* tabela, int chave) {
    int indice = funcao_hash(tabela, chave);
    Node* atual = tabela->gavetas[indice];
    
    while (atual != NULL) {
        if (atual->chave == chave) return atual;
        atual = atual->prox;
    }
    
    return NULL;
}
