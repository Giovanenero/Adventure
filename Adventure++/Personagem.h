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
			bool morrer;
			bool olharEsquerda;
			bool atacando;
			bool andando;
			bool noChao;

			//ainda em teste...
			float carregandoAtaque = 0.f;
			float tempoAtacando = 0.f;
			const float carregarAtaque = 1.0f;
			const float tempoAtaque = 1.0f;

			//ainda em teste...
			const float carregarMorrer = 0.6f;
			float carregandoMorrendo = 0.0f;
			int vida = 200;
			//int dano = 35;

			const float carregarTomarDano = 0.6f;
			float carregandoTomarDano = 0.0f;
			bool dano = false;


			//teste
			//float carregandoDano = 0.f;
			//float tempoTomandoDano = 0.f;
			//const float carregarDano = 1.0f;
			//const float tempoDano = 1.0f;

			ElementoGrafico::AnimacaoMovimento* pAnimacaoMovimento;
		public:
			Personagem(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id);
			~Personagem();

			void setVida(int vida);
			int getVida() const;

			void setMorrer(bool morrer);
			bool getMorrer() const;

			void setVelocidade(Matematica::CoordenadaF velocidade);
			Matematica::CoordenadaF getVelocidade();

			void colisaoPlataforma(Matematica::CoordenadaF intersecao, Entidade* pEntidade);

			void atualizar(const float tempo) = 0;
			void atualizarTempoAtaque(const float tempo);

			void ativarAndar(bool paraEsquerda);
			void ativarAtacar();
			void desligarAndar();
			virtual void atualizarImagem(const float tempo) = 0;
			void renderizar();
			virtual void executar() = 0;

			//teste...
			const bool podeAtacar() {
				return (tempoAtacando > carregarAtaque) ? true : false;
			}
			const bool podeMorrer() const {
				return (carregandoMorrendo > carregarMorrer) ? true : false;
			}
			const bool podeTomarDano() const {
				return (carregandoTomarDano > carregarTomarDano) ? true : false;
			}
			void tomarDano(int dano) {
				vida = vida - dano;
				if (vida <= 0) {
					morrer = true;
				}
				else {
					this->dano = true;
				}
			}

		};
	}
}

