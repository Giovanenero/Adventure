#pragma once

#include "Projetil.h"
#include "ListaEntidade.h"

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			class Atirador
			{
			protected:
				bool jaAtirou;
				Lista::ListaEntidade* ListaEntidadeMovimento;
				//teste
				const float tempoExplosao = 10.f;
				float carregarTempoExplosao = 0.f;
			public:
				Atirador(Lista::ListaEntidade* ListaEntidadeMovimento);
				~Atirador();
				void criarProjetil(Matematica::CoordenadaF posicao, const bool esquerda, const int dano);
			};
		}
	}
}

