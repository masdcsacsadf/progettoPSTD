#include<stdio.h>
#include<stdlib.h>

/*
questa struttura dati serve rappresentare i posti nel aula.
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


/*
getLibero
prende come parametri l array di posti "p" e la dimenstione del array "n"
cerca nel array un posto che ha lo status ==-1.
se lo trova,restituisce la varibile i,usata per ciclare il ciclo
se non lo trova,resituisce -1.
*/
int getLibero(posti p[], int n){
	for(int i=0;i<n; i++){
		if(p[i].status==-1){
			return i;
		}
	}
	return -1; 
}
