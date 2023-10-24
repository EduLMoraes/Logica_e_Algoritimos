#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXN 10

struct carta {
  int valor;
  char naipe[MAXN];
}; 

typedef struct carta Carta;


void preenche(Carta []);
void distribui(Carta [], Carta[], Carta[]);
void baralha(Carta []);
void mostra_cartas(Carta []);
void mostra_cartas_baralho(Carta []);

int main()
{
 
 int nro_cartas1=26, nro_cartas2=26;
 char a;
 


 Carta baralho[52], jog1[26], jog2[26];
 
 srand(time(NULL));
 preenche(baralho);
 printf ("\n*** CARTAS ****\n");
 mostra_cartas_baralho(baralho);
 a=getchar();
 baralha(baralho);

 printf ("\n*** CARTAS EMBARALHADAS ****\n");
 mostra_cartas_baralho(baralho);
 a=getchar();

 distribui(baralho, jog1, jog2);
 printf ("\n*** CARTAS DO JOGADOR 1 ****\n");
 
 mostra_cartas(jog1);
  a=getchar();

 printf ("\n*** CARTAS DO JOGADOR 2 ****\n");
 mostra_cartas(jog2);
  a=getchar();

 
 printf ("\nQtde de cartas do jog1 %d e qtde de cartas do jog2 %d", nro_cartas1, nro_cartas2);
 return 1;
}

void preenche( Carta baralho[]) {
  int i=0,x,y; 
  char naipes[][MAXN]={"Copas","Espadas","Paus","Ouros"};
  
  for (x=0;x<4;x++)
    for (y=1;y<=13;y++,i++)
    {
    baralho[i].valor = y;
    strcpy(baralho[i].naipe,naipes[x]);
    }
}

void baralha(Carta baralho[]) 
{
  for(int i = 0; i< 52; i++){
    int pos1 = rand() % 52;
    int pos2 = rand() % 52;


    Carta carta1 = baralho[pos1];
    Carta carta2 = baralho[pos2];
    baralho[pos1] = carta2;
    baralho[pos2] = carta1;
  }
}

void distribui(Carta baralho[], Carta jog1[], Carta jog2[]) 
{
  int ja_tem = 0, i =0, pos = 0;
  Carta carta_temp;

 while(i<26){
    pos = rand() % 52;
    carta_temp = baralho[pos];
    ja_tem = 0;

    for(int j = 0; j < 26; j++){

      if(jog1[j].valor == carta_temp.valor){
        if(strcmp(jog1[j].naipe, carta_temp.naipe) == 0){
          ja_tem = 1; 
          break;
        }
      }
    }
    
    if(ja_tem == 0){
      jog1[i] = carta_temp;
      i++;
    }
  }

  ja_tem = 0;
  i = 0;
  printf("\n");

  while(i<26){
    pos = rand() % 52;
    carta_temp = baralho[pos];
    ja_tem = 0;

    for(int j = 0; j < 26; j++){

      if(jog1[j].valor == carta_temp.valor){
        if(strcmp(jog1[j].naipe, carta_temp.naipe) == 0){
          ja_tem = 1; 
          break;
        }
      }
      else if(jog2[j].valor == carta_temp.valor){
        if(strcmp(jog2[j].naipe, carta_temp.naipe) == 0){
          ja_tem = 1; 
          break;
        }
      }
    }
    
    if(ja_tem == 0){
      jog2[i] = carta_temp;
      i++;
    }
  }
}

void mostra_cartas (Carta carta_temp[])
{
  int i;
  for(i=0;i<26;i++) 
      printf("%d - %2d de %-7s%c",i, carta_temp[i].valor,carta_temp[i].naipe,
           (i+1)%3? '\t': '\n');

}

void mostra_cartas_baralho (Carta carta_temp[]){
  int i;
  for(i=0;i<52;i++) 
      printf("%d - %2d de %-7s%c",i, carta_temp[i].valor,carta_temp[i].naipe,
           (i+1)%3? '\t': '\n');

}
