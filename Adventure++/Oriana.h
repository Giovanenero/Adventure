#pragma once

#include "Coordenada.h"
#include "Personagem.h"

#define TAMX 50
#define TAMY 80

namespace Entidade {
	namespace Personagem {
		class Oriana: public Personagem
		{
		private:
			const bool EhJogador1;
		public:
			Oriana(Matematica::CoordenadaF pos);
			~Oriana();
			void inicializacao();
			void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade);
			void atualizar(float tempo);
		};
	}
}

