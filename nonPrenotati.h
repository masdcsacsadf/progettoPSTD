
#include"queue.h"

typedef struct nonPrenotati *nonPrenotati;

nonPrenotati inizializzaNoP();
#define NULLITEMNOPR inizializzaNoP()

int getNoprenMatr(nonPrenotati nop);

struct node;

struct c_queue;

queue newQueue(void);

int emptyQueue(queue q);

int enqueue(nonPrenotati val, queue q);

nonPrenotati dequeue(queue q);