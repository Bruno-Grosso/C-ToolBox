#include <stdlib.h>

// Arquitetura central: O Nó agora carrega um metadado de Cor e o ponteiro para o Pai
enum Cor { VERMELHO, PRETO };

typedef struct Node {
    int valor;
    enum Cor cor;
    struct Node* esq;
    struct Node* dir;
    struct Node* pai;
} Node;

Node* criar_no(int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->cor = VERMELHO; // Todo nó novo nasce vermelho pela regra da RBT
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = NULL;
    return novo;
}

// O motor físico: Gira os ponteiros para a esquerda mantendo a ordem da BST
void rotacao_esquerda(Node** raiz, Node* x) {
    Node* y = x->dir;
    x->dir = y->esq;
    if (y->esq != NULL) y->esq->pai = x;
    y->pai = x->pai;
    if (x->pai == NULL) *raiz = y;
    else if (x == x->pai->esq) x->pai->esq = y;
    else x->pai->dir = y;
    y->esq = x;
    x->pai = y;
}

// O motor físico: Gira os ponteiros para a direita mantendo a ordem da BST
void rotacao_direita(Node** raiz, Node* y) {
    Node* x = y->esq;
    y->esq = x->dir;
    if (x->dir != NULL) x->dir->pai = y;
    x->pai = y->pai;
    if (y->pai == NULL) *raiz = x;
    else if (y == y->pai->dir) y->pai->dir = x;
    else y->pai->esq = x;
    x->dir = y;
    y->pai = x;
}

// A lógica principal: Conserta as violações de cor e altura após uma inserção
void consertar_insercao(Node** raiz, Node* z) {
    while (z->pai != NULL && z->pai->cor == VERMELHO) {
        if (z->pai == z->pai->pai->esq) { // O pai é o filho da esquerda
            Node* tio = z->pai->pai->dir;
            
            // Caso 1: O tio é vermelho (Apenas recolore e sobe o problema)
            if (tio != NULL && tio->cor == VERMELHO) {
                z->pai->cor = PRETO;
                tio->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                z = z->pai->pai;
            } else {
                // Caso 2: O tio é preto e o nó é filho da direita (Rotação Dupla)
                if (z == z->pai->dir) {
                    z = z->pai;
                    rotacao_esquerda(raiz, z);
                }
                // Caso 3: O tio é preto e o nó é filho da esquerda (Rotação Simples)
                z->pai->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                rotacao_direita(raiz, z->pai->pai);
            }
        } else { // O pai é o filho da direita (Lógica espelhada)
            Node* tio = z->pai->pai->esq;
            
            if (tio != NULL && tio->cor == VERMELHO) {
                z->pai->cor = PRETO;
                tio->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                z = z->pai->pai;
            } else {
                if (z == z->pai->esq) {
                    z = z->pai;
                    rotacao_direita(raiz, z);
                }
                z->pai->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                rotacao_esquerda(raiz, z->pai->pai);
            }
        }
    }
    (*raiz)->cor = PRETO; // A raiz deve ser estritamente preta
}

// Inserção básica de BST, seguida pela chamada do motor de balanceamento
void inserir_rbt(Node** raiz, int valor) {
    Node* z = criar_no(valor);
    Node* y = NULL;
    Node* x = *raiz;

    // Desce a árvore como uma BST normal
    while (x != NULL) {
        y = x;
        if (z->valor < x->valor) x = x->esq;
        else x = x->dir;
    }

    z->pai = y;
    if (y == NULL) *raiz = z;
    else if (z->valor < y->valor) y->esq = z;
    else y->dir = z;

    // Aciona a blindagem arquitetural da RBT
    consertar_insercao(raiz, z);
}
