#include "EntidadeMovimento.h"

namespace Entidade {

	ElementoGrafico::AnimacaoMovimento* EntidadeMovimento::pAnimacaoMovimento = new ElementoGrafico::AnimacaoMovimento();

	EntidadeMovimento::EntidadeMovimento(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id):
		Entidade(pos, tam, id) { }

	EntidadeMovimento::~EntidadeMovimento() {
		if (pAnimacaoMovimento) {
			pAnimacaoMovimento = nullptr;
		}
	}

	void EntidadeMovimento::renderizar() {
		pAnimacaoMovimento->renderizar();
	}
}