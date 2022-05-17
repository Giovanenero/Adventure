#include "EntidadeMovimento.h"

namespace Entidade {

	ElementoGrafico::AnimacaoMovimento* EntidadeMovimento::pAnimacaoMovimento = new ElementoGrafico::AnimacaoMovimento();

	EntidadeMovimento::EntidadeMovimento(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id):
		Entidade(pos, tam, id), tempo(0.f), olharEsquerda(false), velocidade(0.f, 0.f),
		morrer(false)
	{ }

	EntidadeMovimento::~EntidadeMovimento() {
		if (pAnimacaoMovimento) {
			pAnimacaoMovimento = nullptr;
		}
	}

	void EntidadeMovimento::renderizar() {
		pAnimacaoMovimento->renderizar();
	}
	void EntidadeMovimento::setMorrer(bool morrer) { this->morrer = morrer; }
	bool EntidadeMovimento::getMorrer() const { return morrer; }
	void EntidadeMovimento::setVelodade(Matematica::CoordenadaF velocidade) { this->velocidade = velocidade; }
	Matematica::CoordenadaF EntidadeMovimento::getVelocidade() { return velocidade; }
}