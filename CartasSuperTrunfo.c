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


typedef struct //ficar digitando struct direto é chato
{
    //código da cidade, nome, população, área, PIB, número de pontos turísticos
    /*
    Estado (char)
    Código da carta (char[])
    Nome da cidade (char[])
    População (int)
    Área em km² (float)
    Densidade populacional (float)
    PIB (float)
    PIB per capita (float)
    Número de pontos turísticos (int)
    */
    char pais;// vai de A até H
    char codigo_cidade[4];// 4 cidade por país
    char nome[50];
    unsigned long int populacao;
    float area;
    float densidade_populacional;
    float pib;
    float pib_per_capita;
    int pontos_turisticos;
    float super_poder;
} CartasSuperTrunfo ;

CartasSuperTrunfo baralho[MAX_SIZE];

void printaCarta(CartasSuperTrunfo *carta){
    printf("\n--------------------------------\n");
    printf("Estado: %c\n",carta->codigo_cidade[0]);
    printf("Código da Carta: %s \n",carta->codigo_cidade);
    printf("Nome da Cidade: %s\n",carta->nome);
    printf("População: %lu pessoas\n",carta->populacao);
    printf("Área: %f km²\n",carta->area);
    printf("Densidade populacional: %f pessoas/Km²\n",carta->densidade_populacional);
    printf("PIB: %f bilhões de reais\n",carta->pib);
    printf("PIB per capita: %f bilhões de reais por pessoa\n",carta->pib_per_capita);
    printf("Número de Pontos Turísticos: %d\n",carta->pontos_turisticos);
    printf("Esse é o Super poder (%f)\n",carta->super_poder);
    printf("--------------------------------\n");
}

int procura_carta(CartasSuperTrunfo *baralho,const char *s){
    //retorna o indice no baralho que a carta foi encontrada
    // -1 caso não encontre

    int it = 0;
    while(it < MAX_SIZE){
        if(strcmp(baralho[it].codigo_cidade,s) == 0) return it;
        it++;
    }
    return -1;

}

void printaBaralho(CartasSuperTrunfo *baralho){
    // percorre o baralho e printa as cartas válidas
    int it;//variavel para iterar
    for (it=0;it<MAX_SIZE;it++){
        if (strcmp(baralho[it].codigo_cidade,"") != 0){
            printaCarta(&baralho[it]);
        }
    }
}

void adicionaCarta(CartasSuperTrunfo *carta){

    float acumula = 0.0;
	printf("entre com o código da carta Ex: A1\n");
	scanf("%s",&carta->codigo_cidade[0]);
    printf("entre com o nome da cidade\n");
	scanf("%s",&carta->nome[0]);
    printf("entre com a populacao da cidade de %s.\n",carta->nome);
	scanf("%lu",&carta->populacao);
    acumula += carta->populacao;
    printf("entre com a area da cidade de %s.\n",carta->nome);
	scanf("%f",&carta->area);
    acumula += carta->area;
    printf("entre com o PIB da cidade de %s.\n",carta->nome);
	scanf("%f",&carta->pib);
    acumula += carta->pib;
    printf("entre com a quantidade de pontos turisticos da cidade de %s.\n",carta->nome);
	scanf("%d",&carta->pontos_turisticos);
    acumula += carta->pontos_turisticos;

    //calcula os atributos secundários
    carta->densidade_populacional = carta->populacao/carta->area;
    acumula += 1.0/carta->densidade_populacional;
    carta->pib_per_capita = carta->pib/carta->populacao;
    acumula += carta->pib_per_capita;

    carta->super_poder = acumula;
    
}



CartasSuperTrunfo*  encontraCartaVazia(CartasSuperTrunfo *baralho){
    // vasculha o baralho e retorna um ponteiro para a primeira carta vazia
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

int duelo(CartasSuperTrunfo *baralho,char *player1,char *player2){
    //implementa o duelo entre 2 jogadores

    int numero_da_carta_1 = procura_carta(baralho,player1);
    int numero_da_carta_2 = procura_carta(baralho,player2);


    //se o jogador 1 colocar uma carta inválida o jogador 2 ganha automaticamente
    if(numero_da_carta_1 <0){
        printf("jogador 1 jogou com uma carta inválida!!!!\n");
        return 1;
    }
    //se o jogador 2 colocar uma carta inválida o jogador 1 ganha automaticamente
    if(numero_da_carta_2 <0){
        printf("jogador 2 jogou com uma carta inválida!!!!\n");
        return 0;
    }

    CartasSuperTrunfo carta1 = baralho[numero_da_carta_1];
    CartasSuperTrunfo carta2 = baralho[numero_da_carta_2];

    printf("O jogador 1 escolheu a carta:\n");
    printaCarta(&carta1);
    printf("O jogador 2 escolheu a carta:\n");
    printaCarta(&carta2);

    //agora é escolher o atributo para ser comparado
    int mode;
    printf("agora é escolher o atributo para ser comparado\n");
    printf("1 para comparar a população\n");
    printf("2 para comparar a área\n");
    printf("3 para comparar a densidade populacional\n");
    printf("4 para comparar o PIB\n");
    printf("5 para comparar o PIB per capita\n");
    printf("6 para comparar os pontos turísticos\n");
    printf("7 para comparar o super poder\n");
    scanf("%d",&mode);

    switch (mode)
    {
        case 1:
            if(carta1.populacao>carta2.populacao) return 0;
        return 1;

        case 2:
            if(carta1.area>carta2.area) return 0;
        return 1;

        case 3:
            if(carta1.densidade_populacional>carta2.densidade_populacional) return 0;
        return 1;

        case 4:
            if(carta1.pib>carta2.pib) return 0;
        return 1;

        case 5:
            if(carta1.pib_per_capita>carta2.pib_per_capita) return 0;
        return 1;

        case 6:
            if(carta1.pontos_turisticos>carta2.pontos_turisticos) return 0;
        return 1;

        case 7:
            if(carta1.super_poder>carta2.super_poder) return 0;
        return 1;

        default:
            printf("\nopção inválida!!!\n");
    }
    

}

int main() {

	//para evitar UB tem que iniciar a variável baralho
	int it;//variavel para iterar
	for (it=0;it<MAX_SIZE;it++){
		strcpy(baralho[it].codigo_cidade,"");//o que vai controlar se uma carta pode ser escrita ou não é o codigo dela.
	}
	
	
    int mode = -1; // tem que iniciar com -1 pra entrar no loop :)

    while (mode){
        printf("entre com o modo de jogo\n");
        printf("1 para adicionar cartas\n");
        printf("2 para jogar\n");
        printf("3 para salvar as cartas(não implementado)\n");
        printf("4 para carregar as cartas salvas(não implementado)\n");
        printf("5 para exibir as cartas\n");
        printf("E digite 0 para sair.\n");
        scanf("%d",&mode);
    
        char carta1[4];
        char carta2[4];

        switch (mode){
            case 1:
            if(encontraCartaVazia(baralho) != NULL){
                adicionaCarta(encontraCartaVazia(baralho));
            }
            break;
        case 2:
            printf("entre com a carta escolhida pelo jogador 1:\n");
            scanf("%s",carta1);
            printf("entre com a carta escolhida pelo jogador 2:\n");
            scanf("%s",carta2);
            if(duelo(baralho,carta1,carta2) == 0){
                printf("Jogador 1 ganhou!!!\n\n");
                break;
            }
            printf("Jogador 2 ganhou!!!\n\n");
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