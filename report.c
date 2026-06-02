#include<stdlib.h>
#include<stdio.h>

typedef struct{
  int preTot;
  int accessoT;
  int noShow;
  int stuAttesa;
  int oraMin;    //oraMin e oraMax serve per mostrare la fascio oraria occupata nella sala in media
  int oraMax;
}report;

report setPreTot(report t,int n){
  t.preTot=t.preTot+n;
  return t;
}
report setAccessoT(report t,int n){
  t.accessoT=t.accessoT+n;
  return t;
}
report setNoshow(report t,int n){
  t.noShow=t.noShow+n;
  return t;
}
report setStuAttessa(report t,int n){
  t.stuAttesa=t.stuAttesa+n;
  return t;
}
report setOraMin(report t,int n){
  t.oraMin=n;
  return t;
}
report setOraMax(report t,int n){
  t.oraMax=n;
  return t;
}

void stampa(report t){
  printf("prenotazione totali=%d\n accessi totali= %d\n studenti assentati= %d\n studenti in attesa= %d\n ora minima= %d\n ora massima= %d", &t.preTot, &t.accessoT, &t.noShow, &t.stuAttesa, &t.oraMin, &t.oraMax);
}