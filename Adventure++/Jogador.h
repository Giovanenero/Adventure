#pragma once

#include "Personagem.h"

namespace Entidade {
	namespace Personagem {
			class Jogador : public Personagem
			{
			public:
				Jogador(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, const int vida, Matematica::CoordenadaF vel);
				~Jogador();
				void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade);
				void andar(const bool paraEsquerda, const float tempo);
				void atacar(const float tempo);
				void parar(const float tempo);
			};
	}
}

