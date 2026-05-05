#include <stdio.h>
#include <stdlib.h>
#include "prenotazioni.h"
#include "list.h"

struct node {
    prenotazioni value;
    struct node *next;
};

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

int posItem(list l, item val) {
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

prenotazioni reverseList(list l) {
    list prev = NULL;
    list current = l;
    list next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void outputList(list l) {
    while (l != NULL) {
        output_item(l->value);
        printf(" ");
        l = l->next;
    }
    printf("\n");
}


