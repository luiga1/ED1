#inclide <stdio.h>
#inclide <stdlib.h>

typedef struct elem {
    int valor;
    int linha;
    int coluna;
    elem* baixo;
    elem* direita;
}elem;

typedef struct No{
    int idx;
    elem* elemento;
    No* ant;
    No* prox;
}No



void inserirElemBaixo(elem* prox, elem* atual){
    elem* aux = primeiro;

    while(aux->baixo != null){
        aux = aux->baixo;
    }

    aux->baixo = prox;
    prox->baixo = null;
}

void inserirElemDireita(elem* prox, elem* primeiro){
    elem* aux = primeiro;

    while(aux->direita != null){
        aux = aux->direita;
    }

    aux->direita = prox;
    prox->direita = null;

}

void printValorElem(elem* entrada){
    printf("Valor: %d", entrada.valor);
}

void printCompletoElem(elem* entrada){

    printf("Valor: %d\nLinha: %d\nColuna: %d\n", entrada.valor, entrada.linha, entrada.coluna);

}

elem* criarElem(int valor, int linha, int coluna){
    elem* aux;

    aux.valor = valor;
    aux.linha = linha;
    aux.coluna = coluna;

    return aux;
}

int main(){

}
