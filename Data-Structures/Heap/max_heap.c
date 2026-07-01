#include <stdlib.h>

// Arquitetura central: Struct que gerencia o Array puro
typedef struct Heap {
    int* dados;
    int tamanho;
    int capacidade;
} Heap;

// A Mágica Matemática: Navegando na "Árvore" usando índices do Array
int pai(int i) { return (i - 1) / 2; }
int filho_esq(int i) { return (2 * i) + 1; }
int filho_dir(int i) { return (2 * i) + 2; }

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

Heap* criar_heap(int capacidade) {
    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->capacidade = capacidade;
    h->tamanho = 0;
    h->dados = (int*)malloc(capacidade * sizeof(int));
    return h;
}

// Sobe o elemento recém-inserido até a posição correta O(log N)
void heapify_up(Heap* h, int i) {
    // NOTA: Para transformar em Min-Heap, mude a condição para: h->dados[pai(i)] > h->dados[i]
    while (i != 0 && h->dados[pai(i)] < h->dados[i]) {
        trocar(&h->dados[i], &h->dados[pai(i)]);
        i = pai(i);
    }
}

// Desce a nova raiz até a posição correta O(log N)
void heapify_down(Heap* h, int i) {
    int alvo = i; 
    int esq = filho_esq(i);
    int dir = filho_dir(i);

    // NOTA: Para transformar em Min-Heap, mude o '>' para '<' nas duas verificações abaixo
    if (esq < h->tamanho && h->dados[esq] > h->dados[alvo])
        alvo = esq;

    if (dir < h->tamanho && h->dados[dir] > h->dados[alvo])
        alvo = dir;

    if (alvo != i) {
        trocar(&h->dados[i], &h->dados[alvo]);
        heapify_down(h, alvo);
    }
}

void inserir(Heap* h, int valor) {
    if (h->tamanho == h->capacidade) return; // Heap cheio
    
    int i = h->tamanho;
    h->dados[i] = valor;
    h->tamanho++;

    heapify_up(h, i);
}

int extrair(Heap* h) {
    if (h->tamanho <= 0) return -1; // Heap vazio
    
    if (h->tamanho == 1) {
        h->tamanho--;
        return h->dados[0];
    }

    int raiz = h->dados[0];
    h->dados[0] = h->dados[h->tamanho - 1]; // Joga o último elemento para a raiz
    h->tamanho--;
    
    heapify_down(h, 0); // Reorganiza a árvore

    return raiz;
}
