#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"data.h"
#include"prenotazioni.h"



typedef struct{
    int matricolastud;//matricola della struct studenti
    int ora_min;// ora di entrata dello studente nella sala
    int ora_max;//ora  di uscita dello studente dalla sala
    data data;
    int postoass;//il posto asseganto alla prenotazione
    int flagCheckIn;//inidica se lo studente ha fatto il check-in della prnotazione
}prenotazioni;


struct node {
    prenotazioni value;
    struct node *next;
};

int getFlagCheIn(prenotazioni p){
	return p.flagCheckIn;
}

int getMatricolaPRE(prenotazioni t){
	return t.matricolastud;
}

int getOraMax(prenotazioni t){
	return t.ora_max;
}

int getOraMin(prenotazioni t){
	return t.ora_min;
}

data getData(prenotazioni t){
	return t.data;
}

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


list consList(prenotazioni val, list l) {
    list new_node = (list)malloc(sizeof(struct node));
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

list removeList(list l, int pos)
{
    list l1, prec; // l1 è usato per memorizzare temporaneamente il nodo da eliminare, prec per tenere traccia del nodo precedente
    int i;

    if (pos == 0 && l != NULL) { // Se la posizione è 0 e la lista non è vuota, rimuovere il primo nodo
        l1 = l; // l1 punta al primo nodo, che è quello da eliminare
        l = tailList(l); // Imposta l all'inizio della lista escluso il primo nodo (la "coda" della lista)
        free(l1); // Libera la memoria allocata per il nodo eliminato
    }
    else { // Se il nodo da eliminare non è il primo
        i = 0;
        prec = l; // Imposta prec all'inizio della lista
        while (i < pos - 1 && prec != NULL) { // Scorri la lista fino alla posizione precedente a quella del nodo da eliminare
            prec = prec->next; // Sposta prec al nodo successivo
            i++; // Incrementa il contatore
        }

        // Se prec non è NULL, siamo arrivati al nodo che precede quello da eliminare
        if (prec != NULL && prec->next != NULL) { // Verifica che il nodo da eliminare esista (prec->next non sia NULL)
            l1 = prec->next; // l1 punta al nodo da eliminare
            prec->next = l1->next; // Il nodo precedente ora punta al nodo successivo a quello eliminato
            free(l1); // Libera la memoria allocata per il nodo eliminato
        }
    }

    return l; // Restituisce l'inizio della lista, potenzialmente modificato se il primo nodo è stato eliminato
}

list removeTuttaList(list l, int pos){
    list l1; // l1 è usato per memorizzare temporaneamente il nodo da eliminare, prec per tenere traccia del nodo precedente
    int i;
    if (pos == 0 && l != NULL) { // Se la posizione è 0 e la lista non è vuota, rimuovere il primo nodo
        l1 = l; // l1 punta al primo nodo, che è quello da eliminare
        l = tailList(l); // Imposta l all'inizio della lista escluso il primo nodo (la "coda" della lista)
        free(l1); // Libera la memoria allocata per il nodo eliminato
    }
    return l; // Restituisce l'inizio della lista, potenzialmente modificato se il primo nodo è stato eliminato
}

void outputList(list l) {
    while (l != NULL) {
        output_item(l->value);
        printf(" ");
        l = l->next;
    }
}

list creaListaSUP(list l,dataCorrente d){
    int ora,pos=0;
    data temp;
    prenotazioni t;
    list l2;
    while(l!=NULL){
        t=l->value;
        temp=getData(t);
        ora=t.ora_min;
        if(dataValidCheck(ora,temp,d)==1){
            l2=consList(l->value,l2);
        }
        l = l->next;
    }
    return l2;
}

prenotazioni getPrenotazioneControl(list l, dataCorrente t) {
    data temp;
    while (l != NULL) {
        temp=getData(l->value);
        if (dataValidCheck(l->value.ora_min,temp,t)==0){
            return l->value;
        }
        l = l->next;
    }
    return NULLITEM;
    printf("\n");
}
