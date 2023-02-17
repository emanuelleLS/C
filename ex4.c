
//Emanuelle Lino
/*
Fa�a um programa que seja capaz de armazenar os dados de um produto:
 c�digo, nome, valor e quantidade. Seu programa deve ser capaz de armazenar 5 produtos.
  Ao final dos cadastros, o usu�rio deve inserir o c�digo de um produto e o seu programa deve imprimir
  na tela, as informa��es daquele produto.
  Caso o produto n�o se encontre cadastrado, deve-se informar ao usu�rio a seguinte mensagem: "c�digo n�o encontrado".
*/
#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTS 5

typedef struct Product
{
    int code;
    char name[100];
    float value;
    int quantity;
} Product;

int main()
{
    Product products[MAX_PRODUCTS];
    int i;

    // Cadastro dos produtos
    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        printf("Cadastro do %d� produto:\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &products[i].code);
        printf("Nome: ");
        scanf("%s", products[i].name);
        printf("Valor: ");
        scanf("%f", &products[i].value);
        printf("Quantidade: ");
        scanf("%d", &products[i].quantity);
    }

    // Consulta por c�digo
    int code;
    printf("\nInforme o codigo do produto a ser consultado: ");
    scanf("%d", &code);

    int found = 0;
    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        if (products[i].code == code)
        {
            found = 1;
            printf("\nInformacoes do produto %d:\n", code);
            printf("Nome: %s\n", products[i].name);
            printf("Valor: %.2f\n", products[i].value);
            printf("Quantidade: %d\n", products[i].quantity);
            break;
        }
    }

    if (!found)
    {
        printf("\nCodigo nao encontrado\n");
    }

    return 0;
}
