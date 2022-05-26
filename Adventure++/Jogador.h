#pragma once

#include "Personagem.h"

namespace Entidade {
	namespace Personagem {
			class Jogador : public Personagem
			{
			protected:
				bool pulando;
				const float tamPulo;
			public:
				Jogador(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, const float tamPulo);
				~Jogador();
				void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade);

				//teste...
				void atualizar(const float tempo) = 0;

				//teste...
				const bool getPular() const {
					return pulando;
				}
				void mudarPular() {
					pulando  = ((pulando) ? false : true);
				}
				void pular() {
					if (pulando) {
						velocidade.y = -sqrt(2.0f * GRAVIDADE * tamPulo);
						pulando = false;
					}
				}

			};
	}
}

