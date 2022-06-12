#include "Obstaculo.h"

#include "Caixa.h"

namespace Entidade {
	namespace Obstaculo {
		Obstaculo::Obstaculo(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id) :
			Entidade(pos, tam, id),
			pAnimacaoEstatica(new ElementoGrafico::AnimacaoEstatica()) { }

		Obstaculo::~Obstaculo() {
			pAnimacaoEstatica = nullptr;
		}

		void Obstaculo::renderizar() {
			pAnimacaoEstatica->renderizar();
		}
		void Obstaculo::colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
			if (pEntidade->getID() == Ids::Ids::plataforma ||
				(getID() == Ids::Ids::andaime && pEntidade->getID() == Ids::Ids::andaime) ||
				(getID() == Ids::Ids::andaime && pEntidade->getID() == Ids::Ids::ponte) ||
				(getID() == Ids::Ids::andaime && pEntidade->getID() == Ids::Ids::pedra) ||
				(getID() == Ids::Ids::ponte && pEntidade->getID() == Ids::Ids::andaime) ||
				(getID() == Ids::Ids::ponte && pEntidade->getID() == Ids::Ids::pedra) ||
				(getID() == Ids::Ids::ponte && pEntidade->getID() == Ids::Ids::caixa) ||
				(getID() == Ids::Ids::ponte && pEntidade->getID() == Ids::Ids::ponte) ||
				(getID() == Ids::Ids::caixa && pEntidade->getID() == Ids::Ids::caixa) ||
				(getID() == Ids::Ids::caixa && pEntidade->getID() == Ids::Ids::ponte) ||
				//(getID() == Ids::Ids::pedra && pEntidade->getID() == Ids::Ids::caixa) ||
				(getID() == Ids::Ids::pedra && pEntidade->getID() == Ids::Ids::ponte) ||
				(getID() == Ids::Ids::espinhos && pEntidade->getID() == Ids::Ids::caixa) ||
				(getID() == Ids::Ids::espinhos && pEntidade->getID() == Ids::Ids::ponte))
			{
				colisaoPlataforma(intersecao, pEntidade);
			}
			else if ((getID() == Ids::Ids::andaime && pEntidade->getID() == Ids::Ids::caixa) ||
				(getID() == Ids::Ids::pedra && pEntidade->getID() == Ids::Ids::caixa)) {
				Caixa* pCaixa = static_cast<Caixa*>(pEntidade);
				pCaixa->setEmpurrar(false);
			}
		}
		void Obstaculo::atualizar(const float tempo) {
			if (getID() != Ids::Ids::plataforma) {
				velocidade.y += GRAVIDADE * tempo;
				posicao.y += velocidade.y * tempo;
			}
			atualizar();
		}
	} //namespace Obstaculo
} //namespace Entidade