#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

#define MAX_SIZE 100


typedef struct 
{
    //código da cidade, nome, população, área, PIB, número de pontos turísticos
    /*
    Estado (char)
    Código da carta (char[])
    Nome da cidade (char[])
    População (int)
    Área em km² (float)
    PIB (float)
    Número de pontos turísticos (int)
    */
    char pais;// vai de A até H
    char codigo_cidade[3];// 4 cidade por país
    char nome[50];
    int populacao;
    float area;
    float densidade_populacional;
    float pib;
    float pib_per_capita;
    int pontos_turisticos;
} CartasSuperTrunfo ;

CartasSuperTrunfo baralho[MAX_SIZE];

void printaCarta(CartasSuperTrunfo *carta){
    printf("\n--------------------------------\n");
    printf("Estado: %c\n",carta->codigo_cidade[0]);
    printf("Código da Carta: %s \n",carta->codigo_cidade);
    printf("Nome da Cidade: %s\n",carta->nome);
    printf("População: %d pessoas\n",carta->populacao);
    printf("Área: %f km²\n",carta->area);
    printf("Densidade populacional: %f pessoas/Km²",carta->densidade_populacional);
    printf("PIB: %f bilhões de reais\n",carta->pib);
    printf("PIB per capita: %f bilhões de reais por pessoa\n",carta->pib_per_capita);
    printf("Número de Pontos Turísticos: %d\n",carta->pontos_turisticos);
    printf("--------------------------------\n");
}

void printaBaralho(CartasSuperTrunfo *baralho){
    int it;//variavel para iterar
    for (it=0;it<MAX_SIZE;it++){
        if (strcmp(baralho[it].codigo_cidade,"") != 0){
            printaCarta(&baralho[it]);
        }
    }
}

void adicionaCarta(CartasSuperTrunfo *carta){
	printf("entre com o código da carta Ex: A1\n");
	scanf("%s",&carta->codigo_cidade);
    printf("\nentre com o nome da cidade\n");
	scanf("%s",&carta->nome);
    printf("\nentre com a populacao da cidade de %s.\n",carta->nome);
	scanf("%d",&carta->populacao);
    printf("\nentre com a area da cidade de %s.\n",carta->nome);
	scanf("%f",&carta->area);
    printf("entre com o PIB da cidade de %s.\n",carta->nome);
	scanf("%f",&carta->pib);
    printf("entre com a quantidade de pontos turisticos da cidade de %s.\n",carta->nome);
	scanf("%d",&carta->pontos_turisticos);

    //calcula os atributos secundários
    carta->densidade_populacional = carta->populacao/carta->area;
    carta->pib_per_capita = carta->pib/carta->populacao;
    
}

CartasSuperTrunfo*  encontraCartaVazia(CartasSuperTrunfo *baralho){
    
    int it;//variavel para iterar
    // Se encontrar uma carta vazia, retorna a mesma.
    for (it=0;it<MAX_SIZE;it++){
        if (strcmp(baralho[it].codigo_cidade,"") == 0){
            return &baralho[it];
        }
    }
    // Se nenhuma carta vazia foi encontrada, retorna NULL.
    return NULL;
    
}



int main() {

	//para evitar UB tem que iniciar a variável baralho
	int it;//variavel para iterar
	for (it=0;it<MAX_SIZE;it++){
		strcpy(baralho[it].codigo_cidade,"");//o que vai controlar se uma carte pode ser escrita ou não é o codigo.
	}
	
	
    int mode = 0;

    while (mode){
        printf("entre com o modo\n1 para adicionar cartas\n");
        printf("2 para jogar (não implementado)\n");
        printf("3 para salvar as cartas(não implementado)\n");
        printf("4 para carregar as cartas salvas(não implementado)\n");
        printf("5 para exibir as cartas\n");
        printf("E digite 0 para sair.\n");
        scanf("%d",&mode);
    

        switch (mode){
            case 1:
            if(encontraCartaVazia(baralho) != NULL){
                adicionaCarta(encontraCartaVazia(baralho));
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            printaBaralho(baralho);
            break;
        case 0:
            break;
        default:
            break;
        }
    }

    
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    return 0;
}