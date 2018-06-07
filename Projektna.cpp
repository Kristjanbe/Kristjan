// Izra�un izkoristka pakirnih linij v proizvodnji

#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int planirana (int, int, int, int, int, int);		//funkcija za izra�un skupne planirane koli�ine
int realizirana (int, int, int, int, int, int);		//funkcija za izra�un skupne realizirane koli�ine
double dnevna (int, int);							//funkcija za izra�un izkoristka realizacije vseh 6 pakirnih linij	

int main ()
{
	int a,b,c,d,e,f,g,h,k,l,m,n;		//spremenljivke planiranih in relaiziranih koli�in v tabelah tab1 in tab2
	int pl,re,dn;		//spremenljivke za skupne vrednosti planiranih in realiziranih koli�in
	int ga, hb, kc, ld, me, nf;		//spremenljivke za vrednosti realizacije posamezne pakirne linije
    char datum[10];		//spremenljivka za podatek o datumu
    
	int x=6;		//inicializacija spremenljivke skupnega �tevila delujo�ih pakirnih linij - prireditev velikosti obeh tabel tab1 in tab2 glede na velikost x 

	//Izpis podatkov o poro�ilu
	
	cout << "Izpis porocila o dnevni realizaciji pakirnih linij v proizvodnji (realizacija glede na planirano in realizirano dnevno kolicino pakirnih linij):" << endl;
	cout << "- realizacija bo prikazana v % za vseh 6 pakirnih linij skupaj in za vsako pakirno linijo posebej" << endl << endl;
	cout << "Izvedite vnos planiranih in realiziranih dnevnih kolicin za izracun % realizacije dnevnega plana pakirnih linij:" << endl;			
	cout << "- skupno stevilo pakirnih linij, ki obratujejo: 6" << endl << endl;

int tab1[x];		//deklaracija tabele velikosti kot je �tevilo delujo�ih linij za vnos planiranih dnevnih koli�in

cout << "Vnos planiranih dnevnih kolicin za posamezno pakirno linijo (ks KI):" << endl;

for (int i=1; i<=x; i++)		//�tevec vpisovanja planiranih koli�in v tabelo tab1

{
	cout << "Planirana dnevna kolicina za " << i << ". pakirno linijo: ";		//vnos planiranih koli�in v tabelo tab1
	cin >> tab1[i];
	a=tab1[1]; b=tab1[2]; c=tab1[3]; d=tab1[4]; e=tab1[5]; f=tab1[6];		//dolo�itev imen polj v tabeli tab1 za uporabo v funkcijah
}
	cout << endl;		

int tab2[x];		//deklaracija tabele velikosti kot je �tevilo delujo�ih linij za vnos realiziranih dnevnih koli�in

cout << "Vnos realiziranih dnevnih kolicin za posamezno pakirno linijo (ks KI):" << endl;

for (int j=1; j<=x; j++)		//�tevec vpisovanja realiziranih koli�in v tabelo tab2

{
	cout << "Realizirana dnevna kolicina za " << j << ". pakirno linijo: ";		//vnos realiziranih koli�in v tabelo tab2
	cin >> tab2[j];
	g=tab2[1]; h=tab2[2]; k=tab2[3]; l=tab2[4]; m=tab2[5]; n=tab2[6];		//dolo�itev imen polj v tabeli tab2 za uporabo v funkcijah
}
	cout << endl;
	
    cout << "Izpis skupne planirane in skupne realizirane dnevne kolicine za vseh 6 pakirnih linij: " << endl;		//za�etek izpisa podatkov za poro�ilo
	
	pl=planirana(a, b, c, d, e, f);
	cout << "- skupna planirana kolicina pakirnih linij (ks KI): "<< pl << endl;		//funkcija planirana - izpis skupne planirane koli�ine
	
	re=realizirana(g, h, k, l, m, n);
	cout << "- skupna realizirana kolicina pakirnih linij (ks KI): "<< re << endl;		//funkcija realizirana - izpis skupne realizirane koli�ine
	
	dn=dnevna(pl, re);
	cout << "- skupni izkoristek pakirnih linij je (v %): "<< dn << " %" << endl << endl;		//funkcija dnevna - izpis izkoristka vseh 6 pakirnih linij
	
	cout << "Izpis izkoristka posamezne pakirne linije (v %):" << endl;		//za�etek izpisa podatkov za poro�ilo - izkoristek posamezne pakirne linije
	
	//ena�be ter izpis za izra�un izkoristka posamezne pakirne linije
	
	ga=(double)g/(double)a*100;		//ena�be ter izpis za izra�un izkoristka posamezne pakirne linije
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
    
    cout << "Vnesi datum za izpis porocila: ";		//izpis datuma za poro�ilo
	cin >> datum;
	
	//kreiranje datoteke poro�ila ter vnos podatkov za kreiranje poro�ila
	
 	ofstream porocilo;
 	porocilo.open("porocilo.xls");
 	porocilo << "Poro�ilo za dan (dan.mesec.leto): " << datum;
 	porocilo << endl << endl;
 	porocilo << "Poro�ilo o dnevni realizaciji pakirnih linij v proizvodnji (realizacija glede na planirano in realizirano dnevno koli�ino pakirnih linij):" << endl;
	porocilo << "- realizacija v % za vseh 6 pakirnih linij skupaj in za vsako pakirno linijo posebej" << endl;		
	porocilo << "- skupno �tevilo pakirnih linij, ki obratujejo: 6" << endl << endl;
	porocilo << "Izkoristek pakirnih linij glede na skupno planirano in skupno realizirano dnevno koli�ino za vseh 6 pakirnih linij: " << endl;
	porocilo << "- skupna planirana koli�ina pakirnih linij (ks KI): "<< pl << endl;
	porocilo << "- skupna realizirana dnevna koli�ina pakirnih linij (ks KI): "<< re << endl;
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

int planirana (int a, int b, int c, int d, int e, int f)		//funkcija planirana - izra�un skupne planirane koli�ine 
{
	int pl;
	pl=a+b+c+d+e+f; 
	return pl;

}

int realizirana (int g, int h, int k, int l, int m, int n)		//funkcija realizirana - izra�un skupne realizirane koli�ine 
{
	int re;
	re=g+h+k+l+m+n; 
	return re;
}

double dnevna (int pl, int re)		//funkcija dnevna - izra�un izkoristka vseh pakirnih linij skupaj 
{
	double dn;
	dn=(double)re/(double)pl*100;
	return dn;
}

