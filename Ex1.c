//Emanuelle Lino Scheifer

/* Escreva um trecho de código para fazer a criação dos novos tipos de dados conforme solicitado abaixo:
Horário: composto de hora, minutos e segundos.
Data: composto de dia, mês e ano.
Compromisso: composto de uma data, horário e texto que descreve o compromisso.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição do tipo Horário
typedef struct
{
    int hora;
    int minuto;
    int segundo;
} Horario;

// Definição do tipo Data
typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

// Definição do tipo Compromisso
typedef struct
{
    Data data;
    Horario horario;
    char descricao[100];
} Compromisso;

int main(void)
{
    Compromisso compromisso;

    // Solicitação da data do compromisso
    printf("Informe a data do compromisso (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &compromisso.data.dia, &compromisso.data.mes, &compromisso.data.ano);

    // Solicitação do horário do compromisso
    printf("Informe o horário do compromisso (hh:mm:ss): ");
    scanf("%d:%d:%d", &compromisso.horario.hora, &compromisso.horario.minuto, &compromisso.horario.segundo);

    // Solicitação da descrição do compromisso
    printf("Informe a descrição do compromisso: ");
    scanf("%s", compromisso.descricao);

    // Exibição do compromisso
    printf("Data do compromisso: %02d/%02d/%04d\n", compromisso.data.dia, compromisso.data.mes, compromisso.data.ano);
    printf("Horário do compromisso: %02d:%02d:%02d\n", compromisso.horario.hora, compromisso.horario.minuto, compromisso.horario.segundo);
    printf("Descrição do compromisso: %s\n", compromisso.descricao);

    return 0;
}
