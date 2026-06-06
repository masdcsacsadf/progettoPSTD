#include <stdio.h>

typedef struct prenotazioni prenotazioni;

typedef struct node *list;

struct node;

prenotazioni inizializzaPren();

#define NULLITEM inizializzaPren();

int getFlagCheIn(prenotazioni p);

int getMatricolaPRE(prenotazioni t);

int getOraMax(prenotazioni t);

int getOraMin(prenotazioni t);

data getData(prenotazioni t);

void setFlag(prenotazioni p, int n);

void setData(prenotazioni p, data d);

void setMatr(prenotazioni p, int m);

void setMinO(prenotazioni p, int min);

void setMaxO(prenotazioni p, int max);

list newList(void);

int emptyList(list l);

list consList(prenotazioni val, list l);

list tailList(list l);

prenotazioni getFirst(list l);

int sizeList(list l);

prenotazioni getItem(list l, int pos);

list removeList(list l, int pos);

list removeTuttaList(list l, int pos);

void outputList(list l);