// Assume a existência da estrutura Graph e Node da sua adjacency_list.c

void bfs(Graph* grafo, int origem, int num_vertex) {
    
    // 1. PREPARAÇÃO DO TERRENO
    int visited[num_vertex];
    for (int i = 0; i < num_vertex; i++) {
        visited[i] = 0;
    }

    // 2. A INFRAESTRUTURA DA FILA (QUEUE)
    int fila[num_vertex];
    int front = 0; // Quem é o próximo a ser processado
    int rear = 0;  // Onde o próximo descoberto vai entrar na fila

    // 3. IGNIÇÃO
    visited[origem] = 1;
    fila[rear] = origem; // Entra na fila
    rear++;

    // 4. O MOTOR DE EXPANSÃO (A ONDA)
    printf("Ordem de visitacao BFS: ");
    
    // Enquanto a fila não estiver vazia
    while (front < rear) {
        
        // Remove da frente da fila
        int current = fila[front];
        front++;
        
        printf("%d ", current); // Processa a cidade atual

        // Relaxamento (Varre os vizinhos imediatos)
        Node* temp = grafo->array[current];
        
        while (temp != NULL) {
            int vizinho = temp->destino;
            
            // Se o vizinho é inédito, tranca a porta e joga no fim da fila
            if (visited[vizinho] == 0) {
                visited[vizinho] = 1;
                fila[rear] = vizinho; 
                rear++;
            }
            temp = temp->proximo;
        }
    }
    printf("\n");
}
