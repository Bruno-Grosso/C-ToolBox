void dfs_core(Graph* grafo, int current, int* visited) {
    // Marca e processa o vértice atual
    visited[current] = 1;
    printf("%d ", current);

    // Varre as conexões diretas via Lista de Adjacência
    Node* temp = grafo->array[current];
    
    while (temp != NULL) {
        int vizinho = temp->destino;
        
        // Mergulho recursivo em vértices inéditos
        if (visited[vizinho] == 0) {
            dfs_core(grafo, vizinho, visited);
        }
        
        temp = temp->proximo;
    }
}

void dfs(Graph* grafo, int origem, int num_vertex) {
    // Inicialização do array de estado (controle de ciclos)
    int visited[num_vertex];
    for (int i = 0; i < num_vertex; i++) {
        visited[i] = 0;
    }
    
    printf("Ordem de visitacao DFS: ");
    
    // Dispara a ignição do motor a partir da origem
    dfs_core(grafo, origem, visited);
    
    printf("\n");
}
