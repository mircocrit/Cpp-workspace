/*Esercizio 5
Pila senza duplicati modificare l'operatore inPila (con tempo O(n)) per una Pila che non ammette elementi duplicati.

 L     L
 A     L A
 *  A  L
 S     L S
 T     L S T
 I	    L S T I
 *  I  L S T
 N     L S T N
 S     L S T N      (S già presente)
 *  N  L S T
 L     L S T
 I     L S T I      (I già presente)
*/

#include "pilavt.h"

template < class T >
class Pila_dup:    public Pila<T>{
	public:
		void inPilaD (Pila<T> &,T);
};



template < class T >
void Pila_dup<T>::inPilaD (Pila<T> &p,T search){
	int e;									//quax e quella che servira a ripopolare this
	int flag=0;
	Pila<T> qaux(p.get_max()*2);
	qaux.creaPila();

	while(!p.pilaVuota()){
		e = p.leggiPila();
		if (e!=search){
			qaux.inPila(e);
		}else{
			flag=1;
			cout<<"Elemento gia presente!"<<endl;
			qaux.inPila(e);
		}
		p.fuoriPila();
	}
	if(flag==0)		qaux.inPila(search);

	// ripristino della pila originaria
	p.creaPila();
	while ( !qaux.pilaVuota()){
		e = qaux.leggiPila();
		p.inPila(e);
		qaux.fuoriPila();
	}
}




