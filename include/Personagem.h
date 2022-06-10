#pragma once

#include "Entidade.h"
#include "AnimacaoMovimento.h"

namespace Entidade {
	namespace Personagem {
		class Personagem: public Entidade
		{
		protected:
			bool olharEsquerda;
			bool andando;
			bool noChao;

			//combate:
			float carregarAtaque;//const
			float tempoAtaque;//const
			float carregarMorrer;//const
			float carregarTomarDano;//const

			bool atacando;
			float carregandoAtaque;
			float tempoAtacando;
			float carregandoMorrendo;
			float carregandoTomarDano;
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

			//void colisaoPlataforma(Matematica::CoordenadaF intersecao, Entidade* pEntidade);

			void atualizarTempoAtaque(const float tempo);
			void ativarAndar(bool paraEsquerda);
			void desligarAndar();
			void ativarAtacar();
			void desligarAtacar();
			const bool podeAtacar() const;
			const bool podeMorrer() const;
			void podeTomarDano(int dano);
			const int valorDano() const;
			const bool podeRemover() const;
			void carregaTomarDano(const float tempo);
			void renderizar();

			virtual void atualizar(const float tempo) = 0;
			virtual void atualizarImagem(const float tempo) = 0;
		};
	}
}

