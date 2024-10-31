/* 
Escreva um programa que devolva o tamanho da maior cadeia de 0’s de uma string

Para rodar o programa
gcc -std=c99 -Wall -g -lm questao2.c -o questao2.exe
Get-Content input2.txt | ./questao2.exe 

*/

#include <stdio.h>

#define NMAX 100

void procura_cadeia(char cadeia[NMAX]);

int main()
{
    char cadeia[NMAX];

    scanf("%[^\n]", cadeia);
    getchar();

    procura_cadeia(cadeia);
    return 0;
}

//essa função recebe uma string e procura o numero de zeros da maior sequencia de 0
void procura_cadeia(char cadeia[NMAX])
{
    int maximo, comparador = 0;
    for (int i = 0; i < NMAX; i++)
    {
        if (cadeia[i] == '0'){
            comparador += 1;
        }else{
            if (comparador > maximo){ 
                maximo = comparador; 
                comparador = 0; 
            }
        }
    }
    printf("%d", maximo);
}