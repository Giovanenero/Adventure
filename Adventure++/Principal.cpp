#include "Principal.h"

using namespace Gerenciador;

Principal::Principal(): 
	pGrafico(GerenciadorGrafico::getGerenciadorGrafico()),
	pEvento(GerenciadorEvento::getGerenciadorEvento()),
	pOriana(new Entidade::Personagem::Oriana(Matematica::CoordenadaF(200.0f, 500.0f))),
	pPascal(new Entidade::Personagem::Pascal(Matematica::CoordenadaF(600.0f, 500.0f), pOriana))
{
	Executar();
}
Principal::~Principal() {
	pGrafico = nullptr;
	pEvento = nullptr;
}

void Principal::Executar() {
	float tempo = 0.f;
	pEvento->setOriana(pOriana);
	while (pGrafico->isWindowOpen()) {
		tempo = pGrafico->atualizartempo();
		pEvento->pollEvents();
		pGrafico->limpar();

		pEvento->eventojogador(tempo);
		pPascal->atualizar(tempo);
		pPascal->renderizar();

		pGrafico->mostrar();
	}
}