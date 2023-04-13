#include <stdio.h>
int main(){
    float n1, n2, n3, mh;

    printf("Informe as 3 notas do aluno: ");
    scanf("%f", &n1);
    scanf("%f", &n2);
    scanf("%f", &n3);

    mh = ((1/n1) + (1/n2) + (1/n3))/3;

    printf("Média Harmonica: %f", mh);
}