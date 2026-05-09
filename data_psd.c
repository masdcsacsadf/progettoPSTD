#include<stdio.h>
#include<stdlib.h>

struct typedef{
	int anno;	
	int mese;	
	int giorno;	//se mese==1 || 3 || 5 || 7 || 8 || 10 || 12  giorno==3	\ se mese==4 || 6 || 9 || 11 giorni==30 \ se mese==2 28 o 29 se bisestile
}data;

struct typedef{
	data date;
	int ora;
}dataCorrente;
