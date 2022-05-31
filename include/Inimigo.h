#pragma once
#include "Personagem.h"
#include "Oriana.h"


#include <time.h>

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			class Inimigo : public Personagem
			{
			protected:
				Jogador::Oriana* pOriana;
				const Matematica::CoordenadaF distanciaJogador;
				unsigned int contAleatorio;
				short aleatorio;
			public:
				Inimigo(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, Jogador::Oriana* pOriana, Matematica::CoordenadaF distanciaJogador, const int vida, const int dano);
				~Inimigo();

				void setOriana(Jogador::Oriana* pOriana);
				Jogador::Oriana* getOriana();

				Matematica::CoordenadaF getDistanciaJogador();
				void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade);

				void atualizar(const float tempo);
				virtual void atualizarImagem(const float tempo) = 0;

				virtual const float getVelocidadeEspecifica() const = 0;
				virtual void executar() = 0;
			};
		} //namespace Inimigo
	} //namespace Personagem
} //namespace Entidade

