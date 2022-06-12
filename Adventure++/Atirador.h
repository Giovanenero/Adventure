#pragma once

#include "Projetil.h"
#include "ListaEntidade.h"

#define TEMPO_PROJETIL_EXPLOSAO 10.0f

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			class Atirador
			{
			protected:
				bool jaAtirou;
				Lista::ListaEntidade* ListaEntidadeMovimento;
				float carregarTempoExplosao;
			public:
				Atirador(Lista::ListaEntidade* ListaEntidadeMovimento);
				~Atirador();
				void criarProjetil(Matematica::CoordenadaF posicao, const bool esquerda, const int dano);
				Jogador::Jogador* jogadorMaisProximo(Jogador::Oriana* pOriana = nullptr, Jogador::Hideo* pHideo = nullptr, Matematica::CoordenadaF posInimigo = Matematica::CoordenadaF(0.0f, 0.0f));
			};
		}
	}
}

