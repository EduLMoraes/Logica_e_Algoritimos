#include <stdio.h>

int main(){
    int c, f, k;

    printf("Informe a temperatura em Celsius: \n");
    scanf("%i", &c);

    f = 1.8 * c + 32;
    k = 273 + c;

    printf("%i Fahrenheit \n %i Kelvin", f, k);
}