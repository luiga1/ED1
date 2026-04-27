#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
*
* TAD estrutura de filas
*
*/

typedef struct {
    File* file
    char* nome;
    struct Arquivo* prox;
} Arquivo;

/* Struct do cabeçalho da fila de arquivos */

typedef struct {
    Arquivo* primeiro;
    Arquivo* final;
    int tamanho;
} Fila;

/* Função que retorna o proximo arquivo que esta na fila  */

File* pegaArquivo(Fila* fila){
    // define os ponteiros
    Arquivo* saida = fila->primeiro;
    Arquivo* aux;

    // se o primeiro for nulo o seu prox não vai existir
    if(saida == NULL ) aux = NULL;
    else aux = saida->prox;

    //movo a fila para a frente
    fila->primeiro = aux;

    return saida;
}

/* Adiciona um arquivo no final da fila */

void colocaFinal(Fila* fila, File* arquivo){
    Arquivo* adicao;
    Arquivo* aux = fila->primeiro;
    // cria na memoria
    adicao = malloc(sizeof(Arquivo));

    //criando os ponteiros
    adicao->file = arquivo;
    adicao->prox = NULL;

    // verifica se é o primeiro da fila
    if(aux == NULL){
        fila->primeiro = adicao;
        fila->ultimo = adicao;
    }else{
        while(aux->prox != NULL){
        aux = aux->prox;
        }
    }



}
