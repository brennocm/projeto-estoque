/* Programa de Controle de Estoque*/
//Rode o programa aqui

#include <stdio.h>
#include <stdlib.h>
#include "MainFunctions.c"
#define TRUE 1

int main (){
    char entrar;
    printf("\nEntrar no sistema de controle de estoque?\nS p/ Sim ou N p/ Nao\n");
    scanf(" %c", &entrar);
        
    while (toupper(entrar) == 'S'){
        char op;
        printf ("\nDigite:\n I para incluir novo produto.\n B para buscar um produto.\n A para alterar um produto.\n R para remover um produto.\n V para ver o Estoque\n L para limpar estoque\n S para sair\n");
        scanf(" %c", &op);

        switch (toupper(op)){
            case 'I':
                incluirProduto();
                break;
            case 'B':
                buscarProduto();
                break;
            case 'A':
                alterarProduto();
                break;
            case 'R':
                removerProduto();
                break;
            case 'V':
                retornarEstoque();
                break;
            case 'L':
                limparEstoque();
                break;
            case 'S': 
                entrar = 'N';
                break;
            default:
                printf("Opcao invalida!\n");
        }

    }

    //system ("PAUSE");
    return 0;
}
