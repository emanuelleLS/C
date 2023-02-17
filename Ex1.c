//Emanuelle Lino Scheifer

/* Escreva um trecho de c�digo para fazer a cria��o dos novos tipos de dados conforme solicitado abaixo:
Hor�rio: composto de hora, minutos e segundos.
Data: composto de dia, m�s e ano.
Compromisso: composto de uma data, hor�rio e texto que descreve o compromisso.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defini��o do tipo Hor�rio
typedef struct
{
    int hora;
    int minuto;
    int segundo;
} Horario;

// Defini��o do tipo Data
typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

// Defini��o do tipo Compromisso
typedef struct
{
    Data data;
    Horario horario;
    char descricao[100];
} Compromisso;

int main(void)
{
    Compromisso compromisso;

    // Solicita��o da data do compromisso
    printf("Informe a data do compromisso (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &compromisso.data.dia, &compromisso.data.mes, &compromisso.data.ano);

    // Solicita��o do hor�rio do compromisso
    printf("Informe o hor�rio do compromisso (hh:mm:ss): ");
    scanf("%d:%d:%d", &compromisso.horario.hora, &compromisso.horario.minuto, &compromisso.horario.segundo);

    // Solicita��o da descri��o do compromisso
    printf("Informe a descri��o do compromisso: ");
    scanf("%s", compromisso.descricao);

    // Exibi��o do compromisso
    printf("Data do compromisso: %02d/%02d/%04d\n", compromisso.data.dia, compromisso.data.mes, compromisso.data.ano);
    printf("Hor�rio do compromisso: %02d:%02d:%02d\n", compromisso.horario.hora, compromisso.horario.minuto, compromisso.horario.segundo);
    printf("Descri��o do compromisso: %s\n", compromisso.descricao);

    return 0;
}
