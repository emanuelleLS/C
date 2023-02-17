//Emanuelle Lino
/*
Fa�a um programa em C que l� 5 frases de,
no m�ximo, 50 caracteres cada uma e armazene-as em um arquivo.
Mas, antes de gravar cada frase no arquivo, � necess�rio converter todas as suas letras para mai�sculas.
O nome do arquivo ser� fornecido, via teclado, pelo usu�rio.
A fun��o que converte mai�scula para min�scula � o toupper().
A seguir, feche o arquivo e reabra para leitura exibindo todas as frases convertidas.
Como cada texto pode ter tamanho diferente, ser� necess�rio gravar antes de cada frase o tamanho do texto a ser lido,
 logo ser�o necess�rios dois comandos de grava��o e leitura (um para o n�mero inteiro que indica a quantidade de caracteres da frase e outro para a frase com o tamanho lido).


*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    FILE *fp;
    char filename[100];
    char frase[50];
    int i, tamanho;

    printf("Digite o nome do arquivo: "); //Solicita o nome do arquivo ao usu�rio
    scanf("%s", filename); //L� o nome do arquivo digitado pelo usu�rio

    fp = fopen(filename, "wb"); //Abre o arquivo para escrita bin�ria
    if (fp == NULL)   //Verifica se o arquivo foi aberto com sucesso
    {
        printf("Nao foi possivel criar o arquivo.\n"); //Se n�o foi poss�vel abrir o arquivo, informa ao usu�rio
        return 0; //Finaliza o programa
    }

    for (i = 0; i < 5; i++)   //Loop para ler as 5 frases
    {
        printf("Digite uma frase (maximo de 50 caracteres): "); //Solicita uma frase ao usu�rio
        scanf("%s", frase); //L� a frase digitada pelo usu�rio
        tamanho = strlen(frase); //Calcula o tamanho da frase
        fwrite(&tamanho, sizeof(int), 1, fp); //Escreve o tamanho da frase no arquivo bin�rio
        for (int j = 0; j < tamanho; j++)   //Loop para transformar a frase em mai�sculas
        {
            frase[j] = toupper(frase[j]); //Transforma o caractere em mai�sculas
        }
        fwrite(frase, sizeof(char), tamanho, fp); //Escreve a frase em mai�sculas no arquivo bin�rio
    }

    fclose(fp); //Fecha o arquivo

    fp = fopen(filename, "rb"); //Abre o arquivo para leitura bin�ria
    if (fp == NULL)   //Verifica se o arquivo foi aberto com sucesso
    {
        printf("Nao foi possivel abrir o arquivo.\n");
        return 0;
    }

    printf("Frases convertidas:\n");
    for (i = 0; i < 5; i++)
    {
        fread(&tamanho, sizeof(int), 1, fp);
        fread(frase, sizeof(char), tamanho, fp);
        printf("%s\n", frase);
    }

    fclose(fp);

    return 0;
}
