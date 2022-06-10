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
				if (pEntidade->getID() == Ids::Ids::plataforma || 
					(getID() == Ids::Ids::andaime && pEntidade->getID() == Ids::Ids::andaime) ||
					(getID() == Ids::Ids::andaime && pEntidade->getID() == Ids::Ids::ponte) ||
					(getID() == Ids::Ids::ponte && pEntidade->getID() == Ids::Ids::andaime) ||
					(getID() == Ids::Ids::caixa && pEntidade->getID() == Ids::Ids::ponte) ||
					(getID() == Ids::Ids::ponte && pEntidade->getID() == Ids::Ids::caixa) ||
					(getID() == Ids::Ids::ponte && pEntidade->getID() == Ids::Ids::ponte) ||
					(getID() == Ids::Ids::caixa && pEntidade->getID() == Ids::Ids::pedra) || 
					(getID() == Ids::Ids::caixa && pEntidade->getID() == Ids::Ids::caixa) || 
					(getID() == Ids::Ids::pedra && pEntidade->getID() == Ids::Ids::caixa) ||
					(getID() == Ids::Ids::espinhos && pEntidade->getID() == Ids::Ids::caixa) ||
					(getID() == Ids::Ids::espinhos && pEntidade->getID() == Ids::Ids::ponte) )
				{
					colisaoPlataforma(intersecao, pEntidade);
					//std::cout << posicao.y << " " << pEntidade->getPosicao().y << std::endl;
				}
			}

			void renderizar();
			virtual void inicializacao() = 0;
			virtual void atualizar() = 0;

			const bool podeRemover() const { return false; }

			void atualizar(const float tempo) {
				if (getID() != Ids::Ids::plataforma) {
					velocidade.y += GRAVIDADE * tempo;
					posicao.y += velocidade.y * tempo;
				}
				atualizar();
			}
			void atualizarImagem(const float tempo) { }
		};
	} //namespace Obstaculo
} //namespace Entidade

