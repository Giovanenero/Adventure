#include "EntidadeEstatica.h"

namespace Entidade {

	ElementoGrafico::AnimacaoEstatica* EntidadeEstatica::pAnimacaoEstatica = new ElementoGrafico::AnimacaoEstatica();

	EntidadeEstatica::EntidadeEstatica(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id):
		Entidade(pos, tam, id) { }

	EntidadeEstatica::~EntidadeEstatica() {
		if (pAnimacaoEstatica) {
			pAnimacaoEstatica = nullptr;
		}
	}

	void EntidadeEstatica::renderizar() {
		pAnimacaoEstatica->renderizar();
	}
}