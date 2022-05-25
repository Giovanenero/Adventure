#pragma once
#include "Personagem.h"
#include "Oriana.h"

namespace Entidade {
	namespace Personagem {
			class Inimigo : public Personagem
			{
			protected:
				float distanciaJogador;
				Oriana* pOriana;
			public:
				Inimigo(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, Oriana* pOriana, const int vida, Matematica::CoordenadaF vel);
				~Inimigo();
				void setOriana(Oriana* pOriana);
				Oriana* getOriana();
				Matematica::CoordenadaF getDistanciaJogador();
				void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade);
			};

	}
}

