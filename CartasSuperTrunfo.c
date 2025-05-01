#include <stdio.h>

/*
    Programa Super Trunfo de Cidades - Comparação de Cartas

    Este programa cadastra duas cartas com dados de cidades brasileiras,
    calcula a densidade populacional e o PIB per capita de cada uma,
    e compara as duas cartas usando o atributo PIB per capita para
    determinar a carta vencedora.

    Requisitos:
    - Comparação de apenas um atributo numérico escolhido no código.
    - Exibição clara e documentada dos resultados.
*/

int main() {
    // Dados da Carta 1
    char estado1[3] = "SP";
    char codigo1[4] = "A01";
    char nomeCidade1[50] = "São Paulo";
    unsigned long int populacao1 = 12300000;
    float area1 = 1521.11; // em km²
    float pib1 = 760.0;    // em bilhões de reais
    int pontosTuristicos1 = 10;

    // Dados da Carta 2
    char estado2[3] = "RJ";
    char codigo2[4] = "B02";
    char nomeCidade2[50] = "Rio de Janeiro";
    unsigned long int populacao2 = 6710000;
    float area2 = 1182.3;  // em km²
    float pib2 = 364.0;    // em bilhões de reais
    int pontosTuristicos2 = 8;

    // Variáveis para cálculos
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;

    // Cálculo da Densidade Populacional e PIB per Capita da Carta 1
    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1e9) / populacao1;  // Convertendo PIB para reais

    // Cálculo da Densidade Populacional e PIB per Capita da Carta 2
    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1e9) / populacao2;

    // Exibição dos dados calculados
    printf("\n--- DADOS DAS CARTAS ---\n");

    printf("\nCarta 1:\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %lu habitantes\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita1);

    printf("\nCarta 2:\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %lu habitantes\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita2);

    // Comparação - Atributo escolhido: PIB per Capita
    printf("\n--- COMPARAÇÃO DE CARTAS (Atributo: PIB per Capita) ---\n");

    printf("\nCarta 1 - %s (%s): R$ %.2f\n", nomeCidade1, estado1, pibPerCapita1);
    printf("Carta 2 - %s (%s): R$ %.2f\n", nomeCidade2, estado2, pibPerCapita2);

    if (pibPerCapita1 > pibPerCapita2) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if (pibPerCapita2 > pibPerCapita1) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
