#pragma once

#include "AnimacaoEstatica.h"
#include "Entidade.h"

namespace Entidade {
	class EntidadeEstatica: public Entidade
	{
	protected:
		static ElementoGrafico::AnimacaoEstatica* pAnimacaoEstatica;
	public:
		EntidadeEstatica(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id);
		~EntidadeEstatica();

		void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
			//terminar...
		}
		void atualizar(const float tempo) {
			//...????
		}

		void renderizar();
		virtual void inicializacao() = 0;
		virtual void atualizar() = 0;
	};
}

