#include<stdlib.h>
#include<stdio.h>
#include<prenotazione.h>
#include<noprenotati.h>
#include<storico_accessi.h>
#include<aula_studio.h>
#include<data.h>
#include<report.h>
#include <studente.h>
/*lo scopo di questo file e quello di contenere tutte le funzioni per far funzionare
il nostro progetto.il motivo di questa scelta e per rendere piu facile la 
manipolazione del codice e il suo debbugging.
FIRMATO da Maxim Zakharov*/

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
    posti sala[100];
    dataCorrente time;
    report rapporto;
    list studenti;
    bool flagLib = 0;
    int limitPren = 0;
}dati;
