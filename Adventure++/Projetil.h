#pragma once

#include "Entidade.h"
#include "Goblin.h"

namespace Entidade {
	class Projetil: public Entidade
	{
	private:
		ElementoGrafico::AnimacaoMovimento* pAnimacaoMovimento;
		const int dano;
		bool explodir;
		const bool paraEsquerda;
		//teste...
		float carregarTempoExplosao;
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

