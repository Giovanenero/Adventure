#pragma once

#include "Entidade.h"
#include "AnimacaoMovimento.h"

namespace Entidade {

	class EntidadeMovimento: public Entidade
	{
	protected:
		Matematica::CoordenadaF velocidade;
		bool olharEsquerda;
		float tempo;
		bool morrer;
		static ElementoGrafico::AnimacaoMovimento* pAnimacaoMovimento;
	public:
		EntidadeMovimento(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id);
		~EntidadeMovimento();
		void setMorrer(bool morrer);
		bool getMorrer() const;
		void setVelodade(Matematica::CoordenadaF velocidade);
		Matematica::CoordenadaF getVelocidade();
		void renderizar();
		virtual void atualizar(float tempo) = 0;
	};
}

