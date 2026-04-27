/**Aplicação de lista estatica encadeada */
#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 10

typedef struct {
    int valor;
    int prox;
} Cell;

typedef struct{
    Cell lista[TAMANHO];
    int comeco;
    int dispo;
} Desc;

//criar lista
Desc* criaLista(){
    Desc* cabeca;
    int i=0;

    cabeca = malloc(sizeof(Desc));
    cabeca->comeco = -1;
    cabeca->dispo = 0;

    for(i=0;i<TAMANHO-1;i++) cabeca->lista[i].prox = i;
    cabeca->lista[i].prox = -1;

    return cabeca;
}

//inserir na lista ordenada
void insereORdenado(Desc* cabeca, int elemento){
    Cell novo;
    int insert = cabeca->dispo, iprox = cabeca->comeco, anterior = cabeca->comeco;

    if(insert == -1) return;

    novo.valor = elemento;

    //ve se a lista é vazia 
    if(iprox == -1){
        iprox = 0; // primeiro espaço
        cabeca->dispo++;
        novo.prox = -1;

        cabeca->lista[iprox] = novo;
        cabeca->comeco = iprox;

        return;
    }

    //percorrer a lista pra chegar no seu lugar
    while(cabeca->lista[iprox].prox != -1){

        if(cabeca->lista[iprox].valor > novo.valor){
            int aux = cabeca->lista[iprox].prox;
            novo.prox = iprox;
            //inseir na celula disponivel
            cabeca->lista[insert] = novo;
            cabeca->lista[anterior].prox = insert; //no no anterior do iprox vai apontar pro novo
            return;
        }
        //vai mover pro proximo valor
        anterior = iprox; // anterior
        iprox = cabeca->lista[iprox].prox; //atual

    }
    //se chegou em -1 é porque vai ser inserido no final
    

}

//remover elemento

//


int main(){

}
