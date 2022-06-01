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
				Projetil* pProjetil;
				Lista::ListaEntidade* ListaEntidadeMovimento;
			public:
				Atirador(Lista::ListaEntidade* ListaEntidadeMovimento);
				~Atirador();
			};
		}
	}
}

