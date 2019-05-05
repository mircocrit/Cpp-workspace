#include "cellalv.h"

CellaLista::CellaLista() {}
CellaLista::CellaLista(tipoelem label){
	etichetta = label;
}
void CellaLista::scriviCella(tipoelem label){
	etichetta = label;
}
tipoelem CellaLista::leggiCella() const{
	return (etichetta);
}
bool CellaLista::operator==(CellaLista cella){
	return(leggiCella() == cella.leggiCella());
}

