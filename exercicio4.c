#include <stdio.h>

int main(){
    int d, m, a;

    printf("Informe sua idade em dias: ");
    scanf("%i", &d);

    m = d/30;
    a = d/365;

    printf("Você tem %i dias de vida \n %i meses de vida \n %i anos de vida", d, m, a);
}