#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<data_psd.h>
#include "list.h"

struct typedef{
    int matricolastud;//matricola della struct studenti
    int ora_min;// ora di entrata dello studente nella sala
    int ora_max;//ora  di uscita dello studente dalla sala
    data data;
    int postoass;//il posto asseganto alla prenotazione
    int flagCheckIn;//inidica se lo studente ha fatto il check-in della prnotazione
}prenotazioni


struct node {
    prenotazioni value;
    struct node *next;
};

void setFlag(prenotazioni p, int n){
    p.flagCheckIn = n;
}

void setData(prenotazioni p, data d){
    p.data = d;
}


void setMatr(prenotazioni p, int m){
    p.matricolastud = m;
}

void setMinO(prenotazioni p, int min){
    p.ora_min = min;
}

void setMaxO(prenotazioni p, int max){
    p.ora_max = max;
}

list newList(void) {
    return NULL;
}


int emptyList(list l) {
    return l == NULL;
}


list consList(prenotazioni val, list l) 
    list new_node = (list)malloc(sizeof(
    if (new_node == NULL) {
        fprintf(stderr, "Errore: impossibile allocare memoria per il nuovo nodo.\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = val;
    new_node->next = l;
    return new_node;
}


list tailList(list l) {
    if (emptyList(l)) {
        fprintf(stderr, "Errore: impossibile ottenere la coda di una lista vuota.\n");
        exit(EXIT_FAILURE);
    }
    return l->next;
}


prenotazioni getFirst(list l) {
    if (emptyList(l)) {
        fprintf(stderr, "Errore: impossibile ottenere il primo elemento di una lista vuota.\n");
        exit(EXIT_FAILURE);
    }
    return l->value;
}


int sizeList(list l) {
    int count = 0;
    while (l != NULL) {
        count++;
        l = l->next;
    }
    return count;
}



prenotazioni getItem(list l, int pos) {
    int count = 1;
    while (l != NULL) {
        if (count == pos) {
            return l->value;
        }
        count++;
        l = l->next;
    }
    return NULLITEM;
}





void outputList(list l) {
    while (l != NULL) {
        output_item(l->value);
        printf(" ");
        l = l->next;
    }
    printf("\n");
}
