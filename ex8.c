
//Emanuelle Lino
/*
Crie um programa C que:
crie/abra um arquivo texto de nome "arq.txt",
permita que o usu�rio entre com diversos caracteres nesse arquivo,
 at� que o usu�rio entre com o caractere �0� (fim da entrada de dados),
Feche o arquivo e abra novamente o arq.txt, e
lendo-o caractere por caractere, e escrevendo na tela (printf) todos os caracteres armazenados.
*/
#include <stdio.h>

int main()
{
// Declara��o do ponteiro para arquivo "fp"
    FILE *fp;
// Declara��o da vari�vel que armazenar� os caracteres lidos do arquivo
    char c;

// Abertura do arquivo "arq.txt" para escrita
    fp = fopen("arq.txt", "w");

// Prompt para o usu�rio digitar o conte�do do arquivo
    printf("Digite o conteudo do arquivo ('0' para encerrar): \n");

// Loop para ler caracteres do teclado at� que o usu�rio digite "0"
    while((c = getchar()) != '0')
    {
// Escrita do caractere lido no arquivo
        fputc(c, fp);
    }

// Fechamento do arquivo "arq.txt"
    fclose(fp);

// Abertura do arquivo "arq.txt" para leitura
    fp = fopen("arq.txt", "r");

// Impress�o do t�tulo "Conteudo do arquivo:"
    printf("Conteudo do arquivo: \n");

// Loop para ler caracteres do arquivo at� que o fim do arquivo seja atingido (EOF)
    while((c = fgetc(fp)) != EOF)
    {
// Impress�o do caractere lido
        printf("%c", c);
    }

// Fechamento do arquivo "arq.txt"
    fclose(fp);

    return 0;
}
