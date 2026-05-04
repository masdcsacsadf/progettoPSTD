#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct typedef{
    char nome[100];
    int matricola;
    char corso[100];// corso di laurea dello studente
    int stato;
/*variabile 'stato' server per controllare se lo studente :ha il posto =2 o ha prenotato=1 o sta aspettano nella coda di attessa =0 */
}studente;