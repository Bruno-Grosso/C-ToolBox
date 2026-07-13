#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 1000 // Tamanho do array em bytes (1000 bytes = 8000 bits)

typedef struct {
    unsigned char bits[SIZE];
} BloomFilter;

// Inicia a estrutura com todos os bits zerados
void init_bloom(BloomFilter *bf) {
    memset(bf->bits, 0, SIZE);
}

// Função Hash 1: Algoritmo djb2 (Clássico para strings em C)
unsigned int hash1(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; 
    }
    return hash % (SIZE * 8); // Garante que o índice cabe no limite de bits
}

// Função Hash 2: Algoritmo sdbm
unsigned int hash2(const char *str) {
    unsigned long hash = 0;
    int c;
    while ((c = *str++)) {
        hash = c + (hash << 6) + (hash << 16) - hash;
    }
    return hash % (SIZE * 8);
}

// Insere "acendendo" os bits usando a operação OR (|)
void insert(BloomFilter *bf, const char *str) {
    unsigned int h1 = hash1(str);
    unsigned int h2 = hash2(str);

    bf->bits[h1 / 8] |= (1 << (h1 % 8));
    bf->bits[h2 / 8] |= (1 << (h2 % 8));
}

// Checa verificando se os bits estão acesos com a operação AND (&)
bool search(BloomFilter *bf, const char *str) {
    unsigned int h1 = hash1(str);
    unsigned int h2 = hash2(str);

    bool bit1 = bf->bits[h1 / 8] & (1 << (h1 % 8));
    bool bit2 = bf->bits[h2 / 8] & (1 << (h2 % 8));

    return bit1 && bit2;
}

int main() {
    BloomFilter bf;
    init_bloom(&bf);

    insert(&bf, "memoria_cache");
    insert(&bf, "matriz_adjacencia");

    printf("Busca 'memoria_cache': %d\n", search(&bf, "memoria_cache")); // Retorna 1 (True)
    printf("Busca 'ponteiro_duplo': %d\n", search(&bf, "ponteiro_duplo")); // Retorna 0 (False)

    return 0;
}
