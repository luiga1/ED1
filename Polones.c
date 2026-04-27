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
    char atual;
    int poxt = 0;
    int topo = -1;

    for(int i=0; exp[i] != '\0';i++){
        atual = exp[i];

        if(atual == ' ') // ignorar espaços
            continue;

        if(precedencia(atual) == 0){
            
            if(atual == '('){
                pilha[++topo] = atual; // vai empilhar o ( para saber a referencia
            } 
            else if(atual == ')'){
                while(pilha[topo] != '('&& topo > -1){// vai desempilhar os operadores dos parenteses
                    pox[poxt++] = pilha[topo--];
                }
                if(topo > -1)topo--; // remove o parenteses
            }
            else {
                pox[poxt++] = atual; //copiar os operandos
            }
        }

        else{
            while (topo >= 0 && pilha[topo] != '(' && precedencia(pilha[topo]) >= precedencia(atual)) { // se o operador for maior ou igual desempilha
                pox[poxt++] = pilha[topo--];
            }
            pilha[++topo] = atual;
        }

    }
    while(topo>-1){
        pox[poxt++] = pilha[topo--]; // desempilhar o final da pilha apos terminar todo a expressão
    }
    pox[poxt] = '\0';


}

int main(){
    char expressao[100];
    char resultado[100]; // Simplificado para array fixo

    printf("Digite a expressao");
    scanf("%s", expressao);

    infixaParaPosfixa(expressao, resultado);

    printf("Infixa: %s\n", expressao);
    printf("Posfixa: %s\n", resultado);

    return 0;
}
