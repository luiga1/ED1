/*
* Lista Ligadas Dinamicas
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int elemento;
    struct No *prox;
} No;


typedef struct cabecalho {
    No *primeiro;
    No *ultimo;
    int tamanho;
}cabecalho;


void Cria_No_Final(cabecalho lista);

void Cria_Lista(cabecalho* lista);

int main(){

    cabecalho *lista1;

    Cria_Lista(lista1);


return 0;
}

void Cria_No_Final(cabecalho lista){
    No *aux;

    aux = lista.primeiro;

    while( aux->prox != NULL){
        aux = aux->prox;
    }

    No *novoNo = malloc(sizeof(No));

    // coloco o elemento do no e deixo o ponteiro em null
    printf("Digite o valor do No ");
    scanf("%d", novoNo->elemento);
    novoNo->prox = NULL;

    aux->prox = novoNo;
}

void Cria_Lista(cabecalho* lista){

    No *novoNo = malloc(sizeof(No));

    printf("Digite o primeiro elemento");
    scanf("%d",novoNo->elemento);

    // defino o primeiro elemento e deixo o No em null
    lista->primeiro = novoNo;
    novoNo->prox = NULL;

}
