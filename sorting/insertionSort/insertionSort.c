#include <stdio.h>

/*
 * INSERTION SORT (Ordenação por Inserção)
 * Funcionamento: Percorre o vetor a partir do segundo elemento,
 * considerando a parte à esquerda como ordenada. O elemento atual
 * é comparado com os elementos anteriores e, enquanto for menor,
 * os elementos maiores são deslocados para a direita. Por fim,
 * o elemento atual é inserido na posição correta.
 *
 * Complexidade de Tempo: O(n²)
 */

void insertionSort(int *vetor, int tamanho){

    int i, j, atual;

    // Começa pelo segundo elemento, pois o primeiro já é considerado ordenado
    for(i = 1; i < tamanho; i++){

        // Guarda o elemento que será inserido na posição correta
        atual = vetor[i];

        // Enquanto o elemento à esquerda for maior que "atual", desloca ele para a direita
        for(j = i; (j > 0) && (atual < vetor[j - 1]); j--){

            // Desloca o elemento maior uma posição para a direita
            vetor[j] = vetor[j - 1];
        }

        // Insere "atual" na posição correta
        vetor[j] = atual;
    }
}

int main(){

    return 0;
}

