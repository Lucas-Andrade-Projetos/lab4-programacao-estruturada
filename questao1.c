/* 

Escreva um programa que recebe um caractere e uma frase e imprima a frase fornecida
até a primeira ocorrência do caractere fornecido. O seu programa funciona corretamente mesmo que
o caractere fornecido não apareça na frase?

Para rodar o programa
gcc -std=c99 -Wall -g -lm questao1.c -o questao1.exe
Get-Content input.txt | ./questao1.exe 

*/

#include <stdio.h>

#define NMAX 100

void procura_char(char caractere, char frase[NMAX], char frase_cortada[NMAX]);

int main()
{
    char caractere, frase[NMAX], frase_cortada[NMAX];

    scanf("%c", &caractere);
    getchar();
    scanf("%[^\n]", frase);
    getchar();
    
    procura_char(caractere, frase, frase_cortada);
    printf("%s\n", frase_cortada);
    
    return 0;
}

//Essa função recebe um caractere e uma string e reatribui as palavras da string até o caractere passado.
void procura_char(char caractere, char frase[NMAX], char frase_cortada[NMAX])
{
    int i;
    for (i = 0; i < NMAX; i++)
    {   
        if(frase[i] == caractere){
            frase_cortada[i] = frase[i];
            break;
        }
        frase_cortada[i] = frase[i];
    }
    frase_cortada = '\0';
}