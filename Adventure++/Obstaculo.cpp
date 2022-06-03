#include "Obstaculo.h"

namespace Entidade {
	namespace Obstaculo {
		Obstaculo::Obstaculo(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id) :
			Entidade(pos, tam, id),
			pAnimacaoEstatica(new ElementoGrafico::AnimacaoEstatica()) { }

		Obstaculo::~Obstaculo() {
			/*
			if (pAnimacaoEstatica) {
				pAnimacaoEstatica = nullptr;
			}
			*/
		}

		void Obstaculo::renderizar() {
			pAnimacaoEstatica->renderizar();
		}
	} //namespace Obstaculo
} //namespace Entidade