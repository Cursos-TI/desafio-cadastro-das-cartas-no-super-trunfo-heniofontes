#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char nome[50];
    unsigned long populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
} Pais;

void exibirMenu(int atributoExcluido) {
    printf("\nEscolha o %s atributo para comparar:\n", atributoExcluido == 0 ? "primeiro" : "segundo");
    if (atributoExcluido != 1) printf("1 - População\n");
    if (atributoExcluido != 2) printf("2 - Área\n");
    if (atributoExcluido != 3) printf("3 - PIB\n");
    if (atributoExcluido != 4) printf("4 - Pontos Turísticos\n");
    if (atributoExcluido != 5) printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção: ");
}

float obterAtributo(Pais pais, int atributo) {
    switch(atributo) {
        case 1: return (float)pais.populacao;
        case 2: return pais.area;
        case 3: return pais.pib;
        case 4: return (float)pais.pontosTuristicos;
        case 5: return pais.densidade;
        default: return 0;
    }
}

const char* nomeAtributo(int atributo) {
    switch(atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "";
    }
}

int main() {
    // Inicialização dos países
    Pais brasil = {"Brasil", 213000000, 8515767.0, 14449.0, 25, 0};
    Pais argentina = {"Argentina", 45195774, 2780400.0, 487.2, 18, 0};
    
    // Calcular densidades
    brasil.densidade = (float)brasil.populacao / brasil.area;
    argentina.densidade = (float)argentina.populacao / argentina.area;

    int opcao1, opcao2;
    float somaBrasil = 0, somaArgentina = 0;
    int vitoriasBrasil = 0, vitoriasArgentina = 0;

    printf("=== SUPER TRUNFO - COMPARAÇÃO COM DOIS ATRIBUTOS ===\n");
    printf("Comparando: %s vs %s\n\n", brasil.nome, argentina.nome);

    // Primeira escolha de atributo
    exibirMenu(0);
    scanf("%d", &opcao1);

    // Validação da primeira opção
    if (opcao1 < 1 || opcao1 > 5) {
        printf("Opção inválida. Execute novamente.\n");
        return 1;
    }

    // Segunda escolha de atributo (excluindo o já escolhido)
    exibirMenu(opcao1);
    scanf("%d", &opcao2);

    // Validação da segunda opção
    if (opcao2 < 1 || opcao2 > 5 || opcao2 == opcao1) {
        printf("Opção inválida ou repetida. Execute novamente.\n");
        return 1;
    }

    printf("\n=== RESULTADOS ===\n");

    // Comparação do primeiro atributo
    printf("\nAtributo 1: %s\n", nomeAtributo(opcao1));
    float atributo1Brasil = obterAtributo(brasil, opcao1);
    float atributo1Argentina = obterAtributo(argentina, opcao1);
    
    printf("%s: %.2f\n", brasil.nome, atributo1Brasil);
    printf("%s: %.2f\n", argentina.nome, atributo1Argentina);

    if (opcao1 == 5) { // Densidade (menor vence)
        if (atributo1Brasil < atributo1Argentina) {
            printf("%s venceu neste atributo!\n", brasil.nome);
            vitoriasBrasil++;
        } else if (atributo1Argentina < atributo1Brasil) {
            printf("%s venceu neste atributo!\n", argentina.nome);
            vitoriasArgentina++;
        } else {
            printf("Empate neste atributo!\n");
        }
    } else { // Demais atributos (maior vence)
        if (atributo1Brasil > atributo1Argentina) {
            printf("%s venceu neste atributo!\n", brasil.nome);
            vitoriasBrasil++;
        } else if (atributo1Argentina > atributo1Brasil) {
            printf("%s venceu neste atributo!\n", argentina.nome);
            vitoriasArgentina++;
        } else {
            printf("Empate neste atributo!\n");
        }
    }

    somaBrasil += atributo1Brasil;
    somaArgentina += atributo1Argentina;

    // Comparação do segundo atributo
    printf("\nAtributo 2: %s\n", nomeAtributo(opcao2));
    float atributo2Brasil = obterAtributo(brasil, opcao2);
    float atributo2Argentina = obterAtributo(argentina, opcao2);
    
    printf("%s: %.2f\n", brasil.nome, atributo2Brasil);
    printf("%s: %.2f\n", argentina.nome, atributo2Argentina);

    if (opcao2 == 5) { // Densidade (menor vence)
        if (atributo2Brasil < atributo2Argentina) {
            printf("%s venceu neste atributo!\n", brasil.nome);
            vitoriasBrasil++;
        } else if (atributo2Argentina < atributo2Brasil) {
            printf("%s venceu neste atributo!\n", argentina.nome);
            vitoriasArgentina++;
        } else {
            printf("Empate neste atributo!\n");
        }
    } else { // Demais atributos (maior vence)
        if (atributo2Brasil > atributo2Argentina) {
            printf("%s venceu neste atributo!\n", brasil.nome);
            vitoriasBrasil++;
        } else if (atributo2Argentina > atributo2Brasil) {
            printf("%s venceu neste atributo!\n", argentina.nome);
            vitoriasArgentina++;
        } else {
            printf("Empate neste atributo!\n");
        }
    }

    somaBrasil += atributo2Brasil;
    somaArgentina += atributo2Argentina;

    // Resultado final
    printf("\n=== RESULTADO FINAL ===\n");
    printf("Soma dos atributos para %s: %.2f\n", brasil.nome, somaBrasil);
    printf("Soma dos atributos para %s: %.2f\n", argentina.nome, somaArgentina);

    if (vitoriasBrasil > vitoriasArgentina) {
        printf("\n%s venceu a rodada por %d a %d!\n", brasil.nome, vitoriasBrasil, vitoriasArgentina);
    } else if (vitoriasArgentina > vitoriasBrasil) {
        printf("\n%s venceu a rodada por %d a %d!\n", argentina.nome, vitoriasArgentina, vitoriasBrasil);
    } else if (somaBrasil > somaArgentina) {
        printf("\nEmpate nos atributos, mas %s venceu pela soma maior!\n", brasil.nome);
    } else if (somaArgentina > somaBrasil) {
        printf("\nEmpate nos atributos, mas %s venceu pela soma maior!\n", argentina.nome);
    } else {
        printf("\nEmpate total!\n");
    }

    return 0;
}
