typedef struct {
    int capacity;
    int num_items;
    int* dp;
} Knapsack;

int knapsack_core(Knapsack* knap, int* values, int* weights) {
    // Itera sobre todos os itens disponíveis
    for (int i = 0; i < knap->num_items; i++) {
        int current_weight = weights[i];
        int current_value = values[i];

        // Marcha à ré: varre a capacidade de trás para frente para evitar reutilizar o mesmo item (Mochila 0/1)
        for (int w = knap->capacity; w >= current_weight; w--) {
            int take_it = current_value + knap->dp[w - current_weight];
            int leave_it = knap->dp[w];

            // Atualiza com o valor máximo entre incluir ou excluir o item atual
            if (take_it > leave_it) {
                knap->dp[w] = take_it;
            }
        }
    }

    // Retorna o lucro máximo acumulado na capacidade total da mochila
    return knap->dp[knap->capacity];
}
