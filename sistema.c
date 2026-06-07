#include<stdlib.h>
#include<stdio.h>
#include"prenotazioni.h"
#include"nonPrenotati.h"
#include"storicoAccessi.h"
#include"aula_studio.h"
#include"data.h"
#include"report.h"
#include "studente.h"
#include"sistema.h"
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
    queue noprenotati;
    list2 storicoAccessi;
    posti sala[LUNG];
    dataCorrente time;
    report rapporto;
    list3 studente;
}dati;


void aggiornamentoSistemaSelect(dati* t){
    int a,m,g,o,flag,oramax,oramin;
    data lol;
    dataCorrente m;
    do{
        scanf("%d",&m);
        scanf("%d",&a);
        scanf("%d",&g);
        scanf("%d",&o);
        m=impostaDataCorr(a,m,g,o);
        lol=getDataCorrente(m);
        flag=dataValidCheck(o,lol,t->time);
    }while((getOraCorrente(m)==-1)||(flag==1));
    if(getOraCorrente(m)>getOraCorrente(t)){
        assegnamentoPosto(t);
        return;
    }
    if(dateUguali(lol,t->time,o)==0){//riutillizo dela funzione "dateUguali" per contrllare se le date sono diverse
        oramax=getOraCorrente(t->time);
        t->rapporto=setOraMax(t->rapporto,oramax);
        stampa(t->rapporto);
        t->time=m;
        t->rapporto=setOraMin(t->rapporto,o);
        aggirnamentoSistemaOrario(t);
        assegnamentoPosto(t);
    }
}

void aggirnamentoSistemaOrario(dati*t){
    list l2;
    nonPrenotati non;
    while(emptylist(t->storicoAccessi)!=1){
        t->storicoAccessi=removeList(t->storicoAccessi,0);
    }
    while(emptyQueue(t->noprenotati)!=1){
        non=dequeue(t->noprenotati);
        free(non);
    }
    l2=creaListaSUP(t->prenotazioni,t->time);
    while(emptyList(t->prenotazioni)!=1){
        t->prenotazioni=removeList(t->prenotazioni,0);
    }
    t->prenotazioni=l2;
    free(l2);
    puliziaAulaStudio(t->sala,LUNG);
}


void assegnamentoPosto(dati* t){
    int pretot=0,accessot=0,stuattessa=0;
    prenotazioni temp;
    int matr,oramax,oraCor;
    nonPrenotati nopre;
    oraCor=getOraCorrente(t->time);
    resetPostiOra(t->sala,LUNG,oraCor);
    for(int i=0;i<LUNG;i++){
        if(getStatus(t->sala[i])!=-1){
            temp=getPrenotazioneControl(t->prenotazioni,t->time);
            if((temp!=inizializzaPren())){
                matr=getMatricolaPRE(temp);
                oramax=getOraMax(temp);
                t->sala[i] = setDatiPosto( t->sala[i], matr, oramax);
                t->storicoAccessi=consList2(matr,1,t->storicoAccessi);
                pretot--;
                accessot++;
            }
        }
    }
    for (int i = 0; i < LUNG; i++)
    {
        if (getStatus(t->sala[i])!=-1)
        {
            nopre = dequeue(t->noprenotati);
            matr = getNoprenMatr(nopre);
            oramax= getOraCorr(t->time) +1;
            t->sala[i] = setDatiPosto( t->sala[i], matr, oramax);
            t->storicoAccessi=consList2(matr,0,t->storicoAccessi);
            stuattessa--;
            accessot++;
        }
    }
    t->rapporto=setPreTot( t->rapporto,pretot);
    t->rapporto=seTaccessoT( t->rapporto,accessot);
    t->rapporto=setStuAttessa( t->rapporto,stuattessa);
}

void prenotazione(dati*t){    
    data temp;
    prenotazioni x;
    int matricola, mese, anno, giorno, minOra, maxOra, pos;

    scanf("%d",&matricola);
    if (ricercaMatricola(matricola, t->studente)==inizializzaStud())
    {
        printf("ERRORE, MATRICOLA NON TROVATA, REGISTRATI O RITENTA");
        return;
    }
 

    do{
        scanf("%d",&mese);
        scanf("%d",&anno);
        scanf("%d",&giorno);
        temp=impostaData(anno,mese,giorno);

        scanf("%d",&minOra);
        scanf("%d",&maxOra);

    }while((dataValidCheck(minOra,temp,t->time) == 1) && (minOra < 0) || (maxOra > 23) || (minOra >= maxOra));
    
    setMinO(x, minOra);//questi sono di prenotazione
    setMaxO(x, maxOra);//questi sono di prenotazione
    setData(x, temp);//questi sono di prenotazione
    setMatr(x, matricola);//questi sono di prenotazione


    ricercaSettaStato(t->studente, matricola, 1);
    consList( x, t->prenotazioni); 
    
  
}

void coda(dati*t){

    studente x;
    int matricola,temp;
    scanf("%d",&matricola);
    if (ricercaMatricola(matricola, t->studente)==inizializzaStud())
    {
        printf("ERRORE, MATRICOLA NON TROVATA, REGISTRATI O RITENTA");
        return;
    }
    
    temp=(enqueue(x,t->noprenotati));
    if (temp!=1)
    {
        printf("ERRORE");
        return;
    }
    ricercaSettaStato(t->studente, matricola, 0);
    return;

}

void selectCheck(dati*t,int m){

    data d;
    int temp,mese,giorno,anno;
    do
    {

        scanf("%d",&temp);

    } while (temp!=1 || temp!=0);

    do{
        scanf("%d",&mese);
        scanf("%d",&anno);
        scanf("%d",&giorno);
        d=impostaData(anno,mese,giorno);

    }while(getAnno(d)==-1);
    

    if (ricercaMatricola(m, t->studente)==inizializzaStud()){
        return;
    }
    
    if(temp==1){
        checkIn( getMatricola(t->studente), getOraMin(t->prenotazioni), d, t);
    }if(temp==0){
        checkOut(getMatricola(t->studente), getOraMin(t->prenotazioni), d, t);
    }
}

void checkIn(int m,int h,data d, dati*t){
    
    if (ciclo(t->prenotazioni, d, h, m) == inizializzaPren()){
        printf("PRENOTAZIONE NON TROVATA");
        return;
    }
}

void checkOut(int m,int h,data d, dati*t){
    
    t->prenotazioni = checkOutFind(t->prenotazioni, h, d, m);
    ricercaSettaStato(t->studente, m, -1);
}

void regStudenti(dati*t){

    studente x;
    int matricola;
    char nome[LUNG],corso[LUNG];

    scanf("%d",&matricola);
    setMatr(x, matricola);

    scanf("%c",&nome);
    setNome(x, nome);
    
    scanf("%c",&corso);
    setCorso(x, corso);

    consList(x,t->studente);
}