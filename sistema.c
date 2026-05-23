#include<stdlib.h>
#include<stdio.h>
#include<prenotazione.h>
#include<noprenotati.h>
#include<storico_accessi.h>
#include<aula_studio.h>
#include<data.h>
#include<report.h>
#define LUNG 100
/*lo scopo di questo file e quello di contenere tutte le funzioni per far funzionare
il nostro progetto.il motivo di questa scelta e per rendere piu facile la 
manipolazione del codice e il suo debbugging.
FIRMATO da Maxim Zakharov*/

void prenotazione(dati*t){    
    
    if(t->limitPren >= 50){
        printf("ERRORE: SPAZIO INSUFFICIENTE PER L'OPERAZIONE");
        return;
    }
    
    data temp;
    prenotazioni x;
    int matricola, mese, anno, giorno, minOra, maxOra;

    scanf("%d",&matricola);
    setMatr(x, matricola);

    do{
        scanf("%d",&mese);
        scanf("%d",&anno);
        scanf("%d",&giorno);
        temp=impostaData();

        scanf("%d",&minOra);
        scanf("%d",&maxOra);

    }while((dataValidCheck(minOra,temp,t->time) == 1) && (minOra < 0) || (maxOra > 23) || (minOra >= maxOra))
    
    setMinO(x, minOra);
    setMaxO(x, maxOra);
    setData(x, temp);

    list consList( x, t->prenotazioni); 

    t->limitPren ++;
}


void regStudenti(dati*t){

    studenti x;
    int matricola;
    char nome[],corso[];

    scanf("%d",&matricola);
    setMatr(x, matricola);

    scanf("%c",&nome);
    setNome(x, nome);
    
    scanf("%c",&corso);
    setCorso(x, corso);

    consList(x,t->studenti);
}

/*questa e una struct che contiene dentro di se tutte le strutture dati del sistema
 e variabili di supporto per far lavorare le varie funzioni che si troverano al 
 interno del file
 il suo scoppo e ridurre il numero di parametri al interno delle altre funzioni
 e rendere piu gestibili le nostre stutture dati,soppratutto nella fase di 
 aggiornamento automatico del sistema*/
typedef struct{
    list prenotazioni;
    list noprenotati;
    list storico_accessi;
    posti sala[LUNG];
    dataCorrente time;
    report rapporto;
    list studenti;
    bool flagLib = 0;
    int limitPren = 0;
}dati;
