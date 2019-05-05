#ifndef _CELLALP_H
#define _CELLALP_H
//completo

template< class T >
  class Cella{
	public:
		typedef T tipoelem;
		Cella() {}
		Cella(const T& elemento){ this->elemento = elemento; }
		void setElemento(tipoelem e){ elemento = e; }
		tipoelem getElemento() const {return elemento; }
		void setSucc(Cella *p){ succ=p; }
		Cella * getSucc() const{ return succ;}
		void setPrec(Cella *p) { prec=p;}
		Cella * getPrec() const{ return prec;}
	private:
		tipoelem elemento;
		Cella * prec;
		Cella * succ;
};
#endif // _CELLALP_H
