#pragma once

#include "Entidade.h"
#include "AnimacaoMovimento.h"

namespace Entidade {

	class EntidadeMovimento: public Entidade
	{
	protected:
		static ElementoGrafico::AnimacaoMovimento* pAnimacaoMovimento;
	public:
		EntidadeMovimento(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id);
		~EntidadeMovimento();

		void renderizar();
		virtual void atualizar(const float tempo) = 0;
		virtual void atualizarImagem(const float tempo) = 0;
	};
}

