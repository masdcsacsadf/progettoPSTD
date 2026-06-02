typedef struct studente * s;
typedef struct list * l;
typedef struct node * l;

//funzioni studente

int getMatricola(studente s);

void setStato(studente s, int stat);

int getStato(studente s);

void setMatricola(studente s, int m);

void setNome(studente s, char nom);

void setCorso(studente s, char co);

//funzioni lista

list newList(void);

int cicle(int m, list l);

int emptyList(list l);

list consList(studente val, list l);

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
