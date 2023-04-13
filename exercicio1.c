#include <stdio.h>

int main(){
    float nota1, nota2, mp;
    int peso1, peso2;

    printf("Informe as notas: \n");
    
    scanf("%f", &nota1);
    scanf("%f", &nota2);

    printf("Informe os pesos na ordem em que informou as notas: \n");
    scanf("%i", &peso1);
    scanf("%i", &peso2);
    while (!mp)
    {
    if(peso1+peso2 == 10){ 
        mp = ((peso1*nota1) + (peso2*nota2))/(peso1+peso2);
    }else{
        printf("Informe os pesos de forma que a soma deles de 10! Insira-os novamente\n");
        scanf("%i", &peso1);
        scanf("%i", &peso2);
        }

    }



    printf("A Média Ponderada foi: %.2f", mp);
}