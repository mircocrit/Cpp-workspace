template<class T>
class listaLineare{
	public:
		typedef int tipoelem;
		typedef int posizione;

		virtual ~listaLineare() {}	// distruttore
		// operatori
		virtual void creaLista();
		virtual bool listaVuota() const;
		virtual tipoelem leggiLista(posizione) const;
		virtual void scriviLista(tipoelem, posizione);
		virtual posizione primoLista() const;
		virtual bool fineLista(posizione) const;
		virtual posizione succLista(posizione) const;
		virtual posizione predLista(posizione) const;
		virtual void insLista(tipoelem, posizione);
		virtual void cancLista(posizione);
};
