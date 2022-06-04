#pragma once

#include "Coordenada.h"
#include "Jogador.h"

#define TEMPO_ATAQUE_ORIANA 0.4f
#define TEMPO_DANO_ORIANA 0.6f
#define TEMPO_MORRE_ORIANA 0.6f


namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			class Oriana : public Jogador
			{
			private:
				const bool EhJogador1;
			public:
				Oriana(Matematica::CoordenadaF posInicio);
				~Oriana();
				void inicializacao();
				void atualizarImagem(const float tempo);
			};
		}
	}
}

