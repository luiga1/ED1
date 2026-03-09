/**
 * Conversor de expreções infixas para posfixas(notação polonesa)
 * Luis Miguel
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int precedencia(char obj){
    if(obj == '+' || obj == '-') return 1;
    if(obj == '*' || obj == '/') return 2;
    return 0;
}

void infixaParaPosfixa(char* exp, char* pox){
    char pilha[100];
    char aux;
    int poxt = 0;
    int topo = -1;

    for(int i=0; exp[i] != '\0';i++){

        if(precedencia(exp[i]) == 0){
            
            if(exp[i] == '('){
                pilha[topo++] = exp[i]; // empilhar e começa a dar preferencia aos operadoes dos parenteses
            }

            if(exp[i] == ')'){
                aux = pilha[--topo];
                while(aux != '('){// vai desempilhar os operadores dos parenteses
                    pox[poxt++] = aux;
                    aux = pilha[--topo];
                }
            }

            else {
                if(exp[i] == ' ') // ignorar espaços
                pox[poxt++] = exp[i]; //copiar os operandos
            }
        }

        if(precedencia(exp[i] == 1)){
            while(topo>0 && pilha[topo-1] != '('){
                pox[poxt++] = pilha[topo--];
            }
            pilha[topo++] = exp[i];
        }

        if(precedencia(exp[i]) == 2){
            while(topo>0 && pilha[topo-1] != '(' && precedencia(pilha[topo-1]) != 1){
                pox[poxt++] = pilha[topo--];
            }
            pilha[topo++] = exp[i];
        }

    }
    while(topo>0){
        pox[poxt++] = pilha[topo--];
    }
    pox[poxt] = '\0';

}

int main(){

    char expressao[100];
    char* resultado = malloc(sizeof(char) * 101);
    printf("digite a expressão");
    scanf("%s",expressao);
    printf("Infixa: %s\n", expressao);
    infixaParaPosfixa(expressao, resultado);
    printf("%s",resultado);
    return 0;
}