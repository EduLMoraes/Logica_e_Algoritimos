#include <stdio.h>

int main(){
    int c, k, f;

    printf("Informe a temperatura em Fahrenheit: ");
    scanf("%i", &f);

    c = (f-32)/1.8;
    k = 273 + c;
    
    printf("%i Celsius \n %i Kelvin", c, k);
}