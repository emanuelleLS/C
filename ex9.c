//Emanuelle Lino
/*
Faça um programa em C que lê 5 frases de,
no máximo, 50 caracteres cada uma e armazene-as em um arquivo.
Mas, antes de gravar cada frase no arquivo, é necessário converter todas as suas letras para maiúsculas.
O nome do arquivo será fornecido, via teclado, pelo usuário.
A função que converte maiúscula para minúscula é o toupper().
A seguir, feche o arquivo e reabra para leitura exibindo todas as frases convertidas.
Como cada texto pode ter tamanho diferente, será necessário gravar antes de cada frase o tamanho do texto a ser lido,
 logo serão necessários dois comandos de gravação e leitura (um para o número inteiro que indica a quantidade de caracteres da frase e outro para a frase com o tamanho lido).


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

    printf("Digite o nome do arquivo: "); //Solicita o nome do arquivo ao usuário
    scanf("%s", filename); //Lê o nome do arquivo digitado pelo usuário

    fp = fopen(filename, "wb"); //Abre o arquivo para escrita binária
    if (fp == NULL)   //Verifica se o arquivo foi aberto com sucesso
    {
        printf("Nao foi possivel criar o arquivo.\n"); //Se não foi possível abrir o arquivo, informa ao usuário
        return 0; //Finaliza o programa
    }

    for (i = 0; i < 5; i++)   //Loop para ler as 5 frases
    {
        printf("Digite uma frase (maximo de 50 caracteres): "); //Solicita uma frase ao usuário
        scanf("%s", frase); //Lê a frase digitada pelo usuário
        tamanho = strlen(frase); //Calcula o tamanho da frase
        fwrite(&tamanho, sizeof(int), 1, fp); //Escreve o tamanho da frase no arquivo binário
        for (int j = 0; j < tamanho; j++)   //Loop para transformar a frase em maiúsculas
        {
            frase[j] = toupper(frase[j]); //Transforma o caractere em maiúsculas
        }
        fwrite(frase, sizeof(char), tamanho, fp); //Escreve a frase em maiúsculas no arquivo binário
    }

    fclose(fp); //Fecha o arquivo

    fp = fopen(filename, "rb"); //Abre o arquivo para leitura binária
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
