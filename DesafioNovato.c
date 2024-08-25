#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar uma carta do jogo
typedef struct {
    char estado;            // Estado representado pela letra
    char codigo[4];         // Código da carta (por exemplo, A01)
    char nomeCidade[50];    // Nome da cidade
    int populacao;          // População da cidade
    float area;             // Área em km²
    float pib;              // PIB da cidade
    int numPontosTuristicos; // Número de pontos turísticos
} Carta;

int main() {
    int numCartas;

    // Solicita ao usuário a quantidade de cartas que deseja cadastrar
    printf("Quantas cartas deseja cadastrar? ");
    scanf("%d", &numCartas);
    getchar(); // Limpar o buffer de entrada

    // Aloca memória para as cartas
    Carta *cartas = (Carta *)malloc(numCartas * sizeof(Carta));

    // Coleta os dados para cada carta
    for (int i = 0; i < numCartas; i++) {
        printf("\nCadastro da carta %d:\n", i + 1);

        printf("Estado (letra): ");
        scanf("%c", &cartas[i].estado);
        getchar(); // Limpar o buffer de entrada

        printf("Código da carta (exemplo: A01): ");
        fgets(cartas[i].codigo, sizeof(cartas[i].codigo), stdin);
        cartas[i].codigo[strcspn(cartas[i].codigo, "\n")] = '\0'; // Remove newline

        printf("Nome da cidade: ");
        fgets(cartas[i].nomeCidade, sizeof(cartas[i].nomeCidade), stdin);
        cartas[i].nomeCidade[strcspn(cartas[i].nomeCidade, "\n")] = '\0'; // Remove newline

        printf("População: ");
        scanf("%d", &cartas[i].populacao);

        printf("Área em km²: ");
        scanf("%f", &cartas[i].area);

        printf("PIB: ");
        scanf("%f", &cartas[i].pib);

        printf("Número de pontos turísticos: ");
        scanf("%d", &cartas[i].numPontosTuristicos);

        getchar(); // Limpar o buffer de entrada
    }

    // Exibe os dados das cartas cadastradas
    printf("\nCartas cadastradas:\n");
    for (int i = 0; i < numCartas; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("Estado: %c\n", cartas[i].estado);
        printf("Código: %s\n", cartas[i].codigo);
        printf("Nome da Cidade: %s\n", cartas[i].nomeCidade);
        printf("População: %d\n", cartas[i].populacao);
        printf("Área em km²: %.2f\n", cartas[i].area);
        printf("PIB: %.2f\n", cartas[i].pib);
        printf("Pontos Turísticos: %d\n", cartas[i].numPontosTuristicos);
    }

    // Libera a memória alocada
    free(cartas);

    return 0;
}
