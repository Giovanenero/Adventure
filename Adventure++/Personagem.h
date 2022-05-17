#pragma once

#include "EntidadeMovimento.h"

namespace Entidade {
	namespace Personagem {
		class Personagem: public EntidadeMovimento
		{
		private:
			int vida;
		public:
			Personagem(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id);
			~Personagem();
			void setVida(int vida);
			int getVida() const;
			void tomarDano(const int dano);
			void colisaoPlataforma(Matematica::CoordenadaF intersecao, Entidade* pEntidade);
		};
	}
}

