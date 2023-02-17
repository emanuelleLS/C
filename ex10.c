//Emanuelle Lino
/*
Faça um programa que peça para o usuário entrar um texto que deseja procurar
(uma palavra) e que em seguida leia um arquivo texto do disco e procure por esta palavra no arquivo.
Caso seja encontrada a palavra digitada pelo usuário em alguma das linhas do arquivo texto lido do disco,
 o programa deverá exibir na tela o número da linha do arquivo onde encontrou esta ocorrência da palavra,
 bem como o conteúdo da linha onde se encontra a palavra procurada.
*/
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000 // define o comprimento máximo da string

int main()
{
    char wordToFind[MAX_LENGTH], line[MAX_LENGTH]; // strings para armazenar a palavra a ser procurada e a linha atual do arquivo
    printf("Entre com a palavra: ");
    scanf("%s", wordToFind); // lê a palavra a ser procurada
    FILE *fp;
    fp = fopen("file.txt", "r"); // abre o arquivo "file.txt" em modo leitura
    if (fp == NULL)
    {
        printf("Erro ao abrir arquivo\n"); // se não conseguir abrir o arquivo, exibe uma mensagem de erro
        return 1;
    }
    int lineNumber = 0; // inicializa o número da linha como zero
    while (fgets(line, MAX_LENGTH, fp) != NULL)   // lê uma linha do arquivo enquanto houver conteúdo para ser lido
    {
        lineNumber++; // incrementa o número da linha
        if (strstr(line, wordToFind) != NULL)   // verifica se a palavra a ser procurada está na linha atual
        {
            printf("Palavra '%s' encontrada na linha %d: %s", wordToFind, lineNumber, line); // exibe a mensagem indicando que a palavra foi encontrada, juntamente com o número da linha e a linha em si
        }
    }
    fclose(fp); // fecha o arquivo
    return 0; // encerra o programa com sucesso
}
