#include "listav.h"
//#define tipoelem int


Lista::~Lista() {};
void Lista::creaLista(){ lunghezza = 0; }
Lista::Lista(){ Lista::creaLista(); }
bool Lista::listaVuota() const {
	return(lunghezza == 0);
}
Lista::posizione Lista::primoLista() const{
	return(1); // e quindi pos(1)=pos(n+1) se la lista è vuota (n=0)
}
Lista::posizione Lista::succLista(posizione p) const{
	if ( (0 < p) && (p < lunghezza+1)) // precondizione
		return(p+1);
	else 	return(p);
}
Lista::posizione Lista::predLista(posizione p) const{
	if ( (1< p) && (p < lunghezza+1)) // precondizione
		return(p-1);
	else return(p);
}
bool Lista::fineLista(posizione p) const{
	if ( (0 < p) && (p <= lunghezza+1)) // precondizione
		return( p == lunghezza+1);
	else return(false);
}
tipoelem Lista::leggiLista(posizione p) const{
	if ( (0 < p) && (p < lunghezza+1)) // precondizione
		return(elementi[p-1].leggiCella());
}
void Lista::scriviLista(tipoelem a, posizione p){
	if ( (0 < p) && (p < lunghezza+1)) // precondizione
		elementi[p-1].scriviCella(a);//chiamo i metodi di cella
}
void Lista::insLista(tipoelem a, posizione p){
	if ( (0 < p) && (p <= lunghezza+1)) { // precondizione
		for (int i=lunghezza; i>=p; i--)//spostare gli elementi dopo la posizione da inserire
			elementi[i] = elementi[i-1];
		elementi[p-1].scriviCella(a);
		lunghezza++;
	}
}
void Lista::cancLista(posizione p){
	if ( (0 < p) && ( p < lunghezza + 1)) // precondizione
		if (!listaVuota()){ //scalo gli elelmento da dopo p
			for (int i=p-1;i<(lunghezza-1);i++)
				elementi[i]=elementi[i+1];
			lunghezza--;
	}
}
