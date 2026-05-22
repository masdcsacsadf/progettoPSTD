#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct typedef{
    char nome[100];
    int matricola;
    char corso[100];// corso di laurea dello studente
    int stato;
/*variabile 'stato' server per controllare se lo studente :ha il posto =2 o ha prenotato=1 o sta aspettano nella coda di attessa =0 */
}studente;

int getMatricola(studente s){
    return s.matricola;
}

void setStato(studente s, int stat){
    s.stato = stat;
}

int getStato(studente s){
    return s.status;
}

void setMatricola(studente s, int m){
    s.matricola = m;
}

void setNome(studente s, char nom){
    s.nome = nom;
}

void setCorso(studente s, char co){
    s.corso = co;
}


char getNome(studente s){
    return s.nome;
}

char getCorso(studente s){
    return s.corso;
}

struct node {
    studente value;
    struct node *next;
};

list newList(void) {
    return NULL;
}


int emptyList(list l) {
    return l == NULL;
}


list consList(studente val, list l) 
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


studente getFirst(list l) {
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


int posItem(list l, studente val) {
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


studente getItem(list l, int pos) {
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
