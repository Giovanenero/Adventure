#pragma once

//arrumar TEMPOATAQUE, pois deve ser inicializado nas filhas
#define TEMPOATAQUE 0.1f

#include "EntidadeMovimento.h"

namespace Entidade {
	namespace Personagem {
		class Personagem: public EntidadeMovimento
		{
		protected:
			bool morrer;
			bool olharEsquerda;
			const float tempoAtaque;
			float tempoAtacando;
			float carregarAtaque;
			bool atacando;
		private:
			Matematica::CoordenadaF velocidade;
			int vida;
		public:
			Personagem(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, const int vida, Matematica::CoordenadaF vel);
			~Personagem();
			void setVida(int vida);
			int getVida() const;
			void setMorrer(bool morrer);
			bool getMorrer() const;
			void setVelocidade(Matematica::CoordenadaF velocidade);
			Matematica::CoordenadaF getVelocidade();
			void tomarDano(const int dano);
			void colisaoPlataforma(Matematica::CoordenadaF intersecao, Entidade* pEntidade);
			const bool podeAtacar() const;
			void ativarAtacando();
			const bool getAtacando() const;
			void atualizaTempoAtacando(const float tempo);
		};
	}
}

