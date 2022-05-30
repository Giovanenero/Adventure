#pragma once
#include "EntidadeEstatica.h"

namespace Entidade {
	class Plataforma : public EntidadeEstatica
	{
	public:
		Plataforma(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id);
		~Plataforma();
		void atualizar();
		void inicializacao();
	};
}

