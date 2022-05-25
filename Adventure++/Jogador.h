#pragma once

#include "Personagem.h"

namespace Entidade {
	namespace Personagem {
			class Jogador : public Personagem
			{
			protected:
				bool pular;
			public:
				Jogador(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id);
				~Jogador();
				void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade);

				//teste...
				void atualizar(const float tempo) = 0;

				//teste...
				const bool getPular() const {
					return pular;
				}
				void mudarPular() {
					pular  = ((pular) ? false : true);
				}

			};
	}
}

