#pragma once

#include "AnimacaoEstatica.h"
#include "Entidade.h"

namespace Entidade {
	class EntidadeEstatica: public Entidade
	{
	protected:
		static ElementoGrafico::AnimacaoEstatica* pAnimacaoEstatica;
	public:
		EntidadeEstatica(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id);
		~EntidadeEstatica();
		void renderizar();

		void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
			//terminar...
		}
		void atualizar(const float tempo) {
			//...????
		}
		void inicializacao(){
			pAnimacaoEstatica->novaAnimacao("textura/Fundo/gramaFloresta.png", Ids::Ids::plataforma);
		}
		void atualizar(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam) {
			pAnimacaoEstatica->atualizar(Ids::Ids::plataforma, pos, tam);
			pAnimacaoEstatica->renderizar();
		}
	};
}

