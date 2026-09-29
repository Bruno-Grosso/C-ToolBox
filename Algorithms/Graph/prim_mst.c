void dijkstra(Graph* grafo, int origem, int destino) {
    int num_vertex = grafo->num_vertex;
    int distance[num_vertex];
    int visited[num_vertex];
    int father[num_vertex];

    // 1. Setup
    for (int i = 0; i < num_vertex; i++) {
        distance[i] = INF;
        visited[i] = 0;
        father[i] = -1;
    }
    distance[origem] = 0;

    // 2. Motor Guloso
    for (int count = 0; count < num_vertex; count++) {
        
        // Ato I: Busca o menor custo não visitado
        int min_dist = INF;
        int current = -1;

        for (int i = 0; i < num_vertex; i++) {
            if (visited[i] == 0 && distance[i] < min_dist) {
                min_dist = distance[i];
                current = i;
            }
        }

        if (current == -1) break;
        
        // Ato II: Tranca a cidade atual
        visited[current] = 1;
        if (current == destino) break;

        // Ato III: Relaxamento dos vizinhos
        Node* temp = grafo->array[current];

        while (temp != NULL) {
            int vizinho = temp->destino;

            if (visited[vizinho] == 0) {
                int next_dist = distance[current] + temp->peso;

                if (next_dist < distance[vizinho]) {
                    distance[vizinho] = next_dist;
                    father[vizinho] = current;
                }
            }
            temp = temp->proximo;
        }
    }

    // 3. Resultado
    if (distance[destino] == INF) {
        printf("Impossivel chegar ao destino.\n");
    } else {
        printf("Distancia: %d\nRota: ", distance[destino]);
        
        int passo = destino;
        while (passo != -1) {
            printf("%d ", passo);
            if (father[passo] != -1) printf("<- ");
            passo = father[passo];
        }
        printf("\n");
    }
}
