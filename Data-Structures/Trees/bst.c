#include <stdlib.h>
#include <stdio.h>

// Arquitetura central: Apenas o Nó e seus dois caminhos possíveis
typedef struct Node {
    int valor;
    struct Node* esq;
    struct Node* dir;
} Node;

Node* criar_no(int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Inserção em O(h) descendo pelos galhos corretos
Node* inserir(Node* raiz, int valor) {
    if (raiz == NULL) return criar_no(valor);

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir(raiz->dir, valor);

    return raiz; // Retorna a raiz inalterada da sub-árvore
}

// Busca rápida em O(h) eliminando metade da árvore a cada passo
Node* buscar(Node* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor)
        return raiz;

    if (valor < raiz->valor)
        return buscar(raiz->esq, valor);

    return buscar(raiz->dir, valor);
}

// Função auxiliar para achar o Sucessor na hora de remover
Node* encontrar_minimo(Node* raiz) {
    Node* atual = raiz;
    while (atual && atual->esq != NULL)
        atual = atual->esq;
    return atual;
}

// Remoção: O coração estrutural da árvore
Node* remover(Node* raiz, int valor) {
    if (raiz == NULL) return raiz;

    // 1. Procurando o nó a ser deletado
    if (valor < raiz->valor)
        raiz->esq = remover(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = remover(raiz->dir, valor);
    else {
        // Nó encontrado!

        // Caso 1 e 2: O nó tem 0 ou 1 filho
        if (raiz->esq == NULL) {
            Node* temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            Node* temp = raiz->esq;
            free(raiz);
            return temp;
        }

        // Caso 3: O nó tem 2 filhos. Precisamos do sucessor (menor dos maiores)
        Node* temp = encontrar_minimo(raiz->dir);
        raiz->valor = temp->valor; // Copia o valor do sucessor para o nó atual
        raiz->dir = remover(raiz->dir, temp->valor); // Deleta o sucessor duplicado lá embaixo
    }
    return raiz;
}

// Leitura In-Order: Passa pelos elementos em ordem crescente exata
void in_order(Node* raiz) {
    if (raiz != NULL) {
        in_order(raiz->esq);
        printf("%d ", raiz->valor);
        in_order(raiz->dir);
    }
}
