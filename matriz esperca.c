#include <stdio.h>
#include <stdlib.h>

typedef struct elem{
    int valor;
    int linha;
    int coluna;
    struct elem *baixo;
    struct elem * direita;
}elem;

typedef struct No{
    int idx;
    elem *elemento;
    struct No *prox;
}No;

typedef struct{
    No *linhas;
    No *colunas;
}Head;

void printValorElem(elem* entrada){
    printf("Valor: %d", entrada->valor);
}

void printCompletoElem(elem* entrada){

    printf("Valor: %d\nLinha: %d\nColuna: %d\n", entrada->valor, entrada->linha, entrada->coluna);

}

elem* criarElem(int valor, int linha, int coluna){
    elem* aux;

    aux = malloc(sizeof(elem));

    aux->valor = valor;
    aux->linha = linha;
    aux->coluna = coluna;
    aux->baixo = NULL;
    aux->direita = NULL;

    return aux;
}

Head* criaMatriz(int linhas,int colunas){
    Head *matriz = malloc(sizeof(Head));
    No *auxlin = malloc(sizeof(No)) ;
    No *auxcol = malloc(sizeof(No));

    matriz->colunas = auxcol;
    matriz->linhas = auxlin;

    auxcol->elemento = NULL;
    auxlin->elemento = NULL;

    auxcol->idx =0;
    auxlin->idx =0;

    for(int i=1;i<linhas;i++){
        No *aux = malloc(sizeof(No));
        aux->prox = NULL;
        aux->elemento = NULL;
        aux->idx = i;
        auxlin->prox = aux;
        auxlin = aux;
    }

    for(int i=1;i<colunas;i++){
        No *aux = malloc(sizeof(No));
        aux->prox = NULL;
        aux->elemento = NULL;
        aux->idx = i;
        auxcol->prox = aux;
        auxcol = aux;
    }

    return matriz;
}

void adicionaElemento(elem* elemento,Head* matriz){
    No* mlinha = matriz->linhas;
    No* mcoluna = matriz->colunas;
    elem *elinha, *ecoluna, *aux;
    int linha = elemento->linha, coluna = elemento->coluna;

    //procurar qual linha esta
    // Procurar a linha
    while(mlinha != NULL && mlinha->idx != linha) {
        printf("idx lin - %d\n",mlinha->idx);
        mlinha = mlinha->prox;
    }

    // Procurar a coluna
    while(mcoluna != NULL && mcoluna->idx != coluna) {
        printf("idx col - %d\n",mcoluna->idx);
        mcoluna = mcoluna->prox;
    }

    //caso seja vazio
    if(mlinha == NULL || mcoluna == NULL) {
        printf("Linha ou coluna nao encontrada!\n");
        return;
    }

    //vou segurar as linhas que esta
    elinha = mlinha->elemento;
    ecoluna = mcoluna->elemento;

    //caso seja o primeiro elemento anexado
    if(elinha == NULL) mlinha->elemento = elemento;
    if(ecoluna == NULL) mcoluna->elemento = elemento;

    // inserir na coluna
    aux = mcoluna->elemento;

    while(ecoluna != NULL){

        if(ecoluna->linha >= elemento->linha){
            break;
        }
        aux = ecoluna;
        ecoluna = ecoluna->baixo;
    }

    // coloca no meio se nao for igual
    if(ecoluna != NULL && ecoluna->linha == elemento->linha){
        printf("Elemento ja existe nessa posicao!\n");
        return;
    }else{
        elemento->baixo = aux->baixo;  // preserva o resto da lista
        aux->baixo = elemento;
    }

    //adicionar na linha
    aux = mlinha->elemento;

    while(elinha != NULL){

        if(elinha->coluna >= elemento->coluna) break;
        aux = elinha;
        elinha = elinha->direita;
    }

    //coloca no meio se n for igual
    if(elinha != NULL && elinha->coluna == elemento->coluna){
        printf("Elemento ja existe nessa posicao!\n");
        return;
    }else{
        elemento->direita = aux->direita;  // preserva o resto da lista
        aux->direita = elemento;
    }

}

int main(){
    Head *matriz = criaMatriz(4,4);
    elem *p1, *p2, *p3;

    p1 = criarElem(10,2,3);
    p2 = criarElem(15,2,2);
    p3 = criarElem(1,3,3);

    printCompletoElem(p1);
    printCompletoElem(p2);
    printCompletoElem(p3);

    adicionaElemento(p1,matriz);
    adicionaElemento(p2,matriz);
    adicionaElemento(p3,matriz);

    return 0;
}
