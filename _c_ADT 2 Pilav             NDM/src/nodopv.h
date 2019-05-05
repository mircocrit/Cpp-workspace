#ifndef _NODOPV_H
#define _NODOPV_H
#include <iostream>

typedef int tipoelem;

class Nodo{
  public:
    Nodo(){}
    Nodo(tipoelem){}
    ~Nodo(){}

    void setElemento(tipoelem label){		  			elemento=label;	 }
    tipoelem getElemento() const{						return elemento;	}
    bool operator ==(Nodo &n){ 	 						return (getElemento() == n.getElemento());  }
  private:
    tipoelem elemento;
  };

std::ostream & operator<<(std::ostream & out, const Nodo & nodo){ 	 return out << nodo.getElemento();};

# endif // _NODOPV_H
