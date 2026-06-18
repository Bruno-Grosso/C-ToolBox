// 1. MOTOR 1: DFS que anota o tempo de término (Preenche a Pilha)
void dfs_fill_stack(Graph* grafo, int v, int* visited, int* stack, int* top) {
    visited[v] = 1;
    
    Node* temp = grafo->array[v];
    while (temp != NULL) {
        if (visited[temp->destino] == 0) {
            dfs_fill_stack(grafo, temp->destino, visited, stack, top);
        }
        temp = temp->proximo;
    }
    
    // O vértice só entra na pilha quando for um beco sem saída absoluto
    stack[*top] = v;
    (*top)++;
}

// 2. MOTOR 2: DFS clássica para agrupar as bolhas
void dfs_print_scc(Graph* grafo, int v, int* visited) {
    visited[v] = 1;
    printf("%d ", v); // Imprime a cidade que pertence à bolha atual
    
    Node* temp = grafo->array[v];
    while (temp != NULL) {
        if (visited[temp->destino] == 0) {
            dfs_print_scc(grafo, temp->destino, visited);
        }
        temp = temp->proximo;
    }
}

// 3. O MÓDULO PRINCIPAL (A Orquestração)
void kosaraju(Graph* grafo, int num_vertex) {
    int stack[num_vertex];
    int top = 0;
    int visited[num_vertex];

    // PASSO 1: Zerar estado e preencher a pilha baseada na ordem de término
    for (int i = 0; i < num_vertex; i++) visited[i] = 0;
    
    for (int i = 0; i < num_vertex; i++) {
        if (visited[i] == 0) {
            dfs_fill_stack(grafo, i, visited, stack, &top);
        }
    }

    // PASSO 2: A Transposição (Inverter o mapa)
    // Inicializa um mapa vazio para receber as ruas na contramão
    Graph* grafo_transposto = criarGrafo(num_vertex); 
    
    for (int i = 0; i < num_vertex; i++) {
        Node* temp = grafo->array[i];
        while (temp != NULL) {
            // A mágica: Onde era Origem->Destino, inserimos Destino->Origem
            adicionarAresta(grafo_transposto, temp->destino, i, temp->peso);
            temp = temp->proximo;
        }
    }

    // PASSO 3: Rodar a DFS no mapa invertido seguindo a ordem da Pilha
    for (int i = 0; i < num_vertex; i++) visited[i] = 0;

    printf("Componentes Fortemente Conexos (Bolhas isoladas):\n");
    
    while (top > 0) {
        top--;
        int v = stack[top];

        // Cada vez que esse 'if' passa, descobrimos um novo componente isolado
        if (visited[v] == 0) {
            printf("[ ");
            dfs_print_scc(grafo_transposto, v, visited);
            printf("]\n");
        }
    }
