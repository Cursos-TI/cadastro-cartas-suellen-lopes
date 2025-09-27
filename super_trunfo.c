#include <stdio.h>
#include <string.h>

// Estrutura (struct) para representar uma carta de Super Trunfo
// Agrupa todas as propriedades de uma cidade em um unico tipo de dado.
struct CartaSuperTrunfo{
    char Estado;
    char Codigo_carta[5]; // Ex: "A01", "B03" (4 caracteres + 1 para o terminador '\0')
    char Nome_Cidade[50]; // Tamanho suficiente para o nome da cidade
    //int populacao; // População (número inteiro)
    unsigned long int populacao; // Atualizado: para acomodar grandes números
    float area_km2; // Área em km² 
    float pib; // PIB em bilhões de reais
    int num_pontos_turisticos;
    
    // Atributos calculados
    float densidade_populacional; // hab/km²
    float pib_per_capita;
    float super_poder; // Soma dos atributos ponderados
};


// Prototipos das funcoes
// Funcoes para ler e exibir os dados e cálculo de estatísticas.
void lerDadosCarta(struct CartaSuperTrunfo *Carta);
void exibirDadosCarta(const struct CartaSuperTrunfo *carta);
void calcularAtributosEstatisticos(struct CartaSuperTrunfo *carta); // Atualizada
void compararCartas(const struct CartaSuperTrunfo *carta1, const struct CartaSuperTrunfo *carta2);


int main(){
    // Declara duas variaveis do tipo CartaSuperTrunfo
    struct CartaSuperTrunfo carta1, carta2;

    //Leitura dos dados da primeira carta
    printf("\n Cadastro da Primeira Carta\n");
    lerDadosCarta(&carta1);

    //Leitura dos dados da segunda carta
    printf("\n Cadastro da Segunda Carta\n");
    lerDadosCarta(&carta2);

    // Calculo de todos os atributos estatísticos para ambas as cartas
    calcularAtributosEstatisticos(&carta1);
    calcularAtributosEstatisticos(&carta2);
                                                                    
    //Exibicao dos dados cadastrados e cálculos
    printf("\n\n Dados das Cartas Cadastradas\n");
    
    printf("\nCarta 1:\n");
    exibirDadosCarta(&carta1);
    //calcularEExibirEstatisticas(&carta1); // Chama a função para calcular e exibir as estatísticas 
                                                                                         
    printf("\nCarta 2:\n");
    exibirDadosCarta(&carta2);
    //calcularEExibirEstatisticas(&carta2); // Chama a função para calcular e exibir as estatísticas

    // Desafio final: Comparação das cartas
    printf("\n\n =======================\n");
    printf("|| Batalha de Cartas Super Trunfo ||\n");
    printf("============================\n");
    compararCartas(&carta1, &carta2);

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
    scanf(" %49[^\n]", carta-> Nome_Cidade);

    printf("Populacao: (unsigned long int): ");
    scanf("%lu", &carta->populacao); // lu para unsigned long int

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
    printf(" Populacao: %lu\n", carta->populacao);
    printf(" Area: %.2f km²\n", carta->area_km2);
    printf(" PIB: %.2f bilhões de reais\n", carta->pib);
    printf(" Pontos Turísticos: %d\n", carta->num_pontos_turisticos);
    printf(" Densidade Populacional: %.2f hab/km²\n", carta->densidade_populacional);
    printf(" PIB per Capita: R$ %.2f\n", carta->pib_per_capita);
    printf(" Super Poder: %.4f\n", carta->super_poder);                                                                                                                                                                                             
/* data */
}

// NOVA FUNÇÃO: Calcula e exibe a Densidade Populacional, PIB per Capita e o Super Poder
void calcularAtributosEstatisticos(const struct CartaSuperTrunfo *carta){
    // Calculo da Densidade Populacional: População / Área (hab/km²)
    // Conversão de (unsigned long int) para (float)
    if (carta->area_km2 . 0){
        carta-.densidade_populacional = (float)carta->populacao / carta->area_km2;
    } else {
        carta->densidade_populacional = 0.0f;
    }

    // Calculo do PIB per Capita: (PIB * 1.000.000.000) / População ( R$ )
    // PIB lido em bilhões, por isso a multiplicação por 1e9 (1,000,000,000.0f)
    if(cvarta->populacao > 0){
        carta->pib_per_capita = (carta->pib * 1000000000.0f) / carta->populacao;
    } else {
        carta->pib_per_capita = 0.0f;
    }

    // Calculo do Super Poder
    // Soma de: População ( como float), Área, PIB, Pontos Turísticos ( como float)
    // PIB per Capita e Inverso da Densidade ( 1.0f / densidade)

    float inverso_densidade = 0.0f;
    if (carta->densidade_populacional > 0) {
        // Quanto menor a Densidade maior o poder ( 1/X )
        inverso_densidade = 1.0f / carta->densidade_populacional;
    }

    //Conversão de tipos! Todos os termos devem ser somados como float
    carta->super_poder = (float)carta->populacao + 
                         carta->area_km2 + 
                         carta->pib + 
                         (float)carta->num_pontos_turisticos + 
                         carta->pib_per_capita + 
                         inverso_densidade;
}

// Implementação da função para comparar as cartas e exibir o resultado
void compararCartas(const struct CartaSuperTrunfo *c1, const struct CartaSuperTrunfo *c2) {
    int resultado;

    // População ( Maior vence)
    resultado = ((long double)c1->populacao > (long double)c2->populacao);
    printf(" População: Carta %d venceu (%d)\n", resultado ? 1: 2, resultado);

    // Área (Maior Vence)
    resultado = (c1->area_km2 > c2->area_km2);
    printf(" Área: Carta %d venceu (%d)\n", resultado ? 1: 2, resultado);

    // PIB (Maior Vence)
    resultado = (c1->pib > c2->pib);
    printf(" PIB: Carta %d venceu (%d)\n", resultado ? 1: 2, resultado);

     // Pontos Turísticos (Maior vence)
    resultado = (c1->num_pontos_turisticos > c2->num_pontos_turisticos);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);

    // Densidade Populacional (Menor vence)
    // A logica e invertida: C1 vence se C1 for MENOR que C2
    resultado = (c1->densidade_populacional < c2->densidade_populacional);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);
    
    // PIB per Capita (Maior vence)
    resultado = (c1->pib_per_capita > c2->pib_per_capita);
    printf("PIB per Capita: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);

    // Super Poder (Maior vence)
    resultado = (c1->super_poder > c2->super_poder);
    printf("Super Poder: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);
}
    



