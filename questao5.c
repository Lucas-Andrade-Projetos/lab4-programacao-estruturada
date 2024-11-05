/*
Desenvolva um programa que reformate os parágrafos de um texto, garantindo que 
nenhuma linha exceda 80 caracteres.

para rodar o programa escreva no terminal do vscode:
gcc -std=c99 -Wall -g -lm questao5.c -o questao5.exe
Get-Content input3.txt | ./questao5.exe

essa questão foi o capeta pqp;

*/
#include <stdio.h>
#include <string.h>

#define NMAX 1000 
void refatura_texto(char texto[NMAX]);

int main()
{
    char texto[NMAX];
    int pos = 0;

    while (pos < NMAX ) 
    {
        //Aqui eu ensiro o texto em um vetor e substituo todos suas quebras de linha por espaços.
        int ch = getchar();
        //esse if verifica se ainda tem texto a ser digitado, caso fosse um programa o usuario pararia digitando control + z 
        if (ch == EOF) break;
        
        if(ch != '\n') {
            texto[pos] = (char)ch;
        }else{
            texto[pos] = ' ';
        }
        pos++;
    }

    //caractere nulo
    texto[pos] = '\0'; 
    

    refatura_texto(texto);
    printf("%s", texto);
    
    return 0;
}

//essa função recebe um vetor de n caracteres e adiciona uma quebra de linha a cada 80 caracteres
void refatura_texto(char texto[NMAX]){

    //essa função conta o tamanho do vetor
    int len = strlen(texto);
    int contador = 80;
    //enquanto contador < que tamanho do vetor, ou seja a função vai adicionando quebra de linhas até no contador passar o tamanho do vetor
    while (contador < len) {
        int pos2 = contador;
        //enquanto posição não for um espaço vazio ou seja estiver no meio de uma palavra ele vai diminuindo, o que isso significa?
        //significa que pos[80] estiver no meio de uma palavra ele diminui até achar um espaço vazio.
        while(texto[pos2] != ' '){ 
            pos2--;
        }
        //quando acha se pos > 0 ele adiciona a quebra de linha e contador recebe mais 80.
        if(pos2 > 0){
            texto[pos2] = '\n';
            contador = pos2 + 80;
        }
    }

}