#pragma once

#include "Lista.h"
#include "Entidade.h"

namespace Lista {
	class ListaEntidade
	{
	private:
		Lista<Entidade::Entidade> objListaEntidade;
	public:
		ListaEntidade();
		~ListaEntidade();
		void adicionarEntidade(Entidade::Entidade* pEntidade);
		void removerEntidade(Entidade::Entidade* pEntidade);
		void removerEntidade(unsigned int posicao);
		unsigned int getTamanho();
		Entidade::Entidade* operator[](int posicao);
	};
}
