#include<stdio.h>
#include<stdlib.h>
#include <queue.h>  // Inclusione dell'header file "queue.h", che contiene le dichiarazioni per le funzioni di gestione della coda.

struct typedef{
	int postoAsgn;
	int ora_min;
	int ora_max;
	int matricolaStud;
} nonPrenotati;

int getNoprenMatr(nonPrenotati nop){
	return nop.matricolaStud;
}


struct node {       // Definizione della struttura "node", che rappresenta un singolo nodo nella coda.
     nonPrenotati value;    // Campo "value" di tipo "item" per memorizzare il valore dell'elemento nel nodo.
     struct node *next; // Puntatore "next" al prossimo nodo nella coda.
};

struct c_queue {          // Definizione della struttura "c_queue", che rappresenta la coda.
     struct node *head,*tail; // Puntatori "head" e "tail" rispettivamente al primo e all'ultimo nodo della coda.
     int numel;           // Campo "numel" per tenere traccia del numero di elementi nella coda.
};

queue newQueue(void)   // Definizione della funzione "newQueue", che crea e inizializza una nuova coda.
{
     struct c_queue *q; // Dichiarazione di un puntatore "q" a "struct c_queue".
     q = malloc (sizeof(struct c_queue)); // Allocazione dinamica della memoria per la coda.
     if (q == NULL) // Controllo se l'allocazione della memoria � fallita.
	return NULL; // Restituisce NULL se non c'� abbastanza memoria.

     q->numel = 0;   // Inizializzazione del campo "numel" a 0.
     q->head = NULL; // Inizializzazione del puntatore "head" a NULL.
     q->tail = NULL; // Inizializzazione del puntatore "tail" a NULL.
     return q;       // Restituisce il puntatore alla nuova coda.
} 

int emptyQueue(queue q) // Definizione della funzione "emptyQueue", che controlla se la coda � vuota.
{
     if (q==NULL) // Controlla se il puntatore alla coda � NULL, indicando che la coda non esiste.
            return -1; // Restituisce -1 in questo caso.
     return q->numel == 0; // Restituisce 1 (vero) se la coda � vuota (numel � 0), altrimenti 0 (falso).
}

int enqueue(nonPrenotati val, queue q) // Definizione della funzione "enqueue", che aggiunge un elemento alla coda.
{
    if (q==NULL) // Controlla se il puntatore alla coda � NULL.
            return -1; // Restituisce -1 se la coda non esiste.

    struct node *nuovo; // Dichiarazione di un nuovo nodo "nuovo".
    nuovo = malloc (sizeof(struct node)); // Allocazione dinamica della memoria per il nuovo nodo.
    if (nuovo == NULL) return 0; // Se l'allocazione fallisce, restituisce 0.

    nuovo->value = val; // Imposta il valore del nuovo nodo al valore passato alla funzione.
    nuovo->next= NULL; // Imposta il puntatore "next" del nuovo nodo a NULL.

    if(q->head==NULL) // Controlla se la coda � vuota (head � NULL).
         q->head = nuovo; // Imposta "head" e "tail" al nuovo nodo, poich� � l'unico nodo nella coda.
    else 
         q->tail->next= nuovo; // Se la coda non � vuota, collega il nodo precedente al nuovo nodo.

    q->tail = nuovo; // Imposta "tail" al nuovo nodo, poich� � ora l'ultimo nodo nella coda.
    (q->numel)++;    // Incrementa il numero di elementi nella coda.
    return 1;        // Restituisce 1 per indicare il successo.
}

nonPrenotati dequeue(queue q)
{
      if (q==NULL) return NULLITEM;  // Se il puntatore alla coda � NULL, cio� la coda non esiste, restituisce un valore speciale NULLITEM che indica nessun elemento.

      if (q->numel == 0) return NULLITEM;  // Se la coda � vuota (numel, il contatore degli elementi, � 0), restituisce NULLITEM, indicando che non c'� niente da rimuovere.

      nonPrenotati result = q->head->value;  // Salva l'elemento in testa alla coda (il valore del nodo puntato da head) nella variabile result, che verr� restituito alla fine della funzione.

      struct node *temp = q->head;  // Crea un puntatore temporaneo al nodo attualmente in testa (q->head), in modo da poter liberare questo nodo dopo averlo rimosso dalla coda.

      q->head = q->head->next;  // Avanza il puntatore head al prossimo nodo nella coda, effettivamente rimuovendo l'elemento attuale in testa dalla coda.

      free(temp);  // Libera la memoria allocata per il nodo che � stato appena rimosso dalla coda, prevenendo cos� memory leak.

      if(q->head==NULL)  // Controlla se, dopo la rimozione, la coda � vuota (cio� se head � NULL perch� non ci sono pi� nodi).
             q->tail=NULL;  // Se la coda � ora vuota, anche tail viene impostato a NULL, perch� non ci sono pi� elementi nella coda.

      (q->numel)--;  // Decrementa il contatore degli elementi nella coda, riflettendo la rimozione dell'elemento.

      return result;  // Restituisce l'elemento che era in testa alla coda all'inizio della funzione.
}

