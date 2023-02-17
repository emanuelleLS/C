//Emanuelle Lino
/*
Fa�a um programa que receba dois arquivos do usu�rio e crie
um terceiro arquivo com o conte�do dos dois primeiros juntos
(o conte�do do primeiro seguido do conte�do do segundo).
*/
#include <stdio.h>

int main()
{
// Declarando o nome dos tr�s arquivos
    char nome_arquivo1[100];
    char nome_arquivo2[100];
    char nome_arquivo3[100];

// Pedindo ao usu�rio que digite o nome dos tr�s arquivos
    printf("Digite o nome do primeiro arquivo: ");
    scanf("%s", nome_arquivo1);
    printf("Digite o nome do segundo arquivo: ");
    scanf("%s", nome_arquivo2);
    printf("Digite o nome do terceiro arquivo: ");
    scanf("%s", nome_arquivo3);

// Abrindo os tr�s arquivos, com "r" para os dois primeiros e "w" para o terceiro
    FILE *arquivo1 = fopen(nome_arquivo1, "r");
    FILE *arquivo2 = fopen(nome_arquivo2, "r");
    FILE *arquivo3 = fopen(nome_arquivo3, "w");

// Verificando se algum arquivo n�o p�de ser aberto
    if (arquivo1 == NULL || arquivo2 == NULL || arquivo3 == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

// Vari�vel que armazenar� os caracteres lidos dos arquivos
    char c;

// Copiando o conte�do do primeiro arquivo para o terceiro arquivo
    while ((c = fgetc(arquivo1)) != EOF)
    {
        fputc(c, arquivo3);
    }

// Copiando o conte�do do segundo arquivo para o terceiro arquivo
    while ((c = fgetc(arquivo2)) != EOF)
    {
        fputc(c, arquivo3);
    }

// Fechando os tr�s arquivos
    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivo3);

// Informando ao usu�rio que a opera��o foi realizada com sucesso
    printf("Arquivos juntados com sucesso!\n");

    return 0;
}
