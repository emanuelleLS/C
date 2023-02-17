
//Emanuelle Lino
/*
Faça um programa que seja capaz de armazenar os dados de um produto:
 código, nome, valor e quantidade. Seu programa deve ser capaz de armazenar 5 produtos.
  Ao final dos cadastros, o usuário deve inserir o código de um produto e o seu programa deve imprimir
  na tela, as informações daquele produto.
  Caso o produto não se encontre cadastrado, deve-se informar ao usuário a seguinte mensagem: "código não encontrado".
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
        printf("Cadastro do %dº produto:\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &products[i].code);
        printf("Nome: ");
        scanf("%s", products[i].name);
        printf("Valor: ");
        scanf("%f", &products[i].value);
        printf("Quantidade: ");
        scanf("%d", &products[i].quantity);
    }

    // Consulta por código
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
