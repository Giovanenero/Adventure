#pragma once

#include "Coordenada.h"
#include "Jogador.h"

namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			class Oriana : public Jogador
			{
			public:
				Oriana(Matematica::CoordenadaF posInicio);
				~Oriana();
				void inicializacao();
				void atualizarImagem(const float tempo);
			};
		}
	}
}

