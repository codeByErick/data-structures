#include <stdio.h>
#include <stdlib.h>

//Essa função percorre o vetor, a cada iteração compara um elemento ao seu sucessor
//Caso o anterior "vetor[i]" seja maior que o sucessor vetor[i+1], há inversão das posições
//Até que o vetor esteja completamente ordenado
void bubbleSort(int *vetor, int n){
	int i, aux, continua, tamanho = n;
	do {
		continua = 0;

		for(i = 0; i < (tamanho-1); i++){
			if(vetor[i] > vetor[i+1]){
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
				continua = 1;// Essa variável indica que houve troca na iteração, caso não haja, a função é finalizada ao sair do do-while, pois indica que o vetor está ordenado
			}
		}
		tamanho--; //A cada iteração o maior elemento é jogado pro final, descartando a necessidade  de compará-los novamente

	} while(continua != 0);
}

void exibirVetor(int *vetor, int n){
	for(int i = 0; i < (n); i++){
		printf("%d ", vetor[i]);
	}

}

int main(){
	int vetor[100] = {
    73, 12, 89, 34, 5, 67, 41, 98, 23, 56,
    8, 91, 45, 17, 62, 30, 76, 3, 84, 51,
    29, 70, 14, 95, 38, 6, 81, 47, 22, 64,
    10, 87, 53, 31, 72, 19, 99, 43, 26, 58,
    4, 68, 35, 80, 16, 92, 49, 7, 61, 27,
    85, 39, 74, 11, 96, 54, 20, 63, 32, 78,
    15, 88, 44, 2, 69, 37, 94, 25, 57, 83,
    9, 71, 48, 18, 90, 36, 65, 13, 79, 42,
    55, 21, 86, 33, 60, 1, 77, 24, 93, 40,
    50, 66, 28, 82, 59, 100, 52, 46, 75, 97
};
	int qtd_elementos = (int)(sizeof(vetor)/sizeof(vetor[0])); //typecast para int pois sizeof retorna size_t
	exibirVetor(vetor, qtd_elementos);

	bubbleSort(vetor, qtd_elementos);
	printf("\n");
	exibirVetor(vetor, qtd_elementos);
	

	return 0;
}
