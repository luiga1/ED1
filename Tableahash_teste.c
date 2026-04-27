#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

/* Cada entrada é um nó de lista ligada */
typedef struct Node {
    char *key;
    char *value;
    struct Node *next;  /* aponta para o próximo nó (colisão) */
} Node;

/* A tabela é um array de ponteiros para Node */
typedef struct {
    Node *buckets[TABLE_SIZE];
} HashTable;

/* ── Função hash ──────────────────────────────────────────────
   Soma os valores ASCII da chave e aplica módulo pelo tamanho.
   Simples, mas funciona bem para demonstração.              */
unsigned int hash(const char *key) {
    unsigned int h = 0;
    while (*key) {
        h += (unsigned char)(*key);
        key++;
    }
    return h % TABLE_SIZE;
}

/* ── Inicializa a tabela (todos os buckets = NULL) ──────────*/
HashTable *ht_create() {
    HashTable *ht = malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++)
        ht->buckets[i] = NULL;
    return ht;
}

/* ── Inserção ───────────────────────────────────────────────*/
void ht_insert(HashTable *ht, const char *key, const char *value) {
    unsigned int idx = hash(key);

    /* Verifica se a chave já existe → atualiza valor */
    Node *curr = ht->buckets[idx];
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            free(curr->value);
            curr->value = strdup(value);
            return;
        }
        curr = curr->next;
    }

    /* Cria novo nó e insere no início da lista (O(1)) */
    Node *node = malloc(sizeof(Node));
    node->key   = strdup(key);
    node->value = strdup(value);
    node->next  = ht->buckets[idx];   /* encadeia com os existentes */
    ht->buckets[idx] = node;
}

/* ── Busca ──────────────────────────────────────────────────*/
char *ht_get(HashTable *ht, const char *key) {
    unsigned int idx = hash(key);
    Node *curr = ht->buckets[idx];
    while (curr) {
        if (strcmp(curr->key, key) == 0)
            return curr->value;
        curr = curr->next;
    }
    return NULL;  /* não encontrado */
}

/* ── Remoção ────────────────────────────────────────────────*/
void ht_remove(HashTable *ht, const char *key) {
    unsigned int idx = hash(key);
    Node *curr = ht->buckets[idx];
    Node *prev = NULL;

    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            if (prev) prev->next = curr->next;
            else      ht->buckets[idx] = curr->next;
            free(curr->key);
            free(curr->value);
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

/* ── Libera toda a memória ─────────────────────────────────*/
void ht_free(HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *curr = ht->buckets[i];
        while (curr) {
            Node *next = curr->next;
            free(curr->key);
            free(curr->value);
            free(curr);
            curr = next;
        }
    }
    free(ht);
}

/* ── Demonstração ──────────────────────────────────────────*/
int main() {
    HashTable *ht = ht_create();

    ht_insert(ht, "nome",   "Ana");
    ht_insert(ht, "nome",   "Pedro");
    ht_insert(ht, "idade",  "28");
    ht_insert(ht, "cidade", "sao Paulo");
    ht_insert(ht, "email",  "ana@exemplo.com");

    printf("nome -> %s\n", ht_get(ht, "nome"));
    printf("cidade -> %s\n", ht_get(ht, "cidade"));

    ht_insert(ht, "nome", "Carlos");  /* atualiza */
    printf("nome (atualizado) -> %s\n", ht_get(ht, "nome"));

    ht_remove(ht, "email");
    printf("email apos remoção -> %s\n",
           ht_get(ht, "email") ? ht_get(ht, "email") : "(null)");

    ht_free(ht);
    return 0;
}
