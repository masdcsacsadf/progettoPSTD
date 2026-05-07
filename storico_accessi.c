#include<stdlib.h>
#include<stdio.h>

struct typedef{
    int matricolAcc;//matricola dello studente,nome differente per ridurre confusione
    int tipoAcc;//come ha fatto l accesso l utente
}storico_accessi

storico_accessi creaIst(int a,int b){
    storico_accessi c=(storico_accessi)malloc(sizeof(struct storico_accessi));
    c.matricolAcc=a;
    c.tipoAcc=b;
    return c;
}
void stampaStorico(storico_accessi a){
    printf("matricola studente: %d",a.matricolAcc);
    printf("tipo di accesso: %d",a.tipoAcc);
}
struct node {
    storico_accessi value;
    struct node *next;
};

list newList(void) {
    return NULL;
}

int emptyList(list l) {
    return l == NULL;
}
list consList(storico_accessi val, list l) {
    list new_node = (list)malloc(sizeof(struct node));
    if (new_node == NULL) {
        fprintf(stderr, "Errore: impossibile allocare memoria per il nuovo nodo.\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = val;
    new_node->next = l;
    return new_node;
}
