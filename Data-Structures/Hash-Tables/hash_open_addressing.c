#include <stdlib.h>

// Arquitetura: Tabela puramente baseada em Array (Sem ponteiros extras)
typedef struct TabelaHash {
    int* gavetas;
    int m;
    int p;
    int a;
    int b;
} TabelaHash;

// Motor Matemático Primário
int funcao_hash(TabelaHash* tabela, int ip) {
    long long embaralhamento = ((long long)tabela->a * ip + tabela->b) % tabela->p;
    return embaralhamento % tabela->m;
}

// Inserção com Sondagem Dupla (Double Hashing)
void inserir(TabelaHash* tabela, int ip) {
    int indice = funcao_hash(tabela, ip);
    int salto = 1 + (ip % 5); // Motor Secundário
    int ind = indice;
    
    while(tabela->gavetas[ind] != -1) {
        if(tabela->gavetas[ind] == ip) return; // Evita duplicatas
        
        ind = (ind + salto) % tabela->m;
        
        if(ind == indice) return; // Tabela lotada
    }
    
    tabela->gavetas[ind] = ip;
}

// Busca saltando pelas gavetas
int buscar(TabelaHash* tabela, int ip) {
    int indice = funcao_hash(tabela, ip);
    int salto = 1 + (ip % 5);
    int ind = indice;
    
    while(tabela->gavetas[ind] != -1) {
        if(tabela->gavetas[ind] == ip) return ind; // Achou
        
        ind = (ind + salto) % tabela->m;
        
        if(ind == indice) break; // Deu a volta completa
    }
    
    return -1; // Não achou
}
