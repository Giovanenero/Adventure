#pragma once
#include "Personagem.h"
#include "Oriana.h"

namespace Entidade {
	namespace Personagem {
			class Inimigo : public Personagem
			{
			protected:
				float distanciaJogador;
			private:
				Oriana* pOriana;
			public:
				Inimigo(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id);
				~Inimigo();
				void setOriana(Oriana* pOriana);
				Matematica::CoordenadaF getDistanciaJogador();
				void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade);
				void atualizar(float tempo);
				void inicializacao();
				//terminar...
			};

	}
}

