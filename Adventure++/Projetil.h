#pragma once

#include "Entidade.h"
#include "Goblin.h"

#define TAMANHO_PROJETIL_X 10.0f
#define TAMANHO_PROJETIL_Y 10.0f
#define VELOCIDADE_PROJETIL_X 0.5f
#define TEMPO_EXPLODIR 1.0f

namespace Entidade {
	class Projetil: public Entidade
	{
	private:
		ElementoGrafico::AnimacaoMovimento* pAnimacaoMovimento;
		const int dano;
		bool explodir;
		const bool paraEsquerda;
	public:
		Projetil(Matematica::CoordenadaF posInicio, const bool paraEsquerda, const int dano);
		~Projetil();
		void renderizar();
		void inicializacao();
		void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade);
		void atualizar(const float tempo);
		void atualizarImagem(const float tempo);
		const bool podeRemover() const;
		void setExplodir(const bool explodir) {
			this->explodir = explodir;
		}
		const bool getExplodir() const {
			return explodir;
		}
	};
}

