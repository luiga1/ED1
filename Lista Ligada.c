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

cabecalho Cria_Lista(cabecalho lista);

cabecalho Cria_No_Inicio(cabecalho lista);

cabecalho Cria_No_Final(cabecalho lista);

cabecalho Deleta_No(cabecalho lista);

void Print_lista(cabecalho lista);

int main(){

    cabecalho lista1;

    lista1 = Cria_Lista(lista1);

    lista1 = Cria_No_Inicio(lista1);

    lista1 = Cria_No_Final(lista1);

    Print_lista(lista1);

return 0;
}


cabecalho Cria_Lista(cabecalho lista){

    No *novoNo = malloc(sizeof(No));

    printf("Digite o primeiro elemento ");
    scanf("%d",&novoNo->elemento);

    // defino o primeiro elemento e deixo o No em null
    lista.primeiro = novoNo;
    novoNo->prox = NULL;

    //vai definir como o ultimo no tambem e seu tamanho
    lista.ultimo = novoNo;
    lista.tamanho = 1;


    return lista;
}

cabecalho Cria_No_Inicio(cabecalho lista){

    //cria um novo nó
    No *novoNo = malloc(sizeof(No));

    printf("Digite o elemento a ser criado ");
    scanf("%d",&novoNo->elemento);

    //troca de ponteiros
    novoNo->prox = lista.primeiro;
    lista.primeiro = novoNo;

    lista.tamanho++;

    return lista;

}

cabecalho Cria_No_Final(cabecalho lista){

    No *aux;

    //cria um novo nó
    No *novoNo = malloc(sizeof(No));

    printf("Digite o elemento a ser criado no final ");
    scanf("%d",&novoNo->elemento);

    // trocar o ponteiro que esta no final pelo novo

    aux = lista.ultimo;

    aux->prox = novoNo;
    novoNo->prox = NULL;

    lista.ultimo = novoNo;

    lista.tamanho++;

    return lista;
}

void Print_lista(cabecalho lista){
    No *aux = lista.primeiro;

    while(aux != NULL){
        printf(" %d ->", aux->elemento);
        aux = aux->prox;
    }

}
