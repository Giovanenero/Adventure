#include "ListaEntidade.h"

namespace Lista {
	ListaEntidade::ListaEntidade():
		objListaEntidade() { }

	ListaEntidade::~ListaEntidade() { 
		objListaEntidade.limpar(); 
	}

	void ListaEntidade::adicionarEntidade(Entidade::Entidade* pEntidade) {
		objListaEntidade.adicionar(pEntidade);
	}
	Entidade::Entidade* ListaEntidade::removerEntidade(Entidade::Entidade* pEntidade) {
		return objListaEntidade.remover(pEntidade);
	}
	Entidade::Entidade* ListaEntidade::removerEntidade(unsigned int posicao) {
		return objListaEntidade.remover((int)posicao);
	}
	unsigned int ListaEntidade::getTamanho() {
		return objListaEntidade.getTamanho();
	}
	Entidade::Entidade* ListaEntidade::operator[](int posicao) {
		return objListaEntidade.operator[](posicao);
	}
}