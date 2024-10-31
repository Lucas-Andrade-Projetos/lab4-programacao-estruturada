/* 
Escreva um programa que converte os caracteres maiúsculos de uma string em minúscu
los e vice-versa. Suponha que só há caracteres latinos sem acentos.
*/

#include <stdio.h>

#define NMAX 100

int isUpper_case(char cadeia);
int isLower_case(char cadeia);
void reverse_case(char frase[NMAX]);

int main()
{
    char frase[NMAX];
    scanf("%[^\n]", frase);
    getchar();
    
    reverse_case(frase);
    printf("%s\n", frase);
    
    return 0;
}

//inverte para maisculo se for minusco e ao contrario para o contrario.
void reverse_case(char frase[NMAX]){
    
    for (int i = 0; i < NMAX; i++)
    {
        
        if(isUpper_case(frase[i])){ 
            frase[i] = frase[i] + 32;
        }else if(isLower_case(frase[i])){ 
            frase[i] = frase[i] - 32;
        }
    }
    
}

//Essa função verifica se um caractere está em maisculo
int isUpper_case(char cadeia) {
    return cadeia >= 'A' && cadeia <= 'Z';
}

//Essa função verifica se um caractere está em minusculo
int isLower_case(char cadeia) {
    return cadeia >= 'a' && cadeia <= 'z';
}