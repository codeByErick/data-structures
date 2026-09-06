#include <stdio.h>
#include <stdlib.h>

/*
 * SELECTION SORT (Ordenação por Seleção)
 *
 * Funcionamento: A cada iteração, percorre a parte ainda não ordenada
 * do vetor procurando o MENOR elemento. Ao encontrá-lo, troca sua posição
 * com o primeiro elemento dessa parte. O processo se repete, avançando
 * uma posição a cada iteração, até que todo o vetor esteja ordenado.
 *
 * Complexidade de Tempo: O(n²)
 */


void selectionSort(int *vetor, int tamanho){
	int i, j, aux, menor;
	for(i = 0; i<tamanho; i++){
		menor = i; //Essa variável contém o índice do menor elemento, na primeira iteração será assumido o menor sendo o da posição 0
		for(j = i+1; j<tamanho; j++){
			if(vetor[j] < vetor[menor]){//Procura o menor elemento do vetor e atualiza a posição de menor
				menor = j;
			}
		}
		//Realiza a troca se menor for diferente de i (Não houve elemento menor que i)
		if(menor != i){
			aux = vetor[i];
			vetor[i] = vetor[menor];
			vetor[menor] = aux;
		}
	}
}

void mostraVetor(int *vetor, int tamanho){
	for(int i = 0; i<tamanho; i++){
		printf("%d ", vetor[i]);
	}

}

int main(){
	int vetor[5] = {4, 2, 1, 3, 5};

	int qtd_elementos = (int)(sizeof(vetor) / sizeof(vetor[0]));
	selectionSort(vetor, qtd_elementos);
	mostraVetor(vetor, qtd_elementos);
	return 0;
}
