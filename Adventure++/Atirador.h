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
				float carregarTempoExplosao = 0.f;
			public:
				Atirador(Lista::ListaEntidade* ListaEntidadeMovimento);
				~Atirador();
				void criarProjetil(Matematica::CoordenadaF posicao, const bool esquerda, const int dano);
			};
		}
	}
}

