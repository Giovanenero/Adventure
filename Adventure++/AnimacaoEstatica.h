#pragma once

#include "Animacao.h"
#include "LinhaAnimacaoEstatica.h"

namespace ElementoGrafico {

	class LinhaAnimacaoEstatica;

	class AnimacaoEstatica: public Animacao
	{
	private:
		std::map<Ids::Ids, LinhaAnimacaoEstatica*> mapAnimacaoEstatica;
	public:
		AnimacaoEstatica();
		~AnimacaoEstatica();

		void novaAnimacao(const char* caminhoTextura, Ids::Ids id);
		void atualizar(Ids::Ids id);
	};
}

