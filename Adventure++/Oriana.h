#pragma once

#include "Coordenada.h"
#include "Jogador.h"

#define TAMX 50
#define TAMY 80

namespace Entidade {
	namespace Personagem {
		class Oriana : public Jogador
		{
		private:
			const bool EhJogador1;
		public:
			Oriana(Matematica::CoordenadaF pos);
			~Oriana();
			void inicializacao();
		};
	}
}

