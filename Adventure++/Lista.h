#pragma once

#include "Elemento.h"

namespace Lista {
	template<class TIPO>
	class Lista {
	private:
		Elemento<TIPO>* pInicio;
		Elemento<TIPO>* pUltimo;
		unsigned int tamanhoLista;
	public:
		Lista();
		~Lista();
		unsigned int getTamanho();
		void adicionar(TIPO* tipo);
		TIPO* remover(TIPO* tipo);
		TIPO* remover(int posicao);
		TIPO* operator[](int posicao);
		void limpar();
		Elemento<TIPO>* getInicio();
		Elemento<TIPO>* getUltimo();

	};

	template<class TIPO>
	Lista<TIPO>::Lista() {
		pInicio = nullptr;
		pUltimo = nullptr;
		tamanhoLista = 0;
	}

	template<class TIPO>
	Lista<TIPO>::~Lista() {
		pInicio = nullptr;
		pUltimo = nullptr;
	}

	template<class TIPO>
	unsigned int Lista<TIPO>::getTamanho() { return tamanhoLista; }

	template<class TIPO>
	void Lista<TIPO>::adicionar(TIPO* tipo) {
		if (tipo) {
			Elemento<TIPO>* novoElemento = new Elemento<TIPO>();
			novoElemento->setTipo(tipo);
			if (pInicio == nullptr) {
				pInicio = novoElemento;
				pUltimo = novoElemento;
			}
			else {
				novoElemento->setAnterior(pUltimo);
				pUltimo->setProximo(novoElemento);
				pUltimo = novoElemento;
			}
			tamanhoLista++;
		}
		else {
			std::cout << "Ponteiro vazio!" << std::endl;
		}
	}

	template<class TIPO>
	TIPO* Lista<TIPO>::remover(TIPO* tipo) {
		if (pInicio != nullptr && tipo != nullptr) {
			Elemento<TIPO>* pAux1 = pInicio;
			Elemento<TIPO>* pAux3 = nullptr;
			TIPO* pAux2 = nullptr;
			while (pAux1 != nullptr) {
				pAux2 = pAux1->getTipo();
				if (pAux2 == tipo) {
					if (pAux1 == pInicio) {
						pInicio = pAux1->getProximo();
					}
					else if (pAux1 == pUltimo) {
						pUltimo = pAux1->getAnterior();
					}
					else {
						pAux3->setProximo(pAux1->getProximo());
					}
					delete(pAux1);
					tamanhoLista--;
					return tipo;
				}
				pAux3 = pAux1;
				pAux1 = pAux1->getProximo();
				pAux2 = nullptr;
			}
			return nullptr;
		}
		else {
			std::cout << "Ponteiro vazio!" << std::endl;
			return nullptr;
		}
	}

	template<class TIPO>
	TIPO* Lista<TIPO>::remover(int posicao) {
		if (posicao < (int)tamanhoLista && posicao >= 0) {
			Elemento<TIPO>* pAux1 = pInicio;
			Elemento<TIPO>* pAux2 = nullptr;
			TIPO* pAux3 = nullptr;
			for (int i = 0; i < posicao; i++) {
				pAux2 = pAux1;
				pAux1 = pAux1->getProximo();
			}
			pAux3 = pAux1->getTipo();
			if (pAux1 == pInicio) {
				pInicio = pAux1->getProximo();
			}
			else if (pAux1 == pUltimo) {
				pUltimo = pAux1->getAnterior();
			}
			else {
				pAux2->setProximo(pAux1->getProximo());
			}
			pAux3 = pAux1->getTipo();
			delete(pAux1);
			pAux1 = nullptr;
			tamanhoLista--;
			return pAux3;
		}
		else {
			std::cout << "Ponteiro vazio!" << std::endl;
			return nullptr;
		}
	}

	template<class TIPO>
	TIPO* Lista<TIPO>::operator[](int posicao) {
		if (posicao < (int)tamanhoLista && posicao >= 0) {
			Elemento<TIPO>* pAux1 = pInicio;
			TIPO* pAux2 = nullptr;
			for (int i = 0; i < posicao; i++) {
				pAux1 = pAux1->getProximo();
			}
			pAux2 = pAux1->getTipo();
			return pAux2;
		}
		else {
			std::cout << "Posicao da lista invalido!" << std::endl;
			return nullptr;
		}
	}

	template<class TIPO>
	void Lista<TIPO>::limpar() {
		if (tamanhoLista > 0) {
			Elemento<TIPO>* pAux1 = pInicio;
			Elemento<TIPO>* pAux2 = pAux1;
			TIPO* pAux3 = nullptr;

			while (pAux1 != nullptr) {
				pAux3 = pAux1->getTipo();
				delete(pAux3);
				pAux3 = nullptr;
				pAux2 = pAux1->getProximo();
				delete(pAux1);
				pAux1 = pAux2;
				pAux2 = nullptr;
				tamanhoLista--;
			}
			pAux1 = nullptr;
		}
	}

	template<class TIPO>
	Elemento<TIPO>* Lista<TIPO>::getInicio() { return pInicio; }

	template<class TIPO>
	Elemento<TIPO>* Lista<TIPO>::getUltimo() { return pUltimo; }

}