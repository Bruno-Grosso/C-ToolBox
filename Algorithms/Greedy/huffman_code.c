#include <stdio.h>
#include <stdlib.h>

// Estrutura base de um no na Arvore de Huffman
typedef struct HuffmanNode {
    char symbol;
    unsigned int freq;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

// Inicializa um novo no (folha para simbolos originais, ou interno para somas)
HuffmanNode* create_node(char symbol, unsigned int freq) {
    HuffmanNode* new_node = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    new_node->symbol = symbol;
    new_node->freq = freq;
    new_node->left = NULL;
    new_node->right = NULL;
    
    return new_node;
}

// O core do algoritmo guloso: funde os dois nos de menor frequencia
HuffmanNode* merge_nodes(HuffmanNode* left_child, HuffmanNode* right_child) {
    // Cria um no pai interno sem simbolo util ('\0'), somando as frequencias
    HuffmanNode* parent = create_node('\0', left_child->freq + right_child->freq);
    
    // Conecta a subarvore
    parent->left = left_child;
    parent->right = right_child;
    
    return parent;
}

// Motor de decodificacao (recebe a raiz da arvore e o fluxo binario "1011001...")
void decode_huffman(HuffmanNode* root, const char* encoded_stream) {
    if (root == NULL || encoded_stream == NULL) return;

    HuffmanNode* current = root;
    
    // Varre o fluxo de bits (stream) bit a bit ate o final
    for (int i = 0; encoded_stream[i] != '\0'; i++) {
        
        // Regra de transicao da arvore: '0' desce a esquerda, '1' desce a direita
        if (encoded_stream[i] == '0') {
            current = current->left;
        } else if (encoded_stream[i] == '1') {
            current = current->right;
        }
        
        // Verifica se alcancou um no folha (onde residem os simbolos decifrados)
        if (current->left == NULL && current->right == NULL) {
            
            // Imprime ou armazena o caractere original revelado
            printf("%c", current->symbol); 
            
            // Reinicia o ponteiro na raiz da arvore para buscar o proximo simbolo
            current = root; 
        }
    }
}
