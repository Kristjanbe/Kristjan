// Izraèun izkoristka pakirnih linij v proizvodnji

#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int planirana (int, int, int, int, int, int);		//funkcija za izraèun skupne planirane kolièine
int realizirana (int, int, int, int, int, int);		//funkcija za izraèun skupne realizirane kolièine
double dnevna (int, int);							//funkcija za izraèun izkoristka realizacije vseh 6 pakirnih linij	

int main ()
{
	int a,b,c,d,e,f,g,h,k,l,m,n;		//spremenljivke planiranih in relaiziranih kolièin v tabelah tab1 in tab2
	int pl,re,dn;		//spremenljivke za skupne vrednosti planiranih in realiziranih kolièin
	int ga, hb, kc, ld, me, nf;		//spremenljivke za vrednosti realizacije posamezne pakirne linije
    char datum[10];		//spremenljivka za podatek o datumu
    
	int x=6;		//inicializacija spremenljivke skupnega števila delujoèih pakirnih linij - prireditev velikosti obeh tabel tab1 in tab2 glede na velikost x 

	//Izpis podatkov o poroèilu
	
	cout << "Izpis porocila o dnevni realizaciji pakirnih linij v proizvodnji (realizacija glede na planirano in realizirano dnevno kolicino pakirnih linij):" << endl;
	cout << "- realizacija bo prikazana v % za vseh 6 pakirnih linij skupaj in za vsako pakirno linijo posebej" << endl << endl;
	cout << "Izvedite vnos planiranih in realiziranih dnevnih kolicin za izracun % realizacije dnevnega plana pakirnih linij:" << endl;			
	cout << "- skupno stevilo pakirnih linij, ki obratujejo: 6" << endl << endl;

int tab1[x];		//deklaracija tabele velikosti kot je število delujoèih linij za vnos planiranih dnevnih kolièin

cout << "Vnos planiranih dnevnih kolicin za posamezno pakirno linijo (ks KI):" << endl;

for (int i=1; i<=x; i++)		//števec vpisovanja planiranih kolièin v tabelo tab1

{
	cout << "Planirana dnevna kolicina za " << i << ". pakirno linijo: ";		//vnos planiranih kolièin v tabelo tab1
	cin >> tab1[i];
	a=tab1[1]; b=tab1[2]; c=tab1[3]; d=tab1[4]; e=tab1[5]; f=tab1[6];		//doloèitev imen polj v tabeli tab1 za uporabo v funkcijah
}
	cout << endl;		

int tab2[x];		//deklaracija tabele velikosti kot je število delujoèih linij za vnos realiziranih dnevnih kolièin

cout << "Vnos realiziranih dnevnih kolicin za posamezno pakirno linijo (ks KI):" << endl;

for (int j=1; j<=x; j++)		//števec vpisovanja realiziranih kolièin v tabelo tab2

{
	cout << "Realizirana dnevna kolicina za " << j << ". pakirno linijo: ";		//vnos realiziranih kolièin v tabelo tab2
	cin >> tab2[j];
	g=tab2[1]; h=tab2[2]; k=tab2[3]; l=tab2[4]; m=tab2[5]; n=tab2[6];		//doloèitev imen polj v tabeli tab2 za uporabo v funkcijah
}
	cout << endl;
	
    cout << "Izpis skupne planirane in skupne realizirane dnevne kolicine za vseh 6 pakirnih linij: " << endl;		//zaèetek izpisa podatkov za poroèilo
	
	pl=planirana(a, b, c, d, e, f);
	cout << "- skupna planirana kolicina pakirnih linij (ks KI): "<< pl << endl;		//funkcija planirana - izpis skupne planirane kolièine
	
	re=realizirana(g, h, k, l, m, n);
	cout << "- skupna realizirana kolicina pakirnih linij (ks KI): "<< re << endl;		//funkcija realizirana - izpis skupne realizirane kolièine
	
	dn=dnevna(pl, re);
	cout << "- skupni izkoristek pakirnih linij je (v %): "<< dn << " %" << endl << endl;		//funkcija dnevna - izpis izkoristka vseh 6 pakirnih linij
	
	cout << "Izpis izkoristka posamezne pakirne linije (v %):" << endl;		//zaèetek izpisa podatkov za poroèilo - izkoristek posamezne pakirne linije
	
	//enaèbe ter izpis za izraèun izkoristka posamezne pakirne linije
	
	ga=(double)g/(double)a*100;		//enaèbe ter izpis za izraèun izkoristka posamezne pakirne linije
	cout << "- skupni izkoristek pakirne linije 1 je (v %): "<< ga << " %" << endl;
	
	hb=(double)h/(double)b*100;
	cout << "- skupni izkoristek pakirne linije 2 je (v %): "<< hb << " %" << endl;
	
	kc=(double)k/(double)c*100;
	cout << "- skupni izkoristek pakirne linije 3 je (v %): "<< kc << " %" << endl;
	
	ld=(double)l/(double)d*100;
	cout << "- skupni izkoristek pakirne linije 4 je (v %): "<< ld << " %" << endl;
		
	me=(double)m/(double)e*100;
	cout << "- skupni izkoristek pakirne linije 5 je (v %): "<< me << " %" << endl;
	
	nf=(double)n/(double)f*100;
	cout << "- skupni izkoristek pakirne linije 6 je (v %): "<< nf << " %" << endl << endl;
    
    cout << "Vnesi datum za izpis porocila: ";		//izpis datuma za poroèilo
	cin >> datum;
	
	//kreiranje datoteke poroèila ter vnos podatkov za kreiranje poroèila
	
 	ofstream porocilo;
 	porocilo.open("porocilo.xls");
 	porocilo << "Poroèilo za dan (dan.mesec.leto): " << datum;
 	porocilo << endl << endl;
 	porocilo << "Poroèilo o dnevni realizaciji pakirnih linij v proizvodnji (realizacija glede na planirano in realizirano dnevno kolièino pakirnih linij):" << endl;
	porocilo << "- realizacija v % za vseh 6 pakirnih linij skupaj in za vsako pakirno linijo posebej" << endl;		
	porocilo << "- skupno število pakirnih linij, ki obratujejo: 6" << endl << endl;
	porocilo << "Izkoristek pakirnih linij glede na skupno planirano in skupno realizirano dnevno kolièino za vseh 6 pakirnih linij: " << endl;
	porocilo << "- skupna planirana kolièina pakirnih linij (ks KI): "<< pl << endl;
	porocilo << "- skupna realizirana dnevna kolièina pakirnih linij (ks KI): "<< re << endl;
	porocilo << "- skupni izkoristek vseh 6 pakirnih linij je (v %): "<< dn << " %" << endl << endl;	
	porocilo << "Izkoristek posamezne pakirne linije (v %):" << endl;
	porocilo << "- skupni izkoristek pakirne linije 1 je (v %): "<< ga << " %" << endl;
	porocilo << "- skupni izkoristek pakirne linije 2 je (v %): "<< hb << " %" << endl;
	porocilo << "- skupni izkoristek pakirne linije 3 je (v %): "<< kc << " %" << endl;
	porocilo << "- skupni izkoristek pakirne linije 4 je (v %): "<< ld << " %" << endl;
	porocilo << "- skupni izkoristek pakirne linije 5 je (v %): "<< me << " %" << endl;
	porocilo << "- skupni izkoristek pakirne linije 6 je (v %): "<< nf << " %" << endl;
	porocilo.close();
	
	return 0;
}

int planirana (int a, int b, int c, int d, int e, int f)		//funkcija planirana - izraèun skupne planirane kolièine 
{
	int pl;
	pl=a+b+c+d+e+f; 
	return pl;

}

int realizirana (int g, int h, int k, int l, int m, int n)		//funkcija realizirana - izraèun skupne realizirane kolièine 
{
	int re;
	re=g+h+k+l+m+n; 
	return re;
}

double dnevna (int pl, int re)		//funkcija dnevna - izraèun izkoristka vseh pakirnih linij skupaj 
{
	double dn;
	dn=(double)re/(double)pl*100;
	return dn;
}

