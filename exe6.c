//Emanuelle Lino
/*
Fa�a um programa que realize a leitura dos seguintes dados relativos a
um conjunto de alunos: Matricula, Nome, C�digo da Disciplina, Nota1 e Nota2.
Considere uma turma de at� 10 alunos. Ap�s ler todos os dados digitados, e depois de armazen�-los em
um vetor de estrutura, exibir na tela a listagem final dos alunos com as suas respectivas m�dias finais
 (use uma m�dia ponderada: Nota1 com peso=1.0 e Nota2 com peso=2.0).

*/
#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 10

// Define a estrutura de dados "Aluno" com informa��es relevantes
struct Aluno
{
    int matricula;
    char nome[100]; // Armazena o nome do aluno como uma string de at� 100 caracteres
    int codigo_disciplina;
    float nota1;
    float nota2;
};

int main()
{
    struct Aluno alunos[MAX_ALUNOS];
    int num_alunos;

// Obt�m o n�mero de alunos na turma
    printf("Digite o numero de alunos na turma: ");
    scanf("%d", &num_alunos);

// L� os dados dos alunos
    for (int i = 0; i < num_alunos; i++)
    {
        printf("\nDados do %do aluno\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Nome: ");
        scanf("%s", alunos[i].nome);
        printf("Codigo da Disciplina: ");
        scanf("%d", &alunos[i].codigo_disciplina);
        printf("Nota1: ");
        scanf("%f", &alunos[i].nota1);
        printf("Nota2: ");
        scanf("%f", &alunos[i].nota2);
    }

// Imprime a listagem final dos alunos com suas informa��es relevantes
    printf("\nListagem final dos alunos:\n");
    for (int i = 0; i < num_alunos; i++)
    {
        float media = (alunos[i].nota1 + 2 * alunos[i].nota2) / 3;
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Codigo da Disciplina: %d\n", alunos[i].codigo_disciplina);
        printf("Media Final: %.2f\n", media);
    }

    return 0;
}
