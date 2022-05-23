#include "Principal.h"

using namespace Gerenciador;

Principal::Principal(): 
	pGrafico(GerenciadorGrafico::getGerenciadorGrafico()),
	pEvento(GerenciadorEvento::getGerenciadorEvento()),
	jogador1(new Entidade::Personagem::Oriana(Matematica::CoordenadaF(200.0f, 500.0f))),
	dog(new Entidade::Personagem::Inimigo(Matematica::CoordenadaF(600.0f, 500.0f), Matematica::CoordenadaF(50.0f, 80.0f), Ids::Ids::dog))
{
	Executar();
}
Principal::~Principal() {
	pGrafico = nullptr;
	pEvento = nullptr;
}

void Principal::Executar() {
	float tempo = 0.f;
	while (pGrafico->isWindowOpen()) {
		tempo = pGrafico->atualizartempo();
		pEvento->pollEvents();
		pGrafico->limpar();

		dog->atualizar(tempo);
		dog->renderizar();
		jogador1->atualizar(tempo);
		jogador1->renderizar();

		pGrafico->mostrar();
	}
}