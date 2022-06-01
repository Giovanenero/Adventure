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

			const bool podeRemover() const {
				//arrumar...
				return false;
			}
			void atualizar(const float tempo) {
				//arrumar
			}
			void atualizarImagem(const float tempo) {
				//arrumar..
			}
		};
	} //namespace Obstaculo
} //namespace Entidade

