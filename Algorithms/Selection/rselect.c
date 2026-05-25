#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* =========================================================
 * FUNÇÕES UTILITÁRIAS
 * ========================================================= */

// Troca dois elementos de lugar na memória
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* =========================================================
 * MOTOR DE PARTIÇÃO (O mesmo núcleo do QuickSort)
 * ========================================================= */

// Particiona o array em torno de um pivô aleatório e retorna o índice final dele
int partition(int arr[], int left, int right) {
    // 1. Escolhe um pivô aleatório para evitar o pior caso matemático
    int pivotIdx = left + rand() % (right - left + 1);
    
    // 2. Move o pivô para o final temporariamente
    swap(&arr[pivotIdx], &arr[right]);
    
    int pivot = arr[right];
    int i = left - 1;
    
    // 3. Varre o array e empurra os elementos menores para a esquerda
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    // 4. Coloca o pivô exatamente na sua posição final ordenada
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

/* =========================================================
 * ALGORITMO RSELECT
 * ========================================================= */

// Encontra o i-ésimo menor elemento em um array não ordenado em tempo médio O(N)
// NOTA: 'i' representa a estatística de ordem (1 para o mínimo, n para o máximo)
int rSelect(int arr[], int left, int right, int i) {
    // Caso base: Se só existe um elemento, ele obrigatoriamente é a resposta
    if (left == right) {
        return arr[left];
    }
    
    // Particiona o array e descobre onde o pivô foi parar
    int pivotIdx = partition(arr, left, right);
    
    // Calcula a estatística de ordem do pivô NESTE subarray atual
    int k = pivotIdx - left + 1;
    
    // Árvore de decisão: Para qual lado nós continuamos a busca?
    if (i == k) {
        // Na mosca! O pivô é exatamente o i-ésimo elemento que procurávamos
        return arr[pivotIdx];
    } else if (i < k) {
        // O elemento procurado está estritamente à esquerda. Descartamos a direita inteira!
        return rSelect(arr, left, pivotIdx - 1, i);
    } else {
        // O elemento está à direita. Descartamos a esquerda e reajustamos o 'i'
        return rSelect(arr, pivotIdx + 1, right, i - k);
    }
}

/* =========================================================
 * TESTE DE EXECUÇÃO
 * ========================================================= */
int main() {
    // Alimenta o gerador de números aleatórios com o relógio do sistema
    srand((unsigned int)time(NULL));
    
    int arr[] = {3, 1, 9, 7, 5, 2, 8, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Exemplo: Vamos encontrar o 5º menor elemento (que deve ser o número 5 neste array)
    int orderStatistic = 5;
    
    int result = rSelect(arr, 0, n - 1, orderStatistic);
    
    printf("O %d-esimo menor elemento e: %d\n", orderStatistic, result);
    
    return 0;
}
