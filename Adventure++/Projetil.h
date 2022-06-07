#pragma once

#include "Entidade.h"
#include "Goblin.h"
#include "Pedra.h"

namespace Entidade {
	class Projetil: public Entidade
	{
	private:
		ElementoGrafico::AnimacaoMovimento* pAnimacaoMovimento;
		const int dano;
		bool explodir;
		const bool paraEsquerda;
		float carregarTempoExplosao;
		const float posInicio_y;
		bool caindo = false;
	public:
		Projetil(Matematica::CoordenadaF posInicio, const bool paraEsquerda, const int dano);
		~Projetil();
		void renderizar();
		void inicializacao();
		void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade);
		void atualizar(const float tempo);
		void atualizarImagem(const float tempo);
		const bool podeRemover() const;
		Matematica::CoordenadaF getVelocidadeProjetil();
	};
}

