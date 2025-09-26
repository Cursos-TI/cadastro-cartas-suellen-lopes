#include <stdio.h>
#include <string.h>

//--- Estrutura (struct) para representar uma carta de Super Trunfo ---
// Agrupa todas as propriedades de uma cidade em um unico tipo de dado.
struct CartaSuperTrunfo{
    char Estado;
    char Codigo_carta[5]; // Ex: "A01", "B03" (4 caracteres + 1 para o terminador '\0')
    char Nome_Cidade[50]; // Tamanho suficiente para o nome da cidade
    int populacao; // População (número inteiro)
    float area_km2; // Área em km² 
    float pib; // PIB em bilhões de reais
    int num_pontos_turisticos;
    /* data */
};
// Prototipos das funcoes
// Funcoes para ler e exibir os dados e cálculo de estatísticas.
void lerDadosCarta(struct CartaSuperTrunfo *Carta);
void exibirDadosCarta(const struct CartaSuperTrunfo *carta);
void calcularEExibirEstatisticas(const struct CartaSuperTrunfo *carta);



int main(){
    // Declara duas variaveis do tipo CartaSuperTrunfo
    struct CartaSuperTrunfo carta1, carta2;

    //Leitura dos dados da primeira carta
    printf("\n Cadastro da Primeira Carta\n");
    lerDadosCarta(&carta1);

    //Leitura dos dados da segunda carta
    printf("\n Cadastro da Segunda Carta\n");
    lerDadosCarta(&carta2);
                                                                    
    //Exibicao dos dados cadastrados e cálculos das estatísticas
    printf("\n Dados das Cartas Cadastradas\n");
    
    printf("\nCarta 1:\n");
    exibirDadosCarta(&carta1);
    calcularEExibirEstatisticas(&carta1); // Chama a função para calcular e exibir as estatísticas 
                                                                                         
    printf("\nCarta 2:\n");
    exibirDadosCarta(&carta2);
    calcularEExibirEstatisticas(&carta2); // Chama a função para calcular e exibir as estatísticas

    return 0;

}
// Implementacao da funcao para ler os dados de uma carta
// Recebe um ponteiro para a struct para que a funcao possa modificar seus valores.
void lerDadosCarta(struct CartaSuperTrunfo *carta){
                                                                                                         
    printf("Estado (A a H): ");
    scanf(" %c", &carta->Estado);

    printf("Código da Carta (EX: A01): ");
    scanf("%s", carta-> Codigo_carta);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta-> Nome_Cidade);

    printf("Populacao: ");
    scanf("%d", &carta->populacao);

    printf("Area (km2): ");
    scanf("%f", &carta->area_km2);

    printf(" PIB (em bilhões de R$): ");
    scanf("%f", &carta->pib);

    printf("Numero de Pontos Turisticos ");
    scanf("%d", &carta->num_pontos_turisticos);

     /* data */
}


// Implementacao da funcao para exibir os dados de uma carta
// Recebe um ponteiro constante para a struct para garantir que os dados nao serao alterados.
void exibirDadosCarta(const struct CartaSuperTrunfo *carta){

    printf(" Estado: %c\n", carta->Estado);
    printf(" Codigo: %s\n", carta->Codigo_carta);
    printf(" Nome da Cidade: %s\n", carta->Nome_Cidade);
    printf(" Populacao: %d\n", carta->populacao);
    printf(" Area: %.2f km²\n", carta->area_km2);
    printf(" PIB: %.2f bilhoes de reais\n", carta->pib);
    printf(" Numero de Pontos Turisticos: %d\n", carta->num_pontos_turisticos);                                                                                                                                                                                             
/* data */
}

// NOVA FUNÇÃO: Calcula e exibe a Densidade Populacional e o PIB per Capita
void calcularEExibirEstatisticas(const struct CartaSuperTrunfo *carta){

    float densidade_populacional;
    float pib_per_capita;

    // 1. Cálculo da Densidade Populacional: Populacao / Area (hab/km²)
    densidade_populacional = (float)carta->populacao / carta->area_km2;

     //2. Cálculo do PIB per Capita: (PIB * 1.000.000.000) / Populacao (R$)
     //O PIB foi lido em "bilhões de reais", entao multiplicamos por 1e9 para ter o valor total em reais.
     
    pib_per_capita = (carta->pib * 1000000000.0f) / carta->populacao;

     // 3. Exibição dos Resultados (Formatados com duas casas decimais)
    printf(" Densidade Populacional: %.2f hab/km²\n", densidade_populacional);
    printf(" PIB per Capita: %.2f reais\n", pib_per_capita);

/* data */  
}




