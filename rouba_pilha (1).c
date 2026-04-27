#include <stdio.h>
#include <stdlib.h>

typedef struct int Carta;

typedef struct {
    Carta carta;
    struct No* prox;
    struct No* anterior;
}No;

typedef struct {
    int jogador;
    int tamanho;
    No* topo;
} Monte;

typedef struct {
    int tamanho;
    No* topo;
}Compras;

typedef struct {
    int tamanho;
    No* primeiro;
    No* ultimo;
}Descarte;

typedef struct {
    int numero;
    Monte* monte;
} Jogador;

/**
funçao que vai criar as cartas
*/

void Cria_Carta();

/**
função que cria os jogadores
*/

/** O jogador que tem a vez de jogar
* retira a carta de cima da pilha de compras
*/

