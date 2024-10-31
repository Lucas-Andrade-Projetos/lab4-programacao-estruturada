/* 
Escreva um programa que receba uma palavra e uma frase como entrada. O programa
deve escrever “sim” se a palavra estiver presente na frase e “não” caso contrário.

*/

#include <stdio.h>
#include <string.h>

#define NMAX 100

int procura_palavra(char palavra[NMAX], char frase[NMAX]);

int main()
{
    char palavra[NMAX], frase[NMAX];

    scanf("%[^\n]", palavra);
    getchar();
    fgets(frase, NMAX, stdin);


    if (procura_palavra(palavra, frase)) printf("SIM");
    else printf("NAO");
    
    return 0;
}


//recebe uma palavra e um texto e devolve um true ou false se a palavra estiver no texto
int procura_palavra(char palavra[NMAX], char frase[NMAX])
{
    int tamanho_palavra = strlen(palavra);

   //esse for percorre cada caractere do texto 
   for (int i = 0; i <= NMAX; i++) {
        int j;
        //esse for percorre o texto em busca do padrao da palavra ccaso nao de match entre a letra da palavra e do texto ele quebra o laço e caso dê
        //quando o tamanho j for o mesmo da palavra ele assume que a palavra está respeitando o padrao de letras e modelo, ou seja tem a palavra
        //se ele nao achar o padrao ele devolve false;
        for (j = 0; j < tamanho_palavra; j++){
            if (frase[i + j] != palavra[j])
            {
                break;
            }
        }
        
        if(j == tamanho_palavra){
            return 1;
        }
    }

    return 0;
}