#pragma once

#include <iostream>

namespace Lista {
	template<class TIPO>
	class Lista {
	private:
		template<class TIPO>
		class Elemento {
		private:
			Elemento<TIPO>* proximo;
			TIPO* tipo;
		public:
			Elemento():
				proximo(nullptr), tipo(nullptr) { }
			
			~Elemento() { }

			void setProximo(Elemento<TIPO>* proximo) { this->proximo = proximo; }
			void setTipo(TIPO* tipo) { this->tipo = tipo; }
			
			Elemento<TIPO>* getProximo() { return proximo; }
			TIPO* getTipo() { return this->tipo; }
		};
	private:
		Elemento<TIPO>* pInicio;
		Elemento<TIPO>* pUltimo;
		unsigned int tamanhoLista;
	public:
		Lista();
		~Lista();
		unsigned int getTamanho();
		void adicionar(TIPO* tipo);
		void remover(TIPO* tipo);
		void remover(int posicao);
		TIPO* operator[](int posicao);
		Elemento<TIPO>* getInicio() {
			return pInicio;
		}
		Elemento<TIPO>* getUltimo() {
			return pUltimo;
		}

	};

	template<class TIPO>
	Lista<TIPO>::Lista():
		pInicio(nullptr), pUltimo(nullptr), tamanhoLista(0) { }

	template<class TIPO>
	Lista<TIPO>::~Lista() {
		if (pInicio != nullptr) {
			Elemento<TIPO>* pAux1 = pInicio;
			Elemento<TIPO>* pAux2 = nullptr;
			TIPO* pAux3 = pAux1->getTipo();
			while (pAux1 != nullptr) {
				delete(pAux3);
				pAux3 = nullptr;
				pAux2 = pAux1->getProximo();
				pAux1 = pAux2;
			}
			pAux2 = nullptr;
			pInicio = nullptr;
			pUltimo = nullptr;
			tamanhoLista = 0;
		}
	}

	template<class TIPO>
	unsigned int Lista<TIPO>::getTamanho() { return tamanhoLista; }

	template<class TIPO>
	void Lista<TIPO>::adicionar(TIPO* tipo) {
		if (tipo != nullptr) {
			Elemento<TIPO>* novoElemento = new Elemento<TIPO>();
			novoElemento->setTipo(tipo);
			if (novoElemento == nullptr) {
				std::cout << "ERRO: novoElemento vazio!" << std::endl;
				exit(1);
			}
			if (pInicio == nullptr) {
				pInicio = novoElemento;
				pUltimo = novoElemento;
			}
			else {
				pUltimo->setProximo(novoElemento);
				//novoElemento->setAnterior(pUltimo);
				pUltimo = novoElemento;
			}
			tamanhoLista++;
		}
		else {
			std::cout << "Ponteiro vazio!" << std::endl;
		}
	}

	template<class TIPO>
	void Lista<TIPO>::remover(TIPO* tipo) {
		if (tipo != nullptr) {
			Elemento<TIPO>* pAux1 = pInicio;
			Elemento<TIPO>* pAux3 = nullptr;
			TIPO* pAux2 = nullptr;
			while (pAux1 != nullptr) {
				pAux2 = pAux1->getTipo();
				if (pAux2 == tipo) {
					if (pAux1 == pInicio) {
						pInicio = pAux1->getProximo();
					}
					/*
					else if (pAux1 == pUltimo) {
						pUltimo = pAux1->getAnterior();
					}
					*/
					else if(pAux1 == pUltimo) {
						pUltimo = pAux3;
						pAux3->setProximo(nullptr);
					}
					else {
						pAux3->setProximo(pAux1->getProximo());
					}
					if (pAux2 != nullptr) {
						delete(pAux2);
						pAux2 = nullptr;
					}
					//pAux1 = nullptr;
					tamanhoLista--;
				}
				pAux3 = pAux1;
				pAux1 = pAux1->getProximo();
				pAux2 = nullptr;
			}
		}
		else {
			std::cout << "Ponteiro vazio!" << std::endl;
		}
	}

	template<class TIPO>
	void Lista<TIPO>::remover(int posicao) {
		if (posicao >= (int)tamanhoLista || posicao < 0) {
			std::cout << "ERRO: posicao invalida!" << std::endl;
			exit(1);
		}
		Elemento<TIPO>* pAux1 = pInicio;
		Elemento<TIPO>* pAux2 = nullptr;
		for (int i = 0; i < posicao; i++) {
			pAux2 = pAux1;
			pAux1 = pAux1->getProximo();
		}
		if (pAux1 == pInicio) {
			pInicio = pAux1->getProximo();
		}
		else if (pAux1 == pUltimo) {
			pUltimo = pAux2;
			pAux2->setProximo(nullptr);
		}
		else {
			pAux2->setProximo(pAux1->getProximo());
		}
		if (pAux1->getTipo() != nullptr) {
			delete(pAux1->getTipo());
			pAux1->setTipo(nullptr);
		}
		/*
		if (pAux1 != nullptr) {
			delete(pAux1);
			pAux1 = nullptr;
		}
		*/
		tamanhoLista--;
	}

	template<class TIPO>
	TIPO* Lista<TIPO>::operator[](int posicao) {
		if (posicao >= (int)tamanhoLista || posicao < 0) {
			std::cout << "ERRO: posicao invalida!" << std::endl;
			exit(1);
		}
		Elemento<TIPO>* pAux1 = pInicio;
		for (int i = 0; i < posicao; i++) {
			pAux1 = pAux1->getProximo();
		}

		if (pAux1 == nullptr) {
			std::cout << "ERRO: posicao vazia!" << std::endl;
			exit(1);
		}

		return pAux1->getTipo();
	}
}