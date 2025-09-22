#include <stdio.h>
#include <string.h>

struct CartaSuperTrunfo{
    char Estado;
    char Codigo_carta[5];
    char Nome_Cidade[50];
    int populacao;
    float area_km2;
    float pib;
    int num_pontos_turisticos;
    /* data */
};

void lerDadosCarta(struct CartaSuperTrunfo *Carta);
void exibirDadosCarta(const struct CartaSuperTrunfo *carta);

int main(){
    struct CartaSuperTrunfo carta1, carta2;

    printf("\n---Cadastro da Primeira Carta---\n");
    lerDadosCarta(&carta1);

    printf("\n---Cadastro da Segunda Carta---\n");
    lerDadosCarta(&carta2);

    printf("\n--- Dados das Cartas Cadastradas---\n");
    printf("\nCarta 1:\n");
    exibirDadosCarta(&carta1);

    printf("\nCarta 2:\n");
    exibirDadosCarta(&carta2);

    return 0;

}

void lerDadosCarta(struct CartaSuperTrunfo *carta){
    
    printf("Estado (A a H): ");
    scanf(" %c", &carta->Estado);

    printf("Código da Carta (EX: A01): ");
    scanf("%s", carta-> Codigo_carta);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta-> Nome_Cidade);

    printf("Populacao: ");
    scanf("%s", &carta->populacao);

    printf("Area (km2): ");
    scanf("%f", &carta->area_km2);

    printf("Numero de Pontos Turisticos ");
    scanf("%d", &carta->num_pontos_turisticos);
    /* data */
};


void exibirDadosCarta(const struct CartaSuperTrunfo *carta){

    printf(" Estado: %c\n", carta->Estado);
    printf(" Codigo: %s\n", carta->Codigo_carta);
    printf(" Nome da Cidade: %s\n", carta->Nome_Cidade);
    printf(" Populacao: %d\n", carta->populacao);
    printf(" Area: %.2f km²\n", carta->area_km2);
    printf(" PIB:%.2f bilhoes de reais\n", carta->pib);
    printf(" Numero de Pontos Turisticos: %d\n", carta->num_pontos_turisticos);
    /* data */
};