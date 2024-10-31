/* 
Desenvolva um programa que reformate os parágrafos de um texto, garantindo que ne
nhuma linha exceda 80 caracteres.

//perguntar para o professor o que se usa para entrar textos grandes pq isso eu copiei da internet e não deu muito bom

Para rodar o programa
gcc -std=c99 -Wall -g -lm questao5.c -o questao5.exe
Get-Content input3.txt | ./questao5.exe 
*/

#include <stdio.h>
#include <string.h>

#define NMAX 1000

void refatura_texto(char texto[NMAX]);

int main()
{
    char texto[NMAX];
    char buffer[256]; 

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        strcat(texto, buffer);
        strcat(texto, " ");
    }
    
    refatura_texto(texto);
    printf("%s", texto);    
    return 0;
}



void refatura_texto(char texto[NMAX])
{

    int len = strlen(texto);
    int contador = 80;

    while (contador < len) {
        int pos = contador;
        while(texto[pos] != ' '){
            pos--;
        }

        if(pos > 0){
            texto[pos] = '\n';
            contador = pos + 80;
        }
    }
}