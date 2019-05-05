#ifndef _Bin_treecC_H_
#define _Bin_treecC_H_

#include "Bin_tree.h"
#include "exceptions.h"

//ALBERO BINAIRO

template <class T>
class Bin_treec : 										public Bin_tree<T, int>{
    static const int NIL = -1;//////////

  public:
	typedef typename Bin_tree<T, int>::value_type		value_type;					//valore
	typedef typename Bin_tree<T, int>::Nodo 			Nodo;						//nodo

//////////////////////////////////////////
    struct _cella{						//
        Nodo genitore;					//											//padre:sempre intero e' tipo nodo
        Nodo sinistro;					//											//sx
        Nodo destro;					//											//dxt
        value_type valore;				//											//valore contenuto
      };								//
//////////////////////////////////////////
    typedef struct _cella 										Cella;


    Bin_treec(){
    	  MAXLUNG = 100;
    	  spazio = new Cella[MAXLUNG];	    	 		 create();};	//																//costruttori
    Bin_treec(int nNodi):MAXLUNG(nNodi){
    	  spazio = new Cella[nNodi];			    	  create();
    	};
    ~Bin_treec(){   	  erase(inizio);		    	  delete[] spazio;};

    void create();														// crea albero binario
    bool empty() const{						 return(nNodi == 0);};		// restituisce true se albero vuoto
    Nodo root() const{						 return(inizio);};			// restituisce il nodo radice dell'albero
    Nodo is_root(Nodo u) const{				 return(u==inizio);};			// restituisce se  il nodo  e' radice dell'albero
    Nodo parent(Nodo n) const{											// restituisce il nodo padre del nodo
    	if (n != inizio)		    return (spazio[n].genitore);
    	else						return(n);	//radice
    };
    Nodo sx(Nodo n) const{												//restituisce il fratello sinistro del nodo
    	if (!sx_empty(n))    	return (spazio[n].sinistro);
    	else				    return(n);
    };;
    Nodo dx(Nodo n) const{												//restituisce il fratello destro del nodo
    	  if (!dx_empty(n))			    return (spazio[n].destro);
    	  else						    return(n);
    	};
    bool sx_empty(Nodo n) const{   	  	return (spazio[n].sinistro == NIL);}; //restituisce true se non ho fratelli sinistri
    bool dx_empty(Nodo n) const{	  	return (spazio[n].destro == NIL);};	  //restituisce true se non ho fratelli destri

    //void costr(Bin_treec<T>);
    void erase(Nodo);													//elimina nodo

    T read(Nodo n) const{													//legge il nodo e restituisce il contenuto
    	  if (n != NIL)     return (spazio[n].valore);
    		else			throw NullNode();
    	};
    void write(Nodo n, value_type a){										//scrive un valore nel nodo passato in input
    	  if (n != NIL)	    spazio[n].valore = a;
    		else			throw NullNode();
    	};

    void ins_root(Nodo);												//inserisce il nodo nella radice
    void ins_sx(Nodo);													//inserisce il nodo a sinistra di quello passato
    void ins_dx(Nodo);													//inserisce il nodo a destra di quello passato
//////////////////////////////////////
  private:							//
    int MAXLUNG;					//
    Cella *spazio;					//
    int nNodi;						//
    Nodo inizio;					//
    Nodo libera;					//
};									//
									//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Bin_treec<T>::create(){
  inizio = NIL;			//no nodi
  for (int i = 0; i < MAXLUNG; i++){
      spazio[i].sinistro = (i+1) % MAXLUNG;	//sx=i+1
    }
  libera = 0;	//o sx-->1
  nNodi = 0;
}

template <class T>
void Bin_treec<T>::ins_root(Bin_treec<T>::Nodo n){
  if (inizio == NIL){		//1 cosa da fare
      inizio = libera;		//punta a 0
      libera = spazio[libera].sinistro;		//successivo
      spazio[inizio].sinistro = NIL;		//iniizo e radice
      spazio[inizio].destro = NIL;
      nNodi++;
    }
	else
		throw RootExists();
}

template <class T>
void Bin_treec<T>::ins_sx(Nodo n){
	if (inizio == NIL)							throw EmptyTree();
	if (n == NIL)								throw NullNode();
	if (spazio[n].sinistro != NIL)				throw NodeExists();			//esiste fratello sx
	if (nNodi >= MAXLUNG)						throw FullSize();
	else{
      Nodo q = libera;
      libera = spazio[libera].sinistro;
      spazio[n].sinistro = q;				//figlio sx di nodo n
      spazio[q].sinistro = NIL;
      spazio[q].genitore = n;
      spazio[q].destro = NIL;
      nNodi++;
    }
}

template <class T>
void Bin_treec<T>::ins_dx(Nodo n){
	if (inizio == NIL)
		throw EmptyTree();
	if (n == NIL)
		throw NullNode();
	if (spazio[n].destro != NIL)
		throw NodeExists();
	if (nNodi >= MAXLUNG)
		throw FullSize();
	else
    {
      Nodo q = libera;
      libera = spazio[libera].sinistro;
      spazio[n].destro = q;					//
      spazio[q].genitore = n;
      spazio[q].sinistro = NIL;
      spazio[q].destro = NIL;
      nNodi++;
    }
}

template <class T>
void Bin_treec<T>::erase(Nodo n){
  if (n != NIL) {
      if (!sx_empty(n))       							erase(spazio[n].sinistro);
      if (!dx_empty(n))       							erase(spazio[n].destro);
      if (n != inizio) {			//non e' radice
          Nodo p = parent(n);				//
          if (spazio[p].sinistro == n)    	        spazio[p].sinistro = NIL;		//
          else            							spazio[p].destro = NIL;
        }
      else
    	  	  	  	  	  	  	  	  	  inizio = NIL;
      nNodi--;
      spazio[n].sinistro = libera;
      libera = n;
    }
	else		throw NullNode();
}


#endif /* _Bin_treecC_H_ */
