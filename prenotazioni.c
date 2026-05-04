#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<data_psd.h>

struct typedef{
    int matricolastud;//matricola della struct studenti
    int ora_min;// ora di entrata dello studente nella sala
    int ora_max;//ora  di uscita dello studente dalla sala
    data_psd data;
    int postoass;//il posto asseganto alla prenotazione
    int flagCheck-in//inidica se lo studente ha fatto il check -ni della prnotazione
}prenotazioni