#include <stdio.h>

int main(){
    int elei, vb, vn, vv, vtb, vtn, vtv;

    printf("Informe a quantidade de eleitores em um múnicipio: \n");
    scanf("%i", &elei);

    printf("Informe a quantia de votos em branco: \n");
    scanf("%i", &vb);

    printf("Informe a quantia de votos nulos: \n");
    scanf("%i", &vn);

    printf("Informe a quantia de votos válidos: \n");
    scanf("%i", &vv);

    vtb = (vb*100)/elei;
    vtn = (vn*100)/elei;
    vtv = (vv*100)/elei;

    printf("%%%i votos brancos \n %%%i votos nulos \n %%%i votos válidos", vtb, vtn, vtv);

}