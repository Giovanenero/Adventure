#include "Animacao.h"
#include "LinhaAnimacao.h"

namespace ElementoGrafico {

	Gerenciador::GerenciadorGrafico* Animacao::pGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();

	Animacao::Animacao():
		corpo(), 
		ID(Ids::Ids::vazio) { }

	Animacao::~Animacao() { 
		if (pGrafico) {
			delete(pGrafico);
			pGrafico = nullptr;
		}
	}

	Gerenciador::GerenciadorGrafico* Animacao::getGerenciadorGrafico() { return pGrafico; }

	void Animacao::renderizar() {
		pGrafico->renderizacao(&corpo);
	}
	void Animacao::setPosicao(Matematica::CoordenadaF pos) {
		corpo.setPosition(sf::Vector2f(pos.x, pos.y));
	}
}