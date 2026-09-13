/*
 * QUICK SORT
 *
 * Funcionamento:
 * O Quick Sort escolhe um elemento do vetor como PIVÔ e reorganiza
 * os elementos ao seu redor.
 *
 * Elementos menores que o pivô ficam à esquerda e elementos maiores
 * ficam à direita. Depois disso, o pivô está em sua posição definitiva.
 *
 * O processo é repetido recursivamente nas duas partes do vetor:
 *
 *              [ menores | PIVÔ | maiores ]
 *                         ↓
 *              [ menores ]   [ maiores ]
 *
 * A função particiona() é responsável por realizar essa divisão,
 * enquanto a função quickSort() chama a si mesma para ordenar
 * as partes restantes.
 *
 * Complexidade de tempo:
 * - Caso médio: O(n log n)
 * - Melhor caso: O(n log n)
 * - Pior caso: O(n²)
 */


// Função responsável por particionar o vetor em torno de um pivô.
// Ao final, o pivô ficará em sua posição correta.
int particiona(int *V, int inicio, int final) {

    int esq, dir, pivo, aux;

    // Índice que percorre o vetor da esquerda para a direita.
    esq = inicio;

    // Índice que percorre o vetor da direita para a esquerda.
    dir = final;

    // Escolhe o primeiro elemento da parte do vetor como pivô.
    pivo = V[inicio];

    // Continua enquanto os índices ainda não se encontraram.
    while (esq < dir) {

        // Avança pela esquerda enquanto os elementos forem menores
        // ou iguais ao pivô, pois já estão no lado correto.
        while (esq <= final && V[esq] <= pivo)
            esq++;

        // Avança pela direita enquanto os elementos forem maiores
        // que o pivô, pois já estão no lado correto.
        while (dir >= 0 && V[dir] > pivo)
            dir--;

        // Se os índices ainda não se encontraram, encontramos um
        // elemento grande demais à esquerda e um pequeno demais
        // à direita. Então os dois são trocados.
        if (esq < dir) {
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }

    // Coloca o elemento encontrado pela direita na posição inicial.
    V[inicio] = V[dir];

    // Coloca o pivô na posição encontrada pela direita.
    // A partir daqui, o pivô está em sua posição definitiva.
    V[dir] = pivo;

    // Retorna a posição onde o pivô terminou.
    return dir;
}


// Função principal do Quick Sort.
// Ordena a parte do vetor entre inicio e fim.
void quickSort(int *V, int inicio, int fim) {

    int pivo;

    // Se houver pelo menos dois elementos, realiza a partição.
    if (fim > inicio) {

        // Particiona o vetor e recebe a posição final do pivô.
        pivo = particiona(V, inicio, fim);

        // Ordena recursivamente a parte à esquerda do pivô.
        quickSort(V, inicio, pivo - 1);

        // Ordena recursivamente a parte à direita do pivô.
        quickSort(V, pivo + 1, fim);
    }
}
