#include <stdio.h>
#include <string.h>

//--- Estrutura (struct) para representar uma carta de Super Trunfo ---
// Agrupa todas as propriedades de uma cidade em um unico tipo de dado.
struct CartaSuperTrunfo{
    char Estado;
    char Codigo_carta[5]; // Ex: "A01", "B03" (4 caracteres + 1 para o terminador '\0')
    char Nome_Cidade[50]; // Tamanho suficiente para o nome da cidade
    int populacao;
    float area_km2;
    float pib;
    int num_pontos_turisticos;
    /* data */
};

//--- Prototipos das funcoes ---
// Funcoes para ler e exibir os dados, tornando o codigo mais modular e organizado.
void lerDadosCarta(struct CartaSuperTrunfo *Carta);
void exibirDadosCarta(const struct CartaSuperTrunfo *carta);

int main(){
    // Declara duas variaveis do tipo CartaSuperTrunfo
    struct CartaSuperTrunfo carta1, carta2;

    //--- Leitura dos dados da primeira carta ---
    printf("\n---Cadastro da Primeira Carta---\n");
    lerDadosCarta(&carta1);

    //--- Leitura dos dados da segunda carta ---
    printf("\n---Cadastro da Segunda Carta---\n");
    lerDadosCarta(&carta2);
    
     //--- Exibicao dos dados cadastrados ---
    printf("\n--- Dados das Cartas Cadastradas---\n");
    printf("\nCarta 1:\n");
    exibirDadosCarta(&carta1);
    
    printf("\nCarta 2:\n");
    exibirDadosCarta(&carta2);

    return 0;

}
//--- Implementacao da funcao para ler os dados de uma carta ---
// Recebe um ponteiro para a struct para que a funcao possa modificar seus valores.
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

//--- Implementacao da funcao para exibir os dados de uma carta ---
// Recebe um ponteiro constante para a struct para garantir que os dados nao serao alterados.
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