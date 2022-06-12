#include "ListaEntidade.h"

namespace Lista {
	ListaEntidade::ListaEntidade():
		objListaEntidade() { }

	ListaEntidade::~ListaEntidade() { }

	void ListaEntidade::adicionarEntidade(Entidade::Entidade* pEntidade) {
		objListaEntidade.adicionar(pEntidade);
	}

	void ListaEntidade::removerEntidade(Entidade::Entidade* pEntidade) {
		objListaEntidade.remover(pEntidade);
	}

	void ListaEntidade::removerEntidade(unsigned int posicao) {
		objListaEntidade.remover((int)posicao);
	}

	unsigned int ListaEntidade::getTamanho() {
		return objListaEntidade.getTamanho();
	}

	Entidade::Entidade* ListaEntidade::operator[](int posicao) {
		return objListaEntidade.operator[](posicao);
	}
}