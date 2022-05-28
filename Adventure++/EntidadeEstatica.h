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
			//teste...
			pAnimacaoEstatica->novaAnimacao("textura/Fundo/gramaFloresta.png", Ids::Ids::plataforma, Matematica::CoordenadaF(1.0f, 1.0f));
		}
		void atualizar() {
			pAnimacaoEstatica->atualizar(Ids::Ids::plataforma, posicao, tamanho);
			pAnimacaoEstatica->renderizar();
		}
	};
}

