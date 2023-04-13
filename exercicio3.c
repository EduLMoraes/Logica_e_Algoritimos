#include <stdio.h>
#include <time.h>

int main(){
    int d, m, a, r;

    printf("Informe a data de nascimento em: ");
    printf("Dia: ");
    scanf("%i", &d);
    printf("Mês: ");
    scanf("%i", &m);
    printf("Ano: ");
    scanf("%i", &a);

     // Obtém o tempo atual
    time_t currentTime = time(NULL);
    // Converte o tempo atual para uma estrutura tm
    struct tm* localTime = localtime(&currentTime);
    
    // Extrai os componentes da data atual
    int day = localTime->tm_mday;        // Dia do mês (1-31)
    int month = localTime->tm_mon + 1;   // Mês (0-11, acrescenta 1 para ficar de 1-12)
    int year = localTime->tm_year + 1900;// Ano (o ano atual é contado a partir de 1900)

    d = day-d;
    m = month-m;
    a = year-a;

    r = d+(m*30)+(a*365);

    printf("Você tem %i dias de vida", r);
}