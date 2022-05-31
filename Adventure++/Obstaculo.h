#pragma once

#include "AnimacaoEstatica.h"
#include "Entidade.h"

namespace Entidade {
	namespace Obstaculo {
		class Obstaculo : public Entidade
		{
		protected:
			ElementoGrafico::AnimacaoEstatica* pAnimacaoEstatica;
		public:
			Obstaculo(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id);
			~Obstaculo();

			void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
				//terminar...
			}

			void renderizar();
			virtual void inicializacao() = 0;
			virtual void atualizar() = 0;
			virtual void executar() = 0;
		};
	} //namespace Obstaculo
} //namespace Entidade

