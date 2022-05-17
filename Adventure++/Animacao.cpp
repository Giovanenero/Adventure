#include "Animacao.h"
#include "LinhaAnimacao.h"

namespace ElementoGrafico {

	Gerenciador::GerenciadorGrafico* Animacao::pGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();

	Animacao::Animacao():
		corpo(), ID(Ids::Ids::vazio) { }

	Animacao::~Animacao() { }

	Gerenciador::GerenciadorGrafico* Animacao::getGerenciadorGrafico() { return pGrafico; }

	void Animacao::renderizar() {
		pGrafico->renderizacao(&corpo);
	}
	void Animacao::novaAnimacao(){ }
	void Animacao::atualizar(){ }
}