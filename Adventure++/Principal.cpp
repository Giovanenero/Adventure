#include "Principal.h"

using namespace Gerenciador;

Principal::Principal(): 
	pGrafico(GerenciadorGrafico::getGerenciadorGrafico()),
	pEvento(GerenciadorEvento::getGerenciadorEvento()),
	jogador1(Matematica::CoordenadaF(200.0f, 500.0f))
{
	Executar();
}
Principal::~Principal() {

}

void Principal::Executar() {
	float tempo = 0.f;
	while (pGrafico->isWindowOpen()) {
		tempo = pGrafico->atualizartempo();
		pEvento->pollEvents();
		pGrafico->limpar();


		jogador1.atualizar(tempo);
		jogador1.renderizar();

		pGrafico->mostrar();
	}
}