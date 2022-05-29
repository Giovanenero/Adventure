#pragma once

#include "Personagem.h"

namespace Entidade {
	namespace Personagem {
			class Jogador : public Personagem
			{
			protected:
				bool pulando;
				const float tamPulo;
				
				//teste...
				float pulo = 0.f;
			public:
				Jogador(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, const float tamPulo);
				~Jogador();
				void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade);

				//teste...
				void atualizar(const float tempo) = 0;

				void pular();

				void verificaPulo(const float tempo);

			};
	}
}

