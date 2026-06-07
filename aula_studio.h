typedef struct posti *posti;

int getStatus();

void resetPostiOra(posti p[],int n,int ora);

int getLibero(posti p[], int n);

void puliziaAulaStudio(posti a[],int n);

posti setDatiPosto(posti p,int m,int ora);