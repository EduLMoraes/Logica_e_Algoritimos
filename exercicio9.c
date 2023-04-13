#include <stdio.h>

int main(){
    float troco, prec, pag;
    int  m1, m2, m3, m4, m5;

    printf("Informe o valor: ");
    scanf("%f", &prec);

    printf("Insira quantia do pagamento: ");
    scanf("%f", &pag);

    if(pag > prec){
        troco = pag - prec;
    }else if(pag < prec){
        troco = prec - pag;
    }
    printf("%f de Troco \n", troco);
    do
    {
       if (troco >= 1.0)
       {
        m1++;
        troco -= 1.0;
       }else if(troco >= 0.50 && troco < 1.0){
        m2++;
        troco -= 0.50;
       }else if(troco >= 0.25 && troco < 0.50){
        m3++;
        troco -= 0.25;
       }else if(troco >= 0.10 && troco < 0.25){
        m4++;
        troco -= 0.10;
       }else if(troco >= 0.05 && troco < 0.10){
        m5++;
        troco -= 0.05;
       }else {
        troco = 0.0;
       }

       
    } while (troco > 0.0);
    printf("%i Moedas de R$1,00 \n %i Moedas de R$0,50 \n %i Moedas de R$0,25 \n %i Moedas de R$0,10 \n %i Moedas de R$0,05", m1, m2, m3, m4, m5);
}