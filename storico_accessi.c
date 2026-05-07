#include<stdlib.h>
#include<stdio.h>

struct typedef{
    int matricolAcc;//matricola dello studente,nome differente per ridurre confusione
    int tipoAcc;//come ha fatto l accesso l utente
}storico_accessi

storico_accessi creaIst(int a,int b){
    storico_accessi c=(storico_accessi)malloc(sizeof(struct storico_accessi));
    c.matricolAcc=a;
    c.tipoAcc=b;
    return c;
}
void stampaStorico(storico_accessi a){
    printf("matricola studente: %d",a.matricolAcc);
    printf("tipo di accesso: %d",a.tipoAcc);
}
