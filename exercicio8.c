#include <stdio.h>

int main(){
    float d, p, a, r;

    printf("Informe o diâmetro: ");
    scanf("%f", &d);

    r = d/2;
    p = 2*3.14*r;
    a = 3.14*(r*r);

    printf("O perimetro é %f \n A area é %f", p, a);
}