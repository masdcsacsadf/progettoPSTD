#include<stdio.h>
#include<stdlib.h>
#include "data.h"

typedef struct{
	int anno;	
	int mese;	
	int giorno;	//se mese==1 || 3 || 5 || 7 || 8 || 10 || 12  giorno==3	\ se mese==4 || 6 || 9 || 11 giorni==30 \ se mese==2 28 o 29 se bisestile
}data;

typedef struct{
	data datecor;
	int ora;
}dataCorrente;

data inizializzaData(){
	data d;

	d.anno=0;
	d.mese=0;
	d.giorno=0;

	return(d);
}

int getAnnoCorrente(dataCorrente t){
	return t.datecor.anno;
}

data getDataCorrente(dataCorrente t){
    return t.datecor;
}

int getOraCorrente(dataCorrente t){
    return t.ora;
}

int getAnno(data t){
	return t.anno;
}


data impostaData(int a,int m,int g){
	data t;
	t.anno=a;
	if((m==1)||(m==3)||(m=5)||(m==7)||(m==8)||(m==10)||(m==12)){
		if((g>0)&&(g<=31)){
			t.mese=m;
			t.giorno=g;
			return t;
		}
	}
	if((m==4)||(m==6)||(m==9)||(m==11)){
		if((g>0)&&(g<=30)){
			t.mese=m;
			t.giorno=g;
			return t;
		}		
	}
	if(m==2){
		if((a%4==0)&&(a%100!=0)||(a%400==0)){
			if((g>0)&&(g<=29)){
				t.mese=m;
				t.giorno=g;
				return t;
			}	
		}
		if((g>0)&&(g<=28)){
			t.mese=m;
			t.giorno=g;
			return t;
		}	
	}
	t.anno=-1;
	return t;
}

dataCorrente impostaDataCorr(int a, int m, int g, int o){

	dataCorrente dc;

	dc.datecor = impostaData(a,m,g);

	if( dc.datecor.anno == -1){
		printf("ERRORE DATA INCORRETTA");
		dc.ora = -1;
		return dc;
	}else if(o >= 0 && o <= 23){

		printf("ERRORE ORA INCORRETTA");
		dc.ora = -1;
		return dc;
	}
	dc.ora = o;
	return dc;

}


int dataValidCheck(int n, data d, dataCorrente dc){
	if(d.anno < dc.datecor.anno){

		return 1;

	}else if(d.mese < dc.datecor.mese){

		return 1;

	}else if(d.mese == dc.datecor.mese && d.giorno < dc.datecor.giorno){

		return 1;

	}else if(n < dc.ora){

		return 1;

	}
	return 0;
}

int dateUguali(data a,dataCorrente b,int h){
	if((a.anno==b.datecor.anno)&&(a.mese==b.datecor.mese)&&(a.giorno==b.datecor.giorno)&&(h==b.ora)){
		return 1;
	}
	return 0;
}
