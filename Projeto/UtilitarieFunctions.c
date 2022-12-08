#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define TRUE 1

//Conta as linhas do arquivo e retorna o nº de linhas
int contarLinhas(char *nomeArquivo){
    FILE *fp;
    char ch;
    int cont = 1;
    fp = fopen(nomeArquivo, "r");
    if(fp == NULL){
        printf("Erro ao contar as linhas.\n");
        return -1;
    }
    while(!feof(fp)){
        ch = fgetc(fp);
        if (ch == '\n'){
            cont++;
        }
    }
    fclose(fp);
    return cont; 
}

//Transforma string em upper case
char strToUpper(char * string){
    int i;
     for (i = 0; string[i]!='\0'; i++) {
      if(string[i] >= 'a' && string[i] <= 'z') {
         string[i] = string[i] -32;
      }
   }
   return string;
}

