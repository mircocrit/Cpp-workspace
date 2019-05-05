#ifndef _CODAVT_
#define _CODAVT_

template < class T >
class Coda {
	public:
	  Coda(int n){    maxlung = n;			    creaCoda();}
	  Coda(const Coda<T>& coda);
	  ~Coda(){						delete[] elementi;}
	  void creaCoda(){
		elementi = new T[maxlung];
		testa = 0;		    lung = 0;
	  }
	  bool codaVuota(){  					  return (lung == 0); }
	  T leggiCoda(){  		 if (!codaVuota())   	  return (elementi[testa]);};
	  void fuoriCoda(){
		if (!codaVuota()){
		  testa = (testa + 1) % maxlung;				  lung--;		}
	  }
	  void inCoda(T a){
		if (lung != maxlung){
		  elementi[(testa+lung) % maxlung] = a;			  lung++;		}
	  }
	  Coda<T>& operator=(const Coda<T>& c);
	  bool operator==(const Coda<T> &c) const;
   private:
	  T *elementi;
	  int testa, lung, maxlung;
};

template < class T >
Coda<T>::Coda(const Coda<T>& coda) {
		this->maxlung=coda.maxlung;
		delete[] this->elementi;
		this->elementi = new T[maxlung];
		this->testa = coda.testa;
		this->lung = coda.lung;
		for (int i=0;i<coda.maxlung;i++) {
			   elementi[i]=coda.elementi[i];
		  }
	  }
template < class T >
Coda<T>& Coda<T>::operator=(const Coda<T>& c){
	if (this != &c){
		testa = c.testa;
	  lung = c.lung;
	  maxlung = c.maxlung;
	  delete[] this->elementi;
	  this->elementi = new T[maxlung];
	  for (int i=0;i<c.maxlung;i++) {
		   elementi[i]=c.elementi[i];
	  }
	}
  }

template < class T >
bool Coda<T>::operator==(const Coda<T> &c) const{
	if (c.lung != lung)
		return false;
	for (int i=c.testa;i<c.testa+lung;i++) {
	  if (elementi[(testa+i) % maxlung]!=c.elementi[(testa+i) % maxlung])
		 return false;
	}
	return true;
  }

#endif //CODAVT_
