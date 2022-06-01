#pragma once

#include "Personagem.h"

namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			class Jogador : public Personagem
			{
			protected:
				bool pular;
				const float tamPulo;
				bool caindo;

			public:
				Jogador(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, const float tamPulo, const int vida, const int dano);
				~Jogador();
				void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade);

				virtual void atualizar(const float tempo) = 0;
				virtual void atualizarImagem(const float tempo) = 0;

				void podePular();
			};
		} //namespace Jogador
	} // namespace Personagem
} //namespace Entidade

