//Emanuelle Lino
/*
Fa�a um programa que pe�a para o usu�rio entrar um texto que deseja procurar
(uma palavra) e que em seguida leia um arquivo texto do disco e procure por esta palavra no arquivo.
Caso seja encontrada a palavra digitada pelo usu�rio em alguma das linhas do arquivo texto lido do disco,
 o programa dever� exibir na tela o n�mero da linha do arquivo onde encontrou esta ocorr�ncia da palavra,
 bem como o conte�do da linha onde se encontra a palavra procurada.
*/
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000 // define o comprimento m�ximo da string

int main()
{
    char wordToFind[MAX_LENGTH], line[MAX_LENGTH]; // strings para armazenar a palavra a ser procurada e a linha atual do arquivo
    printf("Entre com a palavra: ");
    scanf("%s", wordToFind); // l� a palavra a ser procurada
    FILE *fp;
    fp = fopen("file.txt", "r"); // abre o arquivo "file.txt" em modo leitura
    if (fp == NULL)
    {
        printf("Erro ao abrir arquivo\n"); // se n�o conseguir abrir o arquivo, exibe uma mensagem de erro
        return 1;
    }
    int lineNumber = 0; // inicializa o n�mero da linha como zero
    while (fgets(line, MAX_LENGTH, fp) != NULL)   // l� uma linha do arquivo enquanto houver conte�do para ser lido
    {
        lineNumber++; // incrementa o n�mero da linha
        if (strstr(line, wordToFind) != NULL)   // verifica se a palavra a ser procurada est� na linha atual
        {
            printf("Palavra '%s' encontrada na linha %d: %s", wordToFind, lineNumber, line); // exibe a mensagem indicando que a palavra foi encontrada, juntamente com o n�mero da linha e a linha em si
        }
    }
    fclose(fp); // fecha o arquivo
    return 0; // encerra o programa com sucesso
}
