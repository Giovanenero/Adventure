#pragma once

#include <iostream>

namespace Lista {
	template <class TIPO>
	class Elemento {
	private:
		Elemento<TIPO>* proximo;
		Elemento<TIPO>* anterior;
		TIPO* tipo;
	public:
		Elemento();
		~Elemento();
		void setProximo(Elemento<TIPO>* proximo);
		void setAnterior(Elemento<TIPO>* anterior);
		void setTipo(TIPO* tipo);
		Elemento<TIPO>* getProximo();
		Elemento<TIPO>* getAnterior();
		TIPO* getTipo();
	};
	template <class TIPO>
	Elemento<TIPO>::Elemento():
		proximo(nullptr),
		anterior(nullptr),
		tipo(nullptr) { }

	template <class TIPO>
	Elemento<TIPO>::~Elemento() {
		proximo = nullptr;
		anterior = nullptr;
		tipo = nullptr;
	}

	template <class TIPO>
	void Elemento<TIPO>::setProximo(Elemento<TIPO>* proximo) { this->proximo = proximo; }

	template <class TIPO>
	void Elemento<TIPO>::setAnterior(Elemento<TIPO>* anterior) { this->anterior = anterior; }

	template <class TIPO>
	void Elemento<TIPO>::setTipo(TIPO* tipo) { this->tipo = tipo; }

	template <class TIPO>
	Elemento<TIPO>* Elemento<TIPO>::getProximo() { return proximo; }

	template <class TIPO>
	Elemento<TIPO>* Elemento<TIPO>::getAnterior() { return anterior; }

	template <class TIPO>
	TIPO* Elemento<TIPO>::getTipo() { return tipo; }
}