
//Emanuelle Lino

/*
Faça um programa que seja capaz de armazenar os dados de uma pessoa: nome, idade, peso e altura.
 Seu programa deve ser capaz de armazenar 5 pessoas. Ao final dos cadastros, o seu programa deve imprimir,
 na tela, todas as informações de todas as pessoas.
Seu programa deve mostrar, também, o nome da pessoa mais magra,
nome da pessoa mais baixa e a média das idades de todas as pessoas.*/
#include <stdio.h>
#include <string.h>

#define MAX 5


//Criação da estrutura "Pessoa" com quatro campos: nome, idade, peso e altura
struct Pessoa
{
    char nome[50];
    int idade;
    float peso;
    float altura;
};

int main()
{
    //Declaração de um vetor de estrutura "Pessoa" com tamanho máximo de 5
    struct Pessoa pessoas[MAX];
    int i;
    float media_idade = 0;
    float peso_minimo = 999999; //Inicializa com um valor alto para garantir que o primeiro valor lido será menor
    float altura_minima = 999999;
    int pessoa_mais_magra = 0;
    int pessoa_mais_baixa = 0;

//para ler as informações de cada uma das 5 pessoas
    for (i = 0; i < MAX; i++)
    {
        printf("Informe o nome da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].nome);
        printf("Informe a idade da pessoa %d: ", i + 1);
        scanf("%d", &pessoas[i].idade);
        printf("Informe o peso da pessoa %d: ", i + 1);
        scanf("%f", &pessoas[i].peso);
        printf("Informe a altura da pessoa %d: ", i + 1);
        scanf("%f", &pessoas[i].altura);

        //Verifica se o peso da pessoa atual é menor que o peso mínimo atual
        if (pessoas[i].peso < peso_minimo)
        {
            peso_minimo = pessoas[i].peso;
            pessoa_mais_magra = i;
        }
        if (pessoas[i].altura < altura_minima)
        {
            altura_minima = pessoas[i].altura;
            pessoa_mais_baixa = i;
        }
        media_idade += pessoas[i].idade;
    }

    media_idade /= MAX;

    printf("\nDados de todas as pessoas:\n");
    for (i = 0; i < MAX; i++)
    {
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Peso: %.2f\n", pessoas[i].peso);
        printf("Altura: %.2f\n", pessoas[i].altura);
        printf("\n");
    }

    printf("Nome da pessoa mais magra: %s\n", pessoas[pessoa_mais_magra].nome);
    printf("Nome da pessoa mais baixa: %s\n", pessoas[pessoa_mais_baixa].nome);
    printf("Media das idades: %.2f\n", media_idade);

    return 0;
}
