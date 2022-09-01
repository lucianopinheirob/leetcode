//lucianopinheirob

#include <stdio.h>
#define indice_max 6

int numeros_possiveis[] = {1000, 500, 100, 50, 10, 5, 1};
char letras_possiveis[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};

int retorna_indice(char letra);
int romanToInt(char* S);

int main (){
    char* numero_romano;
    int numero_inteiro;
    numero_romano = "MCDXCIV";
    numero_inteiro = romanToInt(numero_romano);
    printf("%d", numero_inteiro);
    return 0;
}

int retorna_indice(char letra){
    int indice = 0;
    while (indice < indice_max){
            if (letra == letras_possiveis[indice]) break;
            indice += 1;
        }
    return indice;
}

int romanToInt (char* S){
    int numero_inteiro = 0, indice, proximo_indice, delta_indice;
    while (*S != '\0'){
        indice = retorna_indice(*S);
        proximo_indice = retorna_indice(*(S+1));
        delta_indice = indice - proximo_indice;
        if (delta_indice > 0){
            numero_inteiro += numeros_possiveis[proximo_indice] - numeros_possiveis[indice];
            S = S + 2;
        }
        else{
            numero_inteiro += numeros_possiveis[indice];
            S += 1;
        } 
    }
    return numero_inteiro;
}