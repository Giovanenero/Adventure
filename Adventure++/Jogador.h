#pragma once

#include "Personagem.h"
#include "Espinhos.h"

//teste...
//#include "Fase.h"
//#include "Noturno.h"

namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			class Jogador : public Personagem
			{
			protected:
				bool caindo;
				short mudarAtaque;
				int pontuacao;
			public:
				Jogador(Matematica::CoordenadaF pos, Ids::Ids id);
				~Jogador();

				void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade);
				void podePular();
				void setPontuacao(int pontuacao);
				const int getPontuacao() const;

				void atualizar(const float tempo);
				virtual void atualizarImagem(const float tempo) = 0;
			};
		} //namespace Jogador
	} // namespace Personagem
} //namespace Entidade

