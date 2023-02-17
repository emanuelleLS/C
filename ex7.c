//Emanuelle Lino
/*
Faça um programa que receba dois arquivos do usuário e crie
um terceiro arquivo com o conteúdo dos dois primeiros juntos
(o conteúdo do primeiro seguido do conteúdo do segundo).
*/
#include <stdio.h>

int main()
{
// Declarando o nome dos três arquivos
    char nome_arquivo1[100];
    char nome_arquivo2[100];
    char nome_arquivo3[100];

// Pedindo ao usuário que digite o nome dos três arquivos
    printf("Digite o nome do primeiro arquivo: ");
    scanf("%s", nome_arquivo1);
    printf("Digite o nome do segundo arquivo: ");
    scanf("%s", nome_arquivo2);
    printf("Digite o nome do terceiro arquivo: ");
    scanf("%s", nome_arquivo3);

// Abrindo os três arquivos, com "r" para os dois primeiros e "w" para o terceiro
    FILE *arquivo1 = fopen(nome_arquivo1, "r");
    FILE *arquivo2 = fopen(nome_arquivo2, "r");
    FILE *arquivo3 = fopen(nome_arquivo3, "w");

// Verificando se algum arquivo não pôde ser aberto
    if (arquivo1 == NULL || arquivo2 == NULL || arquivo3 == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

// Variável que armazenará os caracteres lidos dos arquivos
    char c;

// Copiando o conteúdo do primeiro arquivo para o terceiro arquivo
    while ((c = fgetc(arquivo1)) != EOF)
    {
        fputc(c, arquivo3);
    }

// Copiando o conteúdo do segundo arquivo para o terceiro arquivo
    while ((c = fgetc(arquivo2)) != EOF)
    {
        fputc(c, arquivo3);
    }

// Fechando os três arquivos
    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivo3);

// Informando ao usuário que a operação foi realizada com sucesso
    printf("Arquivos juntados com sucesso!\n");

    return 0;
}
