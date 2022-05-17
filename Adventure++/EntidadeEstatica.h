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
		void renderizar();
		void inicializacao(){ /* terminar... */ }
	};
}

