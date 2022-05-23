#pragma once

#include "Personagem.h"

namespace Entidade {
	namespace Personagem {
			class Jogador : public Personagem
			{
			protected:
				//terminar...
			private:
				//terminar...
			public:
				Jogador(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id);
				~Jogador();
				void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade);
				void atualizar(float tempo);
			};
	}
}

