#pragma once

#include "Personagem.h"
#include "Espinhos.h"

namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			class Jogador : public Personagem
			{
			protected:
				bool pular;
				bool caindo;
				short mudarAtaque;
				int pontuacao;
			public:
				Jogador(Matematica::CoordenadaF pos, Ids::Ids id);
				~Jogador();
				void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade);

				void atualizar(const float tempo);
				virtual void atualizarImagem(const float tempo) = 0;

				void podePular();
				void setPontuacao(int pontuacao);
				const int getPontuacao() const;
			};
		} //namespace Jogador
	} // namespace Personagem
} //namespace Entidade

