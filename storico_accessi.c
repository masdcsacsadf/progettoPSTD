#include<stdlib.h>
#include<stdio.h>

struct typedef{
    int matricolAcc;//matricola dello studente,nome differente per ridurre confusione
    int tipoAcc;//come ha fatto l accesso l utente
}storico_accessi

storico_accessi creaIst(int a,int b,storico_accessi c){
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

list2 newList(void) {
    return NULL;
}

int emptyList(list2 l) {
    return l == NULL;
}
list2 consList(int matr, int tipo, list2 l) {
    list2 new_node = (list2)malloc(sizeof(struct node));
    if (new_node == NULL) {
        fprintf(stderr, "Errore: impossibile allocare memoria per il nuovo nodo.\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = creaIst(matr, tipo, new_node -> value);
    new_node->next = l;
    return new_node;
}
list2 rimuoviElementoTesta (list2 l, int pos){
    list2 l1, prec; // puntatore al nodo da eliminare
    int i;
    if(pos == 0 && l != NULL) { // eliminazione in posizione 0
        l1 = l;
        l = tailList(l);
        free(l1);
    }
    return l
}
