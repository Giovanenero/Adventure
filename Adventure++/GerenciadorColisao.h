#pragma once

#include "ListaEntidade.h"

namespace Gerenciador {
	class GerenciadorColisao
	{
	private:
		Lista::ListaEntidade* ListaEntidadeEstatica;
		Lista::ListaEntidade* ListaEntidadeMovimento;
	public:
		GerenciadorColisao(Lista::ListaEntidade* LEstatica, Lista::ListaEntidade* LMovimento);
		~GerenciadorColisao();
		void Colisao();
	};
}

