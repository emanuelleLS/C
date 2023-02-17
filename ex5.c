//Emanuelle Lino
/*
Crie uma estrutura representando os alunos de um determinado curso.
 A estrutura deve conter a matrícula do aluno, nome, nota da primeira prova, nota da segunda prova e nota da terceira prova.
Permita ao usuário entrar com os dados de 5 alunos.
Encontre o aluno com maior nota da primeira prova.
Encontre o aluno com maior média geral.
Encontre o aluno com menor média geral
Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para aprovação.
*/


#include <stdio.h>
#include <string.h>

#define MAX 5

struct Aluno
{
    int matricula;
    char nome[50];
    float prova1, prova2, prova3;
};

int main()
{
    struct Aluno alunos[MAX];
    int i, maior_nota_prova1 = 0, maior_media = 0, menor_media = 9999999;

    // Recebimento de dados
    for (i = 0; i < MAX; i++)
    {
        printf("\nEntre com os dados do %dº aluno\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Nome: ");
        scanf("%s", alunos[i].nome);
        printf("Nota da primeira prova: ");
        scanf("%f", &alunos[i].prova1);
        printf("Nota da segunda prova: ");
        scanf("%f", &alunos[i].prova2);
        printf("Nota da terceira prova: ");
        scanf("%f", &alunos[i].prova3);

        // Verificação do aluno com maior nota na primeira prova
        if (alunos[i].prova1 > alunos[maior_nota_prova1].prova1)
        {
            maior_nota_prova1 = i;
        }

        // Verificação do aluno com maior média geral
        float media = (alunos[i].prova1 + alunos[i].prova2 + alunos[i].prova3) / 3;
        if (media > alunos[maior_media].prova1)
        {
            maior_media = i;
        }

        // Verificação do aluno com menor média geral
        if (media < alunos[menor_media].prova1)
        {
            menor_media = i;
        }
    }

    // Exibição dos resultados
    printf("\nAluno com maior nota na primeira prova: %s\n", alunos[maior_nota_prova1].nome);
    printf("Aluno com maior media geral: %s\n", alunos[maior_media].nome);
    printf("Aluno com menor media geral: %s\n", alunos[menor_media].nome);
    printf("\nResultado de cada aluno\n");
    for (i = 0; i < MAX; i++)
    {
        float media = (alunos[i].prova1 + alunos[i].prova2 + alunos[i].prova3) / 3;
        printf("%s - ", alunos[i].nome);
        if (media >= 6)
        {
            printf("Aprovado");

        }
    }
    return 0;
}
