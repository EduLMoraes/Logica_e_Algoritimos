// 7. O código de César
// ́
// é uma das mais simples e conhecidas técnicas de criptografia. É um tipo

// de substituição na qual cada letra do texto
// ́
// é substituída por outra, que se apresenta no alfabeto
// abaixo dela um número fixo de vezes. Por exemplo, com uma troca de três posições, ‘A’ seria
// substituído por ‘D’, ‘B’ se tornaria ‘E’, e assim por diante. Implemente um programa que faça uso
// desse Código de César (3 posições), entre com uma string e retorne a string codificada.
// Exemplo:
// String: a ligeira raposa marrom saltou sobre o cachorro cansado
// Nova string: D OLJHLUD UDSRVD PDUURP VDOWRX VREUH R FDFKRUUR FDQVDGR

#include <stdio.h>
#include <stdlib.h>

void cesar(char *string);

int main(){
    char *string = NULL;
    int tamanho_init = 3;

    string = (char*)(malloc(tamanho_init*sizeof(char)));
    
    char character;
    int i = 0;

    while(1){
        character = getchar();

        if (character == '\n'){
            string[i] = '\0';
            break;
        }

        string[i] = character;
        i++;

        if (i==tamanho_init)
        {
            tamanho_init+=2;
            string = (char *)realloc(string, tamanho_init*sizeof(char));
            if (string == NULL){
                printf("Erro na realocação de memória");
                return 1;
            }
        }
    }

    cesar(string);
}

void cesar(char *string){
    int i = 0;
    while(1){
        if(string[i] == NULL || string[i] == '\0'){
            puts(string);
            break;
        }
        if(string[i] != ' '){
            string[i] = string[i]+3;
        }
        i++;
    }
}