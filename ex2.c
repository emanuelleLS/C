//Emanuelle Lino
/*
Fa�a um programa que seja capaz de armazenar os dados de tr�s pessoas: nome, idade,
 peso e altura.
Ao final, o algoritmo deve mostrar, na tela, o nome e a idade da primeira pessoa
 e o peso e altura da �ltima pessoa.
*/


#include <stdio.h>

struct Pessoa
{
    char nome[100];
    int idade;
    float peso;
    float altura;
};

int main()
{
    // Declara��o de tr�s vari�veis do tipo Pessoa
    struct Pessoa pessoas[3];

    // Loop para armazenar os dados de cada pessoa
    for (int i = 0; i < 3; i++)
    {
        printf("Informe o nome da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].nome);
        printf("Informe a idade da pessoa %d: ", i + 1);
        scanf("%d", &pessoas[i].idade);
        printf("Informe o peso da pessoa %d: ", i + 1);
        scanf("%f", &pessoas[i].peso);
        printf("Informe a altura da pessoa %d: ", i + 1);
        scanf("%f", &pessoas[i].altura);
    }

    // Mostra o nome e a idade da primeira pessoa
    printf("\nDados da primeira pessoa:\n");
    printf("Nome: %s\n", pessoas[0].nome);
    printf("Idade: %d\n", pessoas[0].idade);

    // Mostra o peso e altura da �ltima pessoa
    printf("\nDados da �ltima pessoa:\n");
    printf("Peso: %.2f\n", pessoas[2].peso);
    printf("Altura: %.2f\n", pessoas[2].altura);

    return 0;
}

