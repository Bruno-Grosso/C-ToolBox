#include <stdio.h>
#include <stdlib.h>

// 1. Sub-rotina de fusão (Merge)
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Alocação dinâmica na memória Heap (Protege contra Stack Overflow)
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copia os dados originais para os arrays temporários
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0; // Índice do array Esquerdo (L)
    int j = 0; // Índice do array Direito (R)
    int k = left; // Índice do array Principal

    // Compara e devolve o menor elemento ao array original
    while (i < n1 && j < n2) {
        // O sinal de "<=" é o que garante a ESTABILIDADE do Merge Sort
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos que sobraram na metade esquerda
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos que sobraram na metade direita
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Liberta a memória para evitar fugas (Memory Leaks)
    free(L);
    free(R);
}

// 2. A Interface principal do Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Previne overflow em arrays gigantes
        
        // Divisão recursiva
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Conquista (Fusão)
        merge(arr, left, mid, right);
    }
}

// --- ZONA DE TESTES (Para o seu Toolbox) ---

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10, 19, 50, 43};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array original: \n");
    printArray(arr, n);
    
    mergeSort(arr, 0, n - 1);
    
    printf("Array ordenado (Merge Sort): \n");
    printArray(arr, n);
    
    return 0;
}
