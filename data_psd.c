#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int anno;	
	int mese;	
	int giorno;	//se mese==1 || 3 || 5 || 7 || 8 || 10 || 12  giorno==3	\ se mese==4 || 6 || 9 || 11 giorni==30 \ se mese==2 28 o 29 se bisestile
}data;

typedef struct{
	data date;
	int ora;
}dataCorrente;

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
