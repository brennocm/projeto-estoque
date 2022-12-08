#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Structs.c"
#include <time.h> //biblioteca para data e horario
#include "UtilitarieFunctions.c"
#define TRUE 1
#define BUFFER_SIZE 1000


void incluirProduto(){

    FILE *file;

    char nome[40];
    int cod, qtd, i;
    
    //seta as variaveis que auxiliam na data e hora
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("Digite o nome do produto: ");
    scanf(" %s", &nome);

    //Transforma nome em maiúslculo
    strToUpper(nome);

    printf("Digite o codigo do produto: ");
    scanf("%d", &cod);
    printf("Digite o quantidade do produto: ");
    scanf("%d", &qtd);

    //seta a estrutura do produto
    Produto p1 = {
        .nome = nome,
        .cod = cod,
        .qtd = qtd,
        .date.dia = tm.tm_mday,
        .date.mes = tm.tm_mon + 1,
        .date.ano = tm.tm_year + 1900,
        .date.hora = tm.tm_hour, 
        .date.min = tm.tm_min, 
        .date.seg = tm.tm_sec
    };

    //se arquivo não existir, fecha.
    if (file == NULL){
        printf("Não foi possível incluir um item.\n\n");
        exit(0);
    }
    
    //abre arquivo e imprime as informações da estrutura no arquivo 
    file = fopen("estoque.txt", "a");
    fprintf(file, "%s\n%d\n%d\n%d/%d/%d\n%d:%d:%d\n", p1.nome, p1.cod, p1.qtd, p1.date.dia, p1.date.mes, p1.date.ano, p1.date.hora, p1.date.min, p1.date.seg);
    fclose(file);

    //Printa no console o produto adicionado
    printf("\nProduto incluido ---\n\nNome: %s\nCod: %d\nQuantidade: %d\nData: %d/%d/%d\nHora: %d:%d:%d\n\n", p1.nome, p1.cod, p1.qtd, p1.date.dia, p1.date.mes, p1.date.ano, p1.date.hora, p1.date.min, p1.date.seg);
    system("Pause");
}; //prot�tipo


void buscarProduto(void){
    int i;
    int linhasArquivo = contarLinhas("estoque.txt");
    char *vetor[linhasArquivo][40];
    size_t malloc_size = 100;
    char nomeProduto[40];

    //Salva o item de busca em uma variável
    printf("Insira o nome do produto que deseja buscar: \n");
    scanf(" %s", &nomeProduto);

     //Transforma nome em maiúslculo
    strToUpper(nomeProduto);

    //Cria ponteiro de arquivo e abre o arquivo
    FILE *file;
    file = fopen("estoque.txt", "r");

    //Grava as linhas do arquivo em um vetor e faz alocação dinamica
    for (i = 0; i < linhasArquivo; i++)
    {   
        vetor[i][40] = malloc(malloc_size + sizeof(char));     
        fscanf(file, "%s\n", &vetor[i]);
    };
    
    //Fecha arquivo
    fclose(file);

    //Compara o item de busca com todos os elementos do vetor
    //Se achar um igual, imprime o item no terminal
    for (i = 0; i < linhasArquivo; i++)
    {     
        if(strcmp(vetor[i], nomeProduto) == 0){
            printf("\n---Item encontrado!---\n\n");
            printf("Nome: %s\n", vetor[i]);
            printf("Codigo: %s\n", vetor[i+1]);
            printf("Quantidade: %s\n", vetor[i+2]);
            printf("Data adicionado: %s\n", vetor[i+3]);
            printf("Horario adicionado: %s\n", vetor[i+4]);
            printf("\n");
            free(vetor);
            system("Pause");
            return 0;
        }
    };
    
    //Se não achar, imprime o seguinte no terminal
    free(vetor);
    printf("\n\n---Item nao encontrado!---\n\n\n");
    system("Pause");

}; //prot�tipo

void alterarProduto(void){

int i;
    int linhasArquivo = contarLinhas("estoque.txt");
    char *vetor[linhasArquivo][40];
    size_t malloc_size = 100;
    char nomeProduto[40];
    int line;

    //declara variaveis com a data atual
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int dia = tm.tm_mday;
    int mes = tm.tm_mon + 1;
    int ano = tm.tm_year + 1900;
    int hora = tm.tm_hour;
    int min = tm.tm_min; 
    int seg = tm.tm_sec;

    fflush(stdin);

    //Salva o item de busca em uma variável
    printf("Insira o nome do produto que deseja alterar: \n");
    fgets(nomeProduto, 40, stdin);
    fflush(stdin);

    size_t strSize = strlen (nomeProduto);
    nomeProduto[strSize-1] = '\0';

     //Transforma nome em maiúslculo
    strToUpper(nomeProduto);
    printf("%s", nomeProduto);
    //Cria ponteiro de arquivo e abre o arquivo
    FILE *file;
    file = fopen("estoque.txt", "r");

    //Grava as linhas do arquivo em um vetor e faz alocação dinamica
    for (i = 0; i < linhasArquivo; i++)
    {   
        vetor[i][40] = malloc(malloc_size + sizeof(char));     
        fscanf(file, "%s\n", &vetor[i]);
    };
    
    //Fecha arquivo
    fclose(file);

    //Compara o item de busca com todos os elementos do vetor
    //Se achar um igual, imprime o item no terminal
    


    for (i = 0; i < linhasArquivo; i++)
    {     
        if(strcmp(vetor[i], nomeProduto) == 0){
            printf("\n---Item encontrado!---\n\n");
        }
    }            
    
    /* File pointer to hold reference of input file */
    FILE * fPtr;
    FILE * fTemp;
    char path[100] = "estoque.txt";
    
    char buffer[BUFFER_SIZE];
    char novoProduto[BUFFER_SIZE];
    int novoCod;
    int novaQtd;
    int count;

    /* Remove extra new line character from stdin */
    fflush(stdin);

    printf("Alterar para: ");
    fgets(novoProduto, BUFFER_SIZE, stdin);

    printf("Código do novo produto: ");
    scanf("%d", &novoCod);
    
    printf("Quantidade do produto: ");
    scanf("%d", &novaQtd);

    strToUpper(novoProduto);
    printf("%s", novoProduto);
    printf("%d", novoCod);
    printf("%d", novaQtd);

    /*  Open all required files */
    fPtr  = fopen(path, "r");
    fTemp = fopen("replace.tmp", "w"); 

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }


    /*
     * Read line from source file and write to destination 
     * file after replacing given line.
     */

    

    count = 0;
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        count++;

        /* If current line is line to replace */
        if (count == line)
            fputs(novoProduto, fTemp);
        else if ( count == line + 1)
            fprintf(fTemp,"%d\n",novoCod);
        else if ( count == line + 2)
            fprintf(fTemp,"%d\n", novaQtd);
        else if ( count == line + 3)
            fprintf(fTemp,"%d/%d/%d\n", dia, mes, ano);
        else if ( count == line + 4)
            fprintf(fTemp,"%d:%d:%d\n", hora, min, seg);
        else
            fputs(buffer, fTemp);
    }
    

    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);


    /* Delete original source file */
    remove(path);

    /* Rename temporary file as original file */
    rename("replace.tmp", path);

    printf("Produto alterado com sucesso!\n");

    printf("\nProduto incluido ---\n\nNome: %s\nCod: %d\nQuantidade: %d\nData: %d/%d/%d\nHora: %d:%d:%d\n\n", novoProduto, novoCod, novaQtd, dia, mes, ano, hora, min, seg);


    return 0;

}; //prot�tipo


void removerProduto(void){
    int i;
    int linhasArquivo = contarLinhas("estoque.txt");
    char *vetor[linhasArquivo][40];
    size_t malloc_size = 100;
    char nomeProduto[40];
    int line;

    fflush(stdin);

    //Salva o item de busca em uma variável
    printf("Insira o nome do produto que deseja alterar: \n");
    fgets(nomeProduto, 40, stdin);
    fflush(stdin);

    size_t strSize = strlen (nomeProduto);
    nomeProduto[strSize-1] = '\0';

     //Transforma nome em maiúslculo
    strToUpper(nomeProduto);
    printf("%s", nomeProduto);
    //Cria ponteiro de arquivo e abre o arquivo
    FILE *file;
    file = fopen("estoque.txt", "r");

    //Grava as linhas do arquivo em um vetor e faz alocação dinamica
    for (i = 0; i < linhasArquivo; i++)
    {   
        vetor[i][40] = malloc(malloc_size + sizeof(char));     
        fscanf(file, "%s\n", &vetor[i]);
    };
    
    //Fecha arquivo
    fclose(file);

    //Compara o item de busca com todos os elementos do vetor
    //Se achar um igual, imprime o item no terminal
    


    for (i = 0; i < linhasArquivo; i++)
    {     
        if(strcmp(vetor[i], nomeProduto) == 0){
            printf("\n---Item encontrado!---\n\n");
            line = i + 1;
            printf("%d\n", line);
        }
    }            
    
    /* File pointer to hold reference of input file */
    FILE * fPtr;
    FILE * fTemp;
    char path[100] = "estoque.txt";
    
    char buffer[BUFFER_SIZE];

    int count;

    /* Remove extra new line character from stdin */
    fflush(stdin);

    system("read -p 'Press Enter to continue...' var");
    /*  Open all required files */
    fPtr  = fopen(path, "r");
    fTemp = fopen("replace.tmp", "w"); 

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }


    /*
     * Read line from source file and write to destination 
     * file after replacing given line.
     */
    count = 0;
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        count++;

        /* If current line is line to delete */
        if (count != line && count!=line+1 && count!=line+2 && count!=line+3 && count!=line+4)
            fputs(buffer, fTemp);
    }


    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);


    /* Delete original source file */
    remove(path);

    /* Rename temporary file as original file */
    rename("replace.tmp", path);



    return 0;
}; //prot�tipo


void limparEstoque(void){
    FILE *file;
    file = fopen("estoque.txt", "w");
    fprintf(file, "");
    fclose(file);
};//Limpa o arquivo


void retornarEstoque(void){
    printf("\n");

    FILE *file;
    
    file = fopen("estoque.txt", "r");
    if (file == NULL){
        printf("Não foi possível abrir o estoque");
        exit(0);
    }
    char linha[10000];

    while(fgets(linha, 10000, file) != NULL){
        printf("%s", linha);
    }
    
    fclose(file);
    printf("\n");
    system("Pause");
}