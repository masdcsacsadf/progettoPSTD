#include<stdlib.h>
#include<stdio.h>

typedef struct{
  int preTot
  int accessoT
  int noShow
  int stuAttesa
  int oraMin    //oraMin e oraMax serve per mostrare la fascio oraria occupata nella sala in media
  int oraMax
}report;

report setPreTot(report t,int n){
  t.preTot=n;
  return t;
}
report seTaccessoT(report t,int n){
  t.accessoT=n;
  return t;
}
report setNoshow(report t,int n){
  t.noShow=n;
  return t;
}
report setStuAttessa(report t,int n){
  t.stuAttessa=n;
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
