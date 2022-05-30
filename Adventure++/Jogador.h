#pragma once

#include "Personagem.h"

namespace Entidade {
	namespace Personagem {
			class Jogador : public Personagem
			{
			protected:
				bool pular;
				const float tamPulo;
				bool caindo;

			public:
				Jogador(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, const float tamPulo);
				~Jogador();
				void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade);

				virtual void atualizar(const float tempo) = 0;
				virtual void atualizarImagem(const float tempo) = 0;

				void podePular();
			};
	}
}

