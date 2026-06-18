#include <stdio.h>

// 1. Função auxiliar para troca de valores na memória
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 2. Extrai a Mediana de Três (Blinda contra o pior caso O(N^2))
int medianOfThree(int arr[], int left, int right) {
    int mid = left + (right - left) / 2;
    
    // Ordena o primeiro, o meio e o último
    if (arr[left] > arr[mid]) swap(&arr[left], &arr[mid]);
    if (arr[left] > arr[right]) swap(&arr[left], &arr[right]);
    if (arr[mid] > arr[right]) swap(&arr[mid], &arr[right]);
    
    // Esconde o pivô (mediana) na posição 'left' para iniciar o particionamento
    swap(&arr[mid], &arr[left]);
    return arr[left];
}

// 3. Sub-rotina de particionamento In-Place (varredura de memória)
int partition(int arr[], int left, int right) {
    int pivot = medianOfThree(arr, left, right);
    int i = left + 1; // Fronteira dos elementos menores que o pivô

    for (int j = left + 1; j <= right; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    // Coloca o pivô na sua posição definitiva
    swap(&arr[left], &arr[i - 1]);
    return i - 1;
}

// 4. A Interface principal do Quick Sort
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        
        // Conquista recursiva das metades
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
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
    int arr[] = {42, 10, 7, 8, 9, 1, 5, 23, 99, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array original: \n");
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    printf("Array ordenado (Quick Sort): \n");
    printArray(arr, n);
    
    return 0;
}
