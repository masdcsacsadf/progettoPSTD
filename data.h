typedef struct data *data;

typedef struct dataCorrente *dataCorrente;

data inizializzaData();

#define NULLITEM inizializzaData();

int getAnno(data t);

data impostaData(int a,int m,int g);

data getDataCorrente(dataCorrente t);

int getAnnoCorrente(dataCorrente t);

int getOraCorrente(dataCorrente t);

dataCorrente impostaDataCorr(int a, int m, int g, int o);

int dataValidCheck(int n, data d, dataCorrente dc);

int dateUguali(data a,dataCorrente b,int h);