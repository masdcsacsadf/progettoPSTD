#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"studente.h"

typedef struct{
    char nome[100];
    int matricola;
    char corso[100];// corso di laurea dello studente
    int stato;
/*variabile 'stato' server per controllare se lo studente :ha il posto =2 o ha prenotato=1 o sta aspettano nella coda di attessa =0, valore neutro = -1 */
}studente;

studente inizializzaStud(){
    studente s;

    s.nome[100]="\0";
    s.matricola=0;
    s.corso[100]="\0";
    s.stato=-1;

    return s;
}

int getMatricola(studente s){
    return s.matricola;
}

void setStato(studente s, int stat){
    s.stato = stat;
}

int getStato(studente s){
    return s.stato;
}

void setMatricola(studente s, int m){
    s.matricola = m;
}

void setNome(studente s, char nom){
    s.nome[LUNG] = nom;
}

void setCorso(studente s, char co){
    s.corso[LUNG] = co;
}


char getNome(studente s){
    return s.nome;
}

char getCorso(studente s){
    return s.corso;
}

studente ricercaMatricola(list3 l, int m){
     while (l!=NULL)
    {
        if (l->value.matricola == m)
        {
            return l->value;
        }

    }

    return NULLITEMSTUD;
}

void ricercaSettaStato(list3 l, int m, int v){
     while (l!=NULL)
    {
        if (l->value.matricola == m)
        {
            setStato(l->value,v);
            return;
        }

    }

    return;
}

struct node {
    studente value;
    struct node *next;
};

list3 newList(void) {
    return NULL;
}


int emptyList(list3 l) {
    return l == NULL;
}


list3 consList3(studente val, list3 l) {
    list3 new_node = (list3)malloc(sizeof(struct node));
    if (new_node == NULL) {
        fprintf(stderr, "Errore: impossibile allocare memoria per il nuovo nodo.\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = val;
    new_node->next = l;
    return new_node;
}


list3 tailList(list3 l) {
    if (emptyList(l)) {
        fprintf(stderr, "Errore: impossibile ottenere la coda di una lista vuota.\n");
        exit(EXIT_FAILURE);
    }
    return l->next;
}


studente getFirst(list3 l) {
    if (emptyList(l)) {
        fprintf(stderr, "Errore: impossibile ottenere il primo elemento di una lista vuota.\n");
        exit(EXIT_FAILURE);
    }
    return l->value;
}


int sizeList(list3 l) {
    int count = 0;
    while (l != NULL) {
        count++;
        l = l->next;
    }
    return count;
}


int posItem(list3 l, studente val) {
    int pos = 1;
    while (l != NULL) {
        if (eq(l->value, val)) {
            return pos;
        }
        pos++;
        l = l->next;
    }
    return -1;
}


studente getItem(list3 l, int pos) {
    int count = 1;
    while (l != NULL) {
        if (count == pos) {
            return l->value;
        }
        count++;
        l = l->next;
    }
    return NULLITEMSTUD;
}

