typedef struct studente *studente;
typedef struct node *list3;
#define LUNG 100
//funzioni studente

studente inizializzaStud();

#define NULLITEMSTUD inizializzaStud();

int getMatricola(studente s);

void setStato(studente s, int stat);

int getStato(studente s);

void setMatricola(studente s, int m);

void setNome(studente s, char nom);

void setCorso(studente s, char co);

//funzioni lista

list3 newList(void);

int cicle(int m, list3 l);

int emptyList(list3 l);

list3 consList3(studente val, list3 l);

//list tailList(list l);
//
//studente getFirst (list l);
//
//int sizeList (list l);
//
//int posItem (list l, studente val);
//
//studente getItem (list l, int pos);
//
//list reverseList (list l);
//
//void outputList (list l);
