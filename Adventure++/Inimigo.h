#pragma once
#include "Personagem.h"
#include "Oriana.h"


#include <time.h>

namespace Entidade {
	namespace Personagem {
			class Inimigo : public Personagem
			{
			protected:
				Oriana* pOriana;
				const float distanciaJogador;
				unsigned int contAleatorio;
				short aleatorio;
			public:
				Inimigo(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, Oriana* pOriana, const float distanciaJogador);
				~Inimigo();

				void setOriana(Oriana* pOriana);
				Oriana* getOriana();

				Matematica::CoordenadaF getDistanciaJogador();
				void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade);

				void atualizar(const float tempo);
				virtual void atualizarImagem(const float tempo) = 0;

				virtual const float getVelocidadeEspecifica() const = 0;
			};

	}
}

