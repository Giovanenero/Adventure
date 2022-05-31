#pragma once

#include "Entidade.h"
#include "AnimacaoMovimento.h"

#define GRAVIDADE 998.0f

namespace Entidade {
	namespace Personagem {
		class Personagem: public Entidade
		{
		protected:
			Matematica::CoordenadaF velocidade;
			bool olharEsquerda;
			bool andando;
			bool noChao;

			//combate:
			bool atacando;
			float carregandoAtaque = 0.f;
			float tempoAtacando = 0.f;
			const float carregarAtaque = 0.4f;
			const float tempoAtaque = 0.4f;
			const float carregarMorrer = 0.6f;
			float carregandoMorrendo = 0.0f;
			const float carregarTomarDano = 0.6f;
			float carregandoTomarDano = 0.0f;
			bool tomarDano;
			int vida;
			int dano;
			bool morrer;

			ElementoGrafico::AnimacaoMovimento* pAnimacaoMovimento;
		public:
			Personagem(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, const int vida, const int dano);
			~Personagem();

			void setVida(int vida);
			int getVida() const;

			void setMorrer(bool morrer);
			bool getMorrer() const;

			void setVelocidade(Matematica::CoordenadaF velocidade);
			Matematica::CoordenadaF getVelocidade();

			void colisaoPlataforma(Matematica::CoordenadaF intersecao, Entidade* pEntidade);

			virtual void atualizar(const float tempo) = 0;
			void atualizarTempoAtaque(const float tempo);
			void ativarAndar(bool paraEsquerda);
			void ativarAtacar();
			void desligarAndar();
			virtual void atualizarImagem(const float tempo) = 0;
			void renderizar();
			virtual void executar() = 0;
			const bool podeAtacar() const;
			const bool podeMorrer() const;
			void podeTomarDano(int dano);
			const int valorDano() const;

		};
	}
}

