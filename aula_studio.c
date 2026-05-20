#include<stdio.h>
#include<stdlib.h>

/*questa struttura dati serve rappresentare i posti nel aula.
al interno ha 2 variabili:la prima varibile prende la matricola dello studente
e quando il posto e libero lo imèpone a -1
la seconda variabile prende l ora di occupazione,cioe quando si libera il posto,
per poter aggirnare i posti usado l aggiornamento automatico per orario
*/

struct typedef{
	int status;
	int oraMax;
}posti;

int getStatus(){
	return status;
}
