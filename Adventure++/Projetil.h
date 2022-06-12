#pragma once

#include "Entidade.h"
#include "Goblin.h"
#include "Pedra.h"

namespace Entidade {
	class Projetil: public Entidade
	{
	private:
		const int dano;
		bool explodir;
		const bool paraEsquerda;
		float carregarTempoExplosao;
		const float posInicio_y;
		bool caindo;
		ElementoGrafico::AnimacaoMovimento* pAnimacaoMovimento;
	public:
		Projetil(Matematica::CoordenadaF posInicio, const bool paraEsquerda, const int dano);
		~Projetil();
		void inicializacao();
		void renderizar();
		void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade);
		void atualizar(const float tempo);
		void atualizarImagem(const float tempo);
		const bool podeRemover() const;
		const Matematica::CoordenadaF getVelocidadeProjetil();
	};
}

